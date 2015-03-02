#include "abstractstrelica.h"
#include <QPen>


AbstractStrelica::AbstractStrelica()
{
    this->_blokA=NULL;
    this->_blokB=NULL;
}

AbstractStrelica::AbstractStrelica(AbstractBlok *blokA, AbstractBlok *blokB)
{
    QPen _pen(Qt::black,1.0);
    setPen(_pen);
    this->_blokA=blokA;
    this->_blokB=blokB;

    _blokA->dodajStrelicu(true,this);
    _blokB->dodajParentBlok(_blokA);

    setFlags(QGraphicsItem::ItemIsSelectable);

    _bojaLinije=Qt::black;
    setZValue(-1);
}

QRectF AbstractStrelica::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;

        return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                          line().p2().y() - line().p1().y()))
            .normalized()
            .adjusted(-extra, -extra, extra, extra);
}

void AbstractStrelica::nacrtajVezu()
{
    QLineF line(mapFromItem(_blokA, 0, 0), mapFromItem(_blokB, 0, 0));
    setLine(line);
}

AbstractStrelica::~AbstractStrelica()
{
    _blokA->obrisiStrelicu(this);
    _blokB->obrisiParentBlok();
}

AbstractBlok*AbstractStrelica::parentBlok() const
{
    return _blokA;
}

AbstractBlok*AbstractStrelica::childBlok() const
{
    return _blokB;
}


