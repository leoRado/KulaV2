#ifndef ABSTRACTBLOK_H
#define ABSTRACTBLOK_H

#include <QGraphicsItem>
#include "abstractstrelica.h"

/* ============================================
 * KLASA: AbstractBlok
 *
 * OPIS: Klasa koja sadrzi sve potrebne metode
 * i parametre za crtanje i povezivanje 2D blokova
 * na grafickoj sceni (Gscena)
 *
 *============================================*/

class AbstractStrelica;

class AbstractBlok : public QGraphicsItem
{
public:

    AbstractBlok();

     enum { Type = UserType + 15 };

    ~AbstractBlok();

    // -- METODE --

    void setText(QString tekst);  //Metoda za postavljanje teksta na blok
    QString getText();                    //Metoda za preuzimanje teksta sa bloka
    QString getTip();                     //Metoda za preuzimanje tipa bloka
    QString getIme();
    QString getVeza();
    int getNextNumber();
    void setNextNumber(int number);
    int getParentNumber();
    void setParentNumber(int number);
    AbstractBlok* getNext();
    AbstractBlok* getParent();
    bool isParentFull();
    bool isNextFull();

    void deleteParent();
    void deleteNext();

    QRectF boundingRect() const;

     //Virtuelna metoda za dobijanje 2D crteza, ako je potrebno za export u JPG itd.
    virtual QPainterPath shape()  const = 0;

     //Virtuelna metoda koja crta 2D crtez na GScena
    virtual void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;

    //Metode za povezivanje blokova
    void dodajStrelicu(AbstractBlok  *blok);
    void dodajParentBlok(AbstractBlok* blok);

    void obrisiStrelicu(bool dete);
    void obrisiStrelice();

    void obrisiParentBlok();

    //Metode za preuzimanje leve i desne strelice
    AbstractStrelica* levaVeza() const;
    AbstractStrelica* desnaVeza() const;
    AbstractBlok *parentBlok() const;                   //Parent

    //Metode za proveru da li je blok povezan
    bool vezanZa(AbstractBlok* blok);
    bool imaVezu();

protected:


    QVariant itemChange(GraphicsItemChange change,const QVariant &value); //Metoda koja se poziva kada se objekat pomeri

    QRectF outlineRect() const;

    //Promenljive

    AbstractBlok* _parentBlok;
    AbstractBlok* next;
    AbstractStrelica* _levoDete;
    AbstractStrelica* _desnoDete;

    QString _tekst;
    QString _tip;
    QString _ime;
    QString _veza;
    QColor  _tekstBoja;
    QColor  _pozadinaBoja;
    QColor  _linijaBoja;

    int _padding;
    int nextNumber;
    int parentNumber;

};

#endif // ABSTRACTBLOK_H
