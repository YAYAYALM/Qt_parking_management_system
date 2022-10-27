#include "parkwin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ParkWin w;
    w.show();
    return a.exec();
}
