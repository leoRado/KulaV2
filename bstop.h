#ifndef BSTOP_H
#define BSTOP_H

#include "abstractblok.h"

/* ===============================================
 * KLASA: BStop(Blok Stop)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka STOP na dijagramu toka algoritma
 *
 *================================================*/

class BStop : public AbstractBlok
{
    public:

        BStop(QString ime,QPoint lokacija=QPoint(0,0));

        QPainterPath shape() const;

    protected:

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BSTOP_H
