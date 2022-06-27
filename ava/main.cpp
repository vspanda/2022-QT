#include "choosemonth.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    choosemonth w;
    w.show();
    return a.exec();
}
