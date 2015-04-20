#include "calcdiv.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalcDiv w;
    w.show();

    return a.exec();
}
