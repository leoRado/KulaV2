#include "bcvor.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>


BCvor::BCvor(QString ime, QPoint lokacija)
{
    this->_tip="Cvor";
    this->_ime=ime;
    this->_tekst="";

    this->_tekstBoja=QColor(0,0,0,255);
    this->_pozadinaBoja=QColor(255,255,255,255);
    this->_linijaBoja=QColor(64,64,64,255);

    this->setPos(lokacija);

    this->_padding=6;
}

QPainterPath BCvor::shape() const
{
    QRectF rect = outlineRect();
    QPainterPath path;

    path.addEllipse(rect.x(),rect.y(),rect.width(),rect.height());
    return path;
}

void BCvor::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
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
