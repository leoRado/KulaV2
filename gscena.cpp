#include "gscena.h"
#include <QGraphicsSceneEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>

/*
#include <QtCore>
#include <QtXml/QDomDocument>
*/

#include <QFile>
#include <QString>
#include <QMap>

//Blokovi
#include "bstart.h"
#include "bstop.h"
#include "bulaz.h"
#include "bizlaz.h"
#include "bobrada.h"
#include "buslov.h"
#include "bfor.h"
#include "bcvor.h"
#include "bwhile.h"
#include "bdowhile.h"
#include "sobicna.h"
#include "aplikacija.h"

#include <QMessageBox>
#include <QApplication>
#include <iostream>
using namespace std;

GScena::GScena(QObject *parent) : QGraphicsScene(parent)
{
    this->_blokHolder = NULL;
    this->stanje = "";

    this->max = 50;
    this->grafickaScena = new QGraphicsItem* [this->max];
    this->top = 0;

    this->drugiSelektovaniObjekat = NULL;
    this->prviSelektovaniObjekat = NULL;

    this->start = NULL;
}

GScena::~GScena()
{
    delete _blokHolder;
    for(int i = 0; i<this->max; i++)
        delete this->grafickaScena[i];
    delete[] this->grafickaScena;
}

void GScena::setBlok(AbstractBlok *blok)
{
    this->_blokHolder=blok;
}

void GScena::setStart()
{
    this->_blokHolder=new BStart("Start"+brojac);
}

void GScena::setStop()
{
    this->_blokHolder=new BStop("StopB"+brojac);
}

void GScena::setUlaz()
{
    this->_blokHolder = new BUlaz("Ulaz"+brojac);
}

void GScena::setIzlaz()
{
    this->_blokHolder=new BIzlaz("Izlaz" + brojac);
}

void GScena::setObrada()
{
    this->_blokHolder = NULL;
    this->_blokHolder = new BObrada("Obrada" + brojac);
}

void GScena::setUslov()
{
    this->_blokHolder=new BUslov("Uslov"+brojac);
}

void GScena::setCvor()
{
    this->_blokHolder=new BCvor("Cvor"+brojac);
}

void GScena::setFor()
{
    this->_blokHolder=new BFor("For"+brojac);
}

void GScena::setWhile()
{
    this->_blokHolder=new BWhile("While"+brojac);
}

void GScena::setDoWhile()
{
    this->_blokHolder=new BDoWhile("DoWhile" + brojac);
}

void GScena::obradiListu()
{
    /*
    foreach(QGraphicsItem* element, items())
        {
            //Osnovni podaci
            //AbstractBlok* blok = (AbstractBlok* )element;

            //QPoint _lokacija = blok->pos();
            //QString _tip = blok->getTip();
            //QString _tekst=blok->getText();
           //QString _veza ; Treba da se doda QString _imeBloka i QString veza u AbstractBlok za sada ne radi

            //Dakle za obradu liste koristi se metoda items()
        }
        */
}

