#ifndef BULAZ_H
#define BULAZ_H

#include "abstractblok.h"

/* ===============================================
 * KLASA: BUlaz(Blok Ulaz)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka ULAZ na dijagramu toka algoritma
 *
 *================================================*/

class BUlaz : public AbstractBlok
{
    public:

        BUlaz(QString ime,QPoint lokacija=QPoint(0,0));

        QPainterPath shape() const;

    protected:
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BULAZ_H
