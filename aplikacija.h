#ifndef APLIKACIJA_H
#define APLIKACIJA_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "gscena.h"

namespace Ui {
class Aplikacija;
}

class Aplikacija : public QMainWindow
{
    Q_OBJECT

public:
    explicit Aplikacija(QWidget *parent = 0);
    ~Aplikacija();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_actionSacuvaj_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    private:
    Ui::Aplikacija *ui;
    GScena* _scena;
};

#endif // APLIKACIJA_H