QString GScena::getKod()
{
    QString _kod;  //Tu ce da bude smesten kod

    //==== Korak 1 - Pretraga za blokom Start ====
    AbstractBlok* _pocetak=NULL;
    AbstractBlok* _pom=NULL;

    foreach(QGraphicsItem* item, items())
        {
            if(item->type()!=QGraphicsLineItem::Type)
                {
                    AbstractBlok* blok = (AbstractBlok*)item;

                    if(blok->getTip().startsWith("Start"))
                    {
                           _pocetak=blok;
                    }
                }
        }

    //==== Korak 2 - Obrada ====
    //Za sada samo prolaz i nista vise

    //Ako nema Start
    if(_pocetak==NULL)
        {
            QMessageBox::warning(0, tr("Algovertor"), tr("Dijagram mora najpre da se započne blokom START!") );
            return " ";
        }

    _kod.append(_pocetak->getTip()+"\n"); //Dodamo start

    //Ako je Start povezan
    if(_pocetak->levaVeza()!=NULL)
        {
            _pom=_pocetak->levaVeza()->childBlok();
        }

    //Obrada
    while(_pom!=NULL)
        {

            if(_pom->getTip()!="Stop")
                {
                   _kod.append(_pom->getTip()+" : "+_pom->getText()+"\n"); //Da prikaze sve (Tip + Text)
                }
            else
                {
                    _kod.append(_pom->getTip()+"\n");  //Da prikaze samo tip
                    return _kod; //Stigo je do kraja
                }


            if(_pom->levaVeza()!=NULL)
                {
                    _pom=_pom->levaVeza()->childBlok();
                }
            else
                {
                    _pom=NULL;
                }
        }

    //Posto nismo dosli do bloka stop
    QMessageBox::warning(0, tr("Algovertor"), tr("Dijagram mora da se započne blokom START, a završi blokom STOP!") );
    return " ";
}

