#ifndef ABSTRACTSTRELICA_H
#define ABSTRACTSTRELICA_H

#include <QGraphicsLineItem>
#include "abstractblok.h"

/* ============================================
 * KLASA: AbstractStrelica
 *
 * OPIS: Klasa koja sadrzi sve potrebne metode
 * i parametre za crtanje veza izmedju blokova
 * na grafickoj sceni (Gscena)
 *
 *============================================*/


class AbstractBlok;

class AbstractStrelica : public QGraphicsLineItem
{
public:

   AbstractStrelica();
   AbstractStrelica(AbstractBlok* blokA,AbstractBlok* blokB);
   enum { Type = UserType + 4 };

   ~AbstractStrelica();

   //Metode za vracanje blokova koji su povezani strelicom
    AbstractBlok* parentBlok() const;
    AbstractBlok* childBlok()  const;

    //Metoda za refresh prilikom pomeranja 2D blokova na sceni
    virtual void nacrtajVezu()=0;

    QRectF boundingRect() const;
    AbstractBlok* getBlockB();

protected:

     virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;

    //Promenljive
    AbstractBlok* _blokA;
    AbstractBlok* _blokB;
    QColor _bojaLinije;
};

#endif // ABSTRACTSTRELICA_H
