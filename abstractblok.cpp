#include "abstractblok.h"
#include "qapplication.h"
#include <QFontMetrics>

AbstractBlok::AbstractBlok()
{
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsGeometryChanges);

    _levoDete=NULL;
    _desnoDete=NULL;
    _parentBlok=NULL;
    _padding=11;
}

AbstractBlok::~AbstractBlok()
{
  delete _levoDete;
  delete _desnoDete;
}

void AbstractBlok::setText(QString tekst)
{
    prepareGeometryChange();
    this->_tekst=tekst;
    update();
}

QString AbstractBlok::getText()
{
    return this->_tekst;
}

QString AbstractBlok::getTip()
{
    return this->_tip;
}

QString AbstractBlok::getIme()
{
    return this->_ime;
}

QString AbstractBlok::getVeza()
{
    return this->_veza;
}

QRectF AbstractBlok::boundingRect() const
{
    const int Margin = 1;
    return outlineRect().adjusted(-Margin, -Margin, +Margin, +Margin);
}

void AbstractBlok::dodajStrelicu(bool dete,AbstractStrelica *strelica)
{
    if(dete)
    {
        _levoDete=strelica;
    }
    else
    {
        _desnoDete=strelica;
    }
}

void AbstractBlok::dodajParentBlok(AbstractBlok *blok)
{
   _parentBlok=blok;
}

void AbstractBlok::obrisiStrelicu(bool dete)
{
    if(dete)
    {
       _levoDete=NULL;
    }
    else
    {
        _desnoDete=NULL;
    }
}

void AbstractBlok::obrisiStrelice()
{
   _levoDete=NULL;
   _desnoDete=NULL;
}

void AbstractBlok::obrisiParentBlok()
{
    _parentBlok=NULL;
}

AbstractStrelica*AbstractBlok::levaVeza() const
{
 return _levoDete;
}

AbstractStrelica*AbstractBlok::desnaVeza() const
{
    return _desnoDete;
}

AbstractBlok *AbstractBlok::parentBlok() const
{
    return _parentBlok;
}

bool AbstractBlok::vezanZa(AbstractBlok* blok)
{
    if(_levoDete->childBlok()==blok || _desnoDete->childBlok()==blok)
        {
            return true;
        }
    else
        {
            return false;
        }
}

bool AbstractBlok::imaVezu()
{
    if(_levoDete!=NULL || _desnoDete!=NULL)
        {
            return true;
        }
}

QVariant AbstractBlok::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionHasChanged) {

       }
       return QGraphicsItem::itemChange(change, value);
}

QRectF AbstractBlok::outlineRect() const
{
    //const int _padding = 10;
    QFontMetricsF metrics = qApp->fontMetrics();
    QRectF rect = metrics.boundingRect(this->_tekst);
    rect.adjust(-_padding, -_padding, +_padding, +_padding);
    rect.translate(-rect.center());
    return rect;
}

