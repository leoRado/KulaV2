#ifndef BFOR_H
#define BFOR_H

#include "bobrada.h"
#include "abstractblok.h"

/* ===============================================
 * KLASA: BFor (Blok For)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka FOR  na dijagramu toka algoritma
 *
 *================================================*/

class BFor : public AbstractBlok
{
    public:
        BFor(QString ime,QPoint lokacija=QPoint(0,0));
        QPainterPath shape() const;

    protected:

        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BFOR_H
