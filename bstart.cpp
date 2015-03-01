#include "bstart.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

BStart::BStart(QString ime, QPoint lokacija)
{
    this->_tip="Start";
    this->_ime=ime;
    this->_tekst=" START";

    this->_tekstBoja=QColor(0,0,0,255);
    this->_pozadinaBoja=QColor(102,204,0,255);
    this->_linijaBoja=QColor(51,102,0,255);

    this->setPos(lokacija);

    //this->setToolTip("Blok "+this->_ime+":\n"+"#include<stdio.h>\n int main(){ ...");
}

QPainterPath BStart::shape() const
{
    QRectF rect = outlineRect();
    QPainterPath path;

    path.addEllipse(rect.x(),rect.y(),rect.width(),rect.height());
    return path;
}

void BStart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(_linijaBoja,2);

       if (option->state & QStyle::State_Selected) {
           pen.setColor(Qt::black);
           pen.setStyle(Qt::DotLine);
           pen.setWidth(2);
       }

       painter->setPen(pen);
       painter->setBrush(_pozadinaBoja);

       QRectF rect = outlineRect();

       painter->drawEllipse(rect.x(),rect.y(),rect.width(),rect.height());

       painter->setPen(_tekstBoja);
       painter->drawText(rect, Qt::AlignCenter, _tekst);
}