void GScena::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        AbstractBlok* X = (AbstractBlok*) this->itemAt(event->scenePos().x(), event->scenePos().y(), QTransform());
        QString tmpString = "Blok: ";
        tmpString += X->getTip();
        tmpString += "\n Parent: ";
        tmpString += X->getParent()->getTip();
        tmpString += "\n Next: ";
        tmpString += X->getNext()->getTip();
        QMessageBox::information(NULL, "Test", tmpString);
        delete X;
        return;
    }

    if(this->stanje == "Povezi")
    {
        QGraphicsItem* tmp;
        if(this->prviSelektovaniObjekat == NULL)
        {
            tmp = this->itemAt(event->scenePos().x(), event->scenePos().y(), QTransform());
            if(tmp != 0)
                this->prviSelektovaniObjekat = (AbstractBlok*)tmp;
            else
            {
                this->prviSelektovaniObjekat = NULL;
                this->drugiSelektovaniObjekat = NULL;
                this->stanje = "Move";
                return;
            }
        }
        else
        {
            tmp = this->itemAt(event->scenePos().x(), event->scenePos().y(), QTransform());
            if(tmp != 0)
                 this->drugiSelektovaniObjekat = (AbstractBlok*)tmp;
            else
            {
                this->prviSelektovaniObjekat = NULL;
                this->drugiSelektovaniObjekat = NULL;
                this->stanje = "Move";
                return;
            }


            SObicna* _strelica;

            if(this->prviSelektovaniObjekat->isParentFull())
            {
                /*if(this->prviSelektovaniObjekat->isNextFull())
                {
                    this->removeItem( this->grafickaScena[this->prviSelektovaniObjekat->getParentNumber()] );
                    this->prviSelektovaniObjekat->deleteParent();
                }*/

                _strelica = new SObicna( this->prviSelektovaniObjekat, this->drugiSelektovaniObjekat );
                this->addItem(_strelica);
                int tmpIndex = this->addToScene(_strelica);
                this->prviSelektovaniObjekat->setNextNumber(tmpIndex);
                this->drugiSelektovaniObjekat->setParentNumber(tmpIndex);

            }

            if(!this->prviSelektovaniObjekat->isParentFull())
            {
                if(this->drugiSelektovaniObjekat->isNextFull())
                {
                    this->removeItem( this->grafickaScena[this->drugiSelektovaniObjekat->getNextNumber()] );
                    this->drugiSelektovaniObjekat->deleteNext();
                }

                _strelica = new SObicna( this->drugiSelektovaniObjekat, this->prviSelektovaniObjekat) ;
                this->addItem(_strelica);
                int tmpIndex = this->addToScene(_strelica);
                this->prviSelektovaniObjekat->setParentNumber(tmpIndex);
                this->drugiSelektovaniObjekat->setNextNumber(tmpIndex);
            }

            this->prviSelektovaniObjekat = NULL;
            this->drugiSelektovaniObjekat = NULL;
            this->stanje = "Move";
            return;



            /*if(this->tmpHolder->getTip() == "Stop")
            {
                if(this->tmpHolder->isParentFull()){
                    this->removeItem( this->grafickaScena[this->tmpHolder->getParentNumber()] );
                    this->tmpHolder->setParentNumber(-1);
                    this->tmpHolder->deleteParent();
                }

                if(B->isParentFull()){
                    this->removeItem( this->grafickaScena[B->getParentNumber()] );
                    B->setParentNumber(-1);
                    B->deleteParent();
                }

                _strelica = new SObicna(B, this->tmpHolder);
                this->addItem(_strelica);
                int tmpIndex = this->addToScene(_strelica);
                this->tmpHolder->setParentNumber(tmpIndex);
                B->setNextNumber(tmpIndex);
                this->tmpHolder = NULL;
                B = NULL;
                _strelica = NULL;
                this->stanje = "Move";
                return;
            }

            if(this->tmpHolder->isParentFull() && B->isNextFull())
            {
                if(this->tmpHolder->isParentFull()){
                    this->removeItem( this->grafickaScena[this->tmpHolder->getParentNumber()] );
                    this->tmpHolder->setParentNumber(-1);
                    this->tmpHolder->deleteParent();
                }

                if(B->isNextFull()){
                    this->removeItem( this->grafickaScena[B->getNextNumber()] );
                    B->setNextNumber(-1);
                    B->deleteNext();
                }

                _strelica = new SObicna(B, this->tmpHolder);
                this->addItem(_strelica);
                int tmpIndex = this->addToScene(_strelica);
                this->tmpHolder->setParentNumber(tmpIndex);
                B->setNextNumber(tmpIndex);
                this->tmpHolder = NULL;
                B = NULL;
                _strelica = NULL;
                this->stanje = "Move";
                return;
            }

            if(this->tmpHolder->isParentFull() || this->tmpHolder->getTip() == "Start"){

                if(this->tmpHolder->isNextFull()){
                    this->removeItem( this->grafickaScena[this->tmpHolder->getNextNumber()] );
                    this->tmpHolder->setNextNumber(-1);
                    this->tmpHolder->deleteNext();
                }

                if(B->isParentFull()){
                    this->removeItem( this->grafickaScena[B->getParentNumber()] );
                    B->setParentNumber(-1);
                    B->deleteParent();
                }

                _strelica = new SObicna(this->tmpHolder, B);
                this->addItem(_strelica);
                int tmpIndex = this->addToScene(_strelica);

                this->tmpHolder->setNextNumber(tmpIndex);
                B->setParentNumber(tmpIndex);

                this->tmpHolder = NULL;
                B = NULL;
                _strelica = NULL;
                this->stanje = "Move";
                return;
            }

            if(B->isParentFull()){

                if(this->tmpHolder->isParentFull()){
                    this->removeItem( this->grafickaScena[this->tmpHolder->getParentNumber()] );
                    this->tmpHolder->setParentNumber(-1);
                    this->tmpHolder->deleteParent();
                }

                if(B->isNextFull()){
                    this->removeItem( this->grafickaScena[B->getNextNumber()] );
                    B->setNextNumber(-1);
                    B->deleteNext();
                }

                _strelica = new SObicna(B, this->tmpHolder);
                this->addItem(_strelica);
                int tmpIndex = this->addToScene(_strelica);
                this->tmpHolder->setParentNumber(tmpIndex);
                B->setNextNumber(tmpIndex);
                this->tmpHolder = NULL;
                B = NULL;
                _strelica = NULL;
                this->stanje = "Move";
                return;
            }*/
        }
    }
    else{
       if(this->_blokHolder != NULL)
       {
        _blokHolder->setPos(event->scenePos());   
        if(this->addToScene(_blokHolder) != -1)
        {
            addItem(_blokHolder);
        }
        _blokHolder=NULL;
        this->stanje = "Move";
        return;
       }
    }

    if(this->stanje == "Move")
    {
        QGraphicsScene::mousePressEvent(event);
    }

    /*
    for(int i=0; i<this->items().length(); i++)
    {
        AbstractBlok* tmpPrint = NULL;
        tmpPrint = (AbstractBlok *)this->items().at(i);
        if(tmpPrint != NULL)
            cout << i << ". " << (char *) tmpPrint->getIme().toLocal8Bit().data() << endl;
    }
    cout << "-------------------" << endl;*/
}
void GScena::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
}

