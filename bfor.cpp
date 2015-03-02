#include "bfor.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QInputDialog>
#include <QLineEdit>

BFor::BFor(QString ime, QPoint lokacija)
{
    this->_tip="For";
    this->_ime=ime;
    this->_tekst=" <podaci> ";

    this->_tekstBoja=QColor(0,0,0,255);
    this->_pozadinaBoja=QColor(255,178,102,255);
    this->_linijaBoja=QColor(153,76,0,255);

    this->setPos(lokacija);
}

QPainterPath BFor::shape() const
{
    QRectF rect = outlineRect();
    QPainterPath path;

    path.addRect(rect.x(),rect.y(),rect.width(),rect.height());

    return path;
}

void BFor::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
    QString text = QInputDialog::getText(0,"Blok for", "Unesi podatke:",QLineEdit::Normal);
       if (!text.isEmpty())
           setText(text);
}

void BFor::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
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
