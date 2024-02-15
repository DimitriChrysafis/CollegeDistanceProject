#include "mainwindow.h"
#include "storewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CampusStore store;
    store.show();
    return a.exec();
}
