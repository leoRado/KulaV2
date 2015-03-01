#ifndef BSTART_H
#define BSTART_H

#include "abstractblok.h"

/* ===============================================
 * KLASA: BStart (Blok Start)
 *
 * OPIS: Klasa nasledjena iz AbstractBlok, pretstavlja
 * model bloka START na dijagramu toka algoritma
 *
 *================================================*/

class BStart : public AbstractBlok
{
public:


    BStart(QString ime,QPoint lokacija=QPoint(0,0));

    QPainterPath shape() const;

    protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BSTART_H
