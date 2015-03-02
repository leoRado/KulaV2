#include "aplikacija.h"
#include "ui_aplikacija.h"
#include "bstart.h"
#include "sobicna.h"

#include <QSaveFile>


Aplikacija::Aplikacija(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Aplikacija)
{
    ui->setupUi(this);
    _scena=new GScena();
    _scena->setSceneRect(0,0,3000,3000);
    ui->graphicsView->setScene(_scena);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing,true);
}

Aplikacija::~Aplikacija()
{
    delete ui;
}

void Aplikacija::on_pushButton_clicked()
{
_scena->setStart();
}

void Aplikacija::on_pushButton_2_clicked()
{
  AbstractBlok* A = (AbstractBlok*)_scena->items().at(1);
  AbstractBlok* B = (AbstractBlok*)_scena->items().at(0);

  SObicna* _strelica = new SObicna(A,B);
  _scena->addItem(_strelica);
}

void Aplikacija::on_actionSacuvaj_triggered()
{
    _scena->sacuvaj();
}

void Aplikacija::on_pushButton_3_clicked()
{
    _scena->setStop();
}

void Aplikacija::on_pushButton_4_clicked()
{
    _scena->setUlaz();
}

void Aplikacija::on_pushButton_5_clicked()
{
   _scena->setIzlaz();
}

void Aplikacija::on_pushButton_6_clicked()
{
    _scena->setObrada();
}

void Aplikacija::on_pushButton_7_clicked()
{
    _scena->setUslov();
}

void Aplikacija::on_pushButton_8_clicked()
{
    _scena->setCvor();
}

void Aplikacija::on_pushButton_9_clicked()
{
    _scena->setFor();
}

void Aplikacija::on_pushButton_10_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->insertPlainText(_scena->getKod());

}
