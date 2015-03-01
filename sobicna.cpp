#include "sobicna.h"
#include <QPainter>


SObicna::SObicna(AbstractBlok *blokA, AbstractBlok *blokB):AbstractStrelica(blokA,blokB)
{
    setLine(QLineF(blokA->pos(), blokB->pos()));
}

void SObicna::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        if(_blokA->collidesWithItem(_blokB))
            {
                return;
            }

        QPen _olovka=pen();
        _olovka.setColor(Qt::black);
        _olovka.setWidthF(1.6);
        painter->setPen(_olovka);

        setLine(QLineF(_blokA->pos(),_blokB->pos()));

        painter->drawLine(line());
}

void SObicna::nacrtajVezu()
{
    QLineF line(mapFromItem(_blokA, 0, 0), mapFromItem(_blokB, 0, 0));
    setLine(line);
}