void GScena::mouseReleaseEvent (QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}

void GScena::keyPressEvent(QKeyEvent *event)
{
  if(event->key()== Qt::Key_Delete)
  {
        foreach(QGraphicsItem* item,selectedItems())
        {
            if(item->type()!=QGraphicsLineItem::Type)
            {
                AbstractBlok* blok = dynamic_cast<AbstractBlok*>(item);

                //Ako postoji veza!
                if(blok->parentBlok()!=0)
                {
                    if(blok->parentBlok()->levaVeza()->childBlok()==blok)
                    {
                        removeItem(blok->parentBlok()->levaVeza());
                        blok->parentBlok()->obrisiStrelicu(true);
                    }
                    else
                    {
                        removeItem(blok->parentBlok()->desnaVeza());
                        blok->parentBlok()->obrisiStrelicu(false);

                    }
                }

                delete blok;
            }
        }
  }
}

void GScena::sacuvaj() {

    QString _fileName = QFileDialog::getSaveFileName(0, tr("Sacuvaj dokument") , " " , tr("Algovertor (*.alg)"));

 /*
    if (fileName.isEmpty()) {

        QMessageBox::information(this, "Greska", "Unesi ime datoteke");
        return;
    }

    else {

        //Pisanje XML fajla
        QDomDocument dokument;

        //Definisanje koren
        QDomElement koren = dokument.createElement ("fajl");

        //Dodavanje korena na dokument
        dokument.appendChild(koren);

        //Pisanje u fajl
        QFile fajl (fileName);

        if (!fajl.open(QIODevice::WriteOnly | QIODevice::Text)) {

            QMessageBox::information(this, "Greska", "Nije se otvorio fajl");
            return;
        }

        else {


        }
    }
    */


    if(_fileName==NULL)
        {
            return;
        }

   QFile fajl (_fileName);

    if (!fajl.open(QIODevice::WriteOnly)) {

        QMessageBox::information(0, tr("Algovertor"), tr("Greska prilikom cuvanja dokumenta!") );
        return;
    }

    QDataStream out (&fajl);
    out.setVersion(QDataStream::Qt_5_3);

    foreach (QGraphicsItem *item, items()) {

           //Da upise samo blokove, ne i veze!!
          if(item->type()!=QGraphicsLineItem::Type)
           {
             AbstractBlok* blok = (AbstractBlok*)item;
             out << blok->getTip() <<blok->getIme() << blok->getText() <<blok->getVeza() << blok->getVeza();
          }
    }
}

int GScena::addToScene(QGraphicsItem *item)
{
    if(this->top > this->max)
    {
        this->max += 20;
        QGraphicsItem** tmp = new QGraphicsItem* [this->top];
        for(int i = 0; i<this->top; i++){
            tmp[i] = this->grafickaScena[i];
            delete this->grafickaScena[i];
        }
        for(int i = 0; i<this->top; i++)
            delete tmp[i];
        delete[] tmp;

        this->grafickaScena = new QGraphicsItem* [this->max];
    }

    this->grafickaScena[this->top] = item;
    int tmpOut = this->top;
    this->top++;

    return tmpOut;
}

void GScena::removeFromScene(int index)
{
    if(index < 0)
        return;
    this->grafickaScena[index] = NULL;
}

QString GScena::convertToCode()
{
    /*AbstractBlok* tmp =
    while()*/
}

