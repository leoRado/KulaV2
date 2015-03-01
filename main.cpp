#include "aplikacija.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Aplikacija w;
    w.show();

    return a.exec();
}
