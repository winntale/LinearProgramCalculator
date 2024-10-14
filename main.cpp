#include "lpwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LpWidget w;
    w.show();
    return a.exec();
}
