#include "bulaz.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QInputDialog>
#include <QLineEdit>


BUlaz::BUlaz(QString ime, QPoint lokacija)
{
    this->_tip="Ulaz";
    this->_ime=ime;
    this->_tekst="  <podaci> ";

    this->_tekstBoja=QColor(0,0,0,255);
    this->_pozadinaBoja=QColor(252,212,64,255);
    this->_linijaBoja=QColor(206,172,65,255);

    this->setPos(lokacija);
}

QPainterPath BUlaz::shape() const
{
    QRectF rect = outlineRect();
    QPainterPath path;

    QPolygon _poligon;

    _poligon.append(rect.topLeft().toPoint());
    _poligon.append(rect.topRight().toPoint());
    _poligon.append(rect.bottomRight().toPoint()-QPoint(10,0));
    _poligon.append(rect.bottomLeft().toPoint()+QPoint(10,0));

    path.addPolygon(_poligon);

    return path;
}

void BUlaz::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QString text = QInputDialog::getText(0,"Blok ulaz", "Unesi podatke:",QLineEdit::Normal);
       if (!text.isEmpty())
           setText(text);
}

void BUlaz::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
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

       QPolygon _poligon;

       _poligon.append(rect.topLeft().toPoint());
       _poligon.append(rect.topRight().toPoint());
       _poligon.append(rect.bottomRight().toPoint()-QPoint(10,0));
       _poligon.append(rect.bottomLeft().toPoint()+QPoint(10,0));

       painter->drawPolygon(_poligon,Qt::OddEvenFill);

       painter->setPen(_tekstBoja);

       painter->drawText(rect, Qt::AlignCenter, _tekst);
}
