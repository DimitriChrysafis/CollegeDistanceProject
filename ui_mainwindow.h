/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *button_go;
    QGroupBox *box_collegeNames;
    QVBoxLayout *verticalLayout;
    QListWidget *list_collegeNames;
    QGroupBox *box_collegeInfo;
    QLabel *label_collegeName;
    QLabel *label_distanceFromSaddlebackPREFIX;
    QListWidget *list_souvenirs;
    QLabel *label_distanceFromSaddleback;
    QPushButton *button_addSouvenir;
    QPushButton *button_editSouvenir;
    QPushButton *button_deleteSouvenir;
    QRadioButton *button_addToTrip;
    QLabel *label_tripColleges;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        button_go = new QPushButton(centralwidget);
        button_go->setObjectName(QString::fromUtf8("button_go"));
        button_go->setGeometry(QRect(680, 520, 80, 24));
        box_collegeNames = new QGroupBox(centralwidget);
        box_collegeNames->setObjectName(QString::fromUtf8("box_collegeNames"));
        box_collegeNames->setGeometry(QRect(20, 20, 241, 481));
        verticalLayout = new QVBoxLayout(box_collegeNames);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        list_collegeNames = new QListWidget(box_collegeNames);
        list_collegeNames->setObjectName(QString::fromUtf8("list_collegeNames"));

        verticalLayout->addWidget(list_collegeNames);

        box_collegeInfo = new QGroupBox(centralwidget);
        box_collegeInfo->setObjectName(QString::fromUtf8("box_collegeInfo"));
        box_collegeInfo->setGeometry(QRect(280, 20, 501, 481));
        label_collegeName = new QLabel(box_collegeInfo);
        label_collegeName->setObjectName(QString::fromUtf8("label_collegeName"));
        label_collegeName->setGeometry(QRect(20, 40, 171, 16));
        label_distanceFromSaddlebackPREFIX = new QLabel(box_collegeInfo);
        label_distanceFromSaddlebackPREFIX->setObjectName(QString::fromUtf8("label_distanceFromSaddlebackPREFIX"));
        label_distanceFromSaddlebackPREFIX->setGeometry(QRect(20, 100, 151, 16));
        list_souvenirs = new QListWidget(box_collegeInfo);
        list_souvenirs->setObjectName(QString::fromUtf8("list_souvenirs"));
        list_souvenirs->setGeometry(QRect(20, 140, 256, 192));
        label_distanceFromSaddleback = new QLabel(box_collegeInfo);
        label_distanceFromSaddleback->setObjectName(QString::fromUtf8("label_distanceFromSaddleback"));
        label_distanceFromSaddleback->setGeometry(QRect(200, 100, 71, 16));
        button_addSouvenir = new QPushButton(box_collegeInfo);
        button_addSouvenir->setObjectName(QString::fromUtf8("button_addSouvenir"));
        button_addSouvenir->setEnabled(false);
        button_addSouvenir->setGeometry(QRect(20, 350, 80, 24));
        button_editSouvenir = new QPushButton(box_collegeInfo);
        button_editSouvenir->setObjectName(QString::fromUtf8("button_editSouvenir"));
        button_editSouvenir->setEnabled(false);
        button_editSouvenir->setGeometry(QRect(109, 350, 80, 24));
        button_deleteSouvenir = new QPushButton(box_collegeInfo);
        button_deleteSouvenir->setObjectName(QString::fromUtf8("button_deleteSouvenir"));
        button_deleteSouvenir->setEnabled(false);
        button_deleteSouvenir->setGeometry(QRect(197, 350, 80, 24));
        button_addToTrip = new QRadioButton(box_collegeInfo);
        button_addToTrip->setObjectName(QString::fromUtf8("button_addToTrip"));
        button_addToTrip->setEnabled(false);
        button_addToTrip->setGeometry(QRect(20, 390, 91, 22));
        label_tripColleges = new QLabel(centralwidget);
        label_tripColleges->setObjectName(QString::fromUtf8("label_tripColleges"));
        label_tripColleges->setGeometry(QRect(20, 520, 641, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button_go->setText(QCoreApplication::translate("MainWindow", "Go!", nullptr));
        box_collegeNames->setTitle(QCoreApplication::translate("MainWindow", "Colleges", nullptr));
        box_collegeInfo->setTitle(QCoreApplication::translate("MainWindow", "College Info", nullptr));
        label_collegeName->setText(QString());
        label_distanceFromSaddlebackPREFIX->setText(QCoreApplication::translate("MainWindow", "Distance from Saddleback:", nullptr));
        label_distanceFromSaddleback->setText(QString());
        button_addSouvenir->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        button_editSouvenir->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        button_deleteSouvenir->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        button_addToTrip->setText(QCoreApplication::translate("MainWindow", "Add to Trip", nullptr));
        label_tripColleges->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
