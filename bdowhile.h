#ifndef BDOWHILE_H
#define BDOWHILE_H

#include "abstractblok.h"

/* ===============================================
 * KLASA: BWhile (Blok While)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka DoWhile na dijagramu toka algoritma
 *
 *================================================*/

class BDoWhile : public AbstractBlok
{
    public:
        BDoWhile(QString ime,QPoint lokacija=QPoint(0,0));
        QPainterPath shape() const;

    protected:
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BDOWHILE_H
