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
#include "bcvor.h"

GScena::GScena(QObject *parent) : QGraphicsScene(parent)
{
    this->_blokHolder=NULL;
}

GScena::~GScena()
{
    delete _blokHolder;
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
    this->_blokHolder=new BStop("Stop"+brojac);
}

void GScena::setUlaz()
{
    this->_blokHolder=new BUlaz("Ulaz"+brojac);
}

void GScena::setIzlaz()
{
    this->_blokHolder=new BIzlaz("Izlaz"+brojac);
}

void GScena::setObrada()
{
    this->_blokHolder=new BObrada("Obrada"+brojac);
}

void GScena::setUslov()
{
    this->_blokHolder=new BUslov("Uslov"+brojac);
}

void GScena::setCvor()
{
    this->_blokHolder=new BCvor("Cvor"+brojac);
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

void GScena::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   if(_blokHolder!=NULL)
   {
    _blokHolder->setPos(event->scenePos());
     addItem(_blokHolder);
     brojac++;
    _blokHolder=NULL;
   }

   QGraphicsScene::mousePressEvent(event);
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

