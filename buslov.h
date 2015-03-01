#ifndef BUSLOV_H
#define BUSLOV_H

#include "abstractblok.h"

/* ===============================================
 * KLASA: BUslov(Blok Uslov)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka USLOV na dijagramu toka algoritma
 *
 *================================================*/

class BUslov : public AbstractBlok
{
    public:

        BUslov(QString ime,QPoint lokacija=QPoint(0,0));

        QPainterPath shape() const;

    protected:
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BUSLOV_H
