#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSize size;
    size.setWidth(243);
    size.setHeight(375);
    w.setFixedSize(size);
    w.show();
    return a.exec();
}
