#ifndef BWHILE_H
#define BWHILE_H

#include "abstractblok.h"

/* ===============================================
 * KLASA: BWhile (Blok While)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka While na dijagramu toka algoritma
 *
 *================================================*/

class BWhile : public AbstractBlok
{
    public:
        BWhile(QString ime,QPoint lokacija=QPoint(0,0));
        QPainterPath shape() const;

protected:
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BWHILE_H
