#include "mainwindow.h"

#include <QApplication>
#include <QDir>
#include <QString>

/**
 * @brief The main function of the program. :)
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    // Test for branches
}
