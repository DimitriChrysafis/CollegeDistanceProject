#include "mainwindow.h"

#include <fstream>
#include <QApplication>
#include <iostream>
#include <QDir>
#include <QString>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    //Test for branches
}

