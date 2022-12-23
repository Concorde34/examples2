#include "mainwindow.h"

#include <QApplication>


// Разобраться почему не убираются минимальные элементы?
// Это проблема UI или класса? или может быть не правильно работает обработчик событий кнопки???


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
