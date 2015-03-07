#ifndef BOBRADA_H
#define BOBRADA_H

#include "bobrada.h"
#include "abstractblok.h"

/* ===============================================
 * KLASA: BObrada (Blok Obrada)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka OBRADA  na dijagramu toka algoritma
 *
 *================================================*/

class BObrada : public AbstractBlok
{
    public:

        BObrada(QString ime,QPoint lokacija=QPoint(0,0));
        BObrada();

        QPainterPath shape() const;

    protected:
        void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BOBRADA_H
