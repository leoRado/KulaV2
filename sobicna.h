#ifndef SOBICNA_H
#define SOBICNA_H

#include "abstractstrelica.h"

class SObicna : public AbstractStrelica
{
public:
    SObicna(AbstractBlok* blokA,AbstractBlok* blokB);

    void refreshLinija();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void nacrtajVezu();
};

#endif // SOBICNA_H
