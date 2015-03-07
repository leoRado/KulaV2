#ifndef GSCENA_H
#define GSCENA_H

#include <QObject>
#include <QGraphicsScene>
#include "abstractblok.h"
#include <QCursor>

/* =====================================================
 * KLASA: GScena
 *
 * OPIS: Klasa nasledjena iz QGraphicsScene, pretstavlja
 * scenu na kojoj se crtaju 2D blokovi, veze i vrsi interakcija
 *sa njima
 *=====================================================*/

class GScena : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GScena(QObject *parent = 0);
    ~GScena();

    //Metoda za postavljanje bloka u holder
    void setBlok(AbstractBlok* blok);

    void setStart();
    void setStop();
    void setUlaz();
    void setIzlaz();
    void setObrada();
    void setUslov();
    void setCvor();
    void setFor();
    void setWhile();
    void setDoWhile();

    int addToScene(QGraphicsItem* item);
    void removeFromScene(int index);

   //Metode za cuvanje dokumenta
    void sacuvaj ();
    void obradiListu();

    //Metode za konverziju dijagrama u kod

    QString getKod();
    QString stanje;

    QString convertToCode();


signals:

public slots:

protected:

    //Metoda koja se izvrsava na MouseClick
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

private:
    //Promenljive
    QGraphicsItem * _blokHolder;
    int brojac=0; //Brojac elemenata
    AbstractBlok *prviSelektovaniObjekat;
    AbstractBlok *drugiSelektovaniObjekat;

    AbstractBlok* start;


    QGraphicsItem** grafickaScena;
    int top;
    int max;

};

#endif // GSCENA_H
