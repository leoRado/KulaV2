#include "bobrada.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

BObrada::BObrada(QString ime, QPoint lokacija)
{
    this->_tip="Obrada";
    this->_ime=ime;
    this->_tekst=" <podaci> ";


    this->_tekstBoja=QColor(0,0,0,255);
    this->_pozadinaBoja=QColor(153,204,255,255);
    this->_linijaBoja=QColor(0,128,255,255);

    this->setPos(lokacija);
}

QPainterPath BObrada::shape() const
{
    QRectF rect = outlineRect();
    QPainterPath path;

    path.addRect(rect.x(),rect.y(),rect.width(),rect.height());

    return path;
}

void BObrada::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

}

void BObrada::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
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

       painter->drawRect(rect.x(),rect.y(),rect.width(),rect.height());

       painter->setPen(_tekstBoja);
       painter->drawText(rect, Qt::AlignCenter, _tekst);
}
