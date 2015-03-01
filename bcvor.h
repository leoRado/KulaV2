#ifndef BCVOR_H
#define BCVOR_H

#include "abstractblok.h"

/* ===============================================
 * KLASA: BCvor (Blok Cvor)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka START na dijagramu toka algoritma
 *
 *================================================*/

class BCvor : public AbstractBlok
{
    public:
        BCvor(QString ime,QPoint lokacija=QPoint(0,0));

        QPainterPath shape() const;

    protected:

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BCVOR_H
