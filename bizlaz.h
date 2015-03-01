#ifndef BIZLAZ_H
#define BIZLAZ_H

#include "abstractblok.h"

/* ===============================================
 * KLASA: BIzlaz (Blok izlaz)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka IZLAZ na dijagramu toka algoritma
 *
 *================================================*/

class BIzlaz : public AbstractBlok
{
    public:

        BIzlaz(QString ime, QPoint lokacija=QPoint(0,0));

        QPainterPath shape() const;

    protected:
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BIZLAZ_H
