/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
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
    QAction *actionUniversity_Of_California_Irvine;
    QAction *actionArizona_State_University;
    QAction *actionAdmin;
    QWidget *centralwidget;
    QPushButton *button_go;
    QGroupBox *box_collegeNames;
    QVBoxLayout *verticalLayout;
    QListWidget *list_collegeNames;
    QGroupBox *box_collegeInfo;
    QLabel *label_collegeName;
    QLabel *label_distanceFromSaddlebackPREFIX;
    QListWidget *list_souvenirs;
    QPushButton *button_addSouvenir;
    QPushButton *button_editSouvenir;
    QPushButton *button_deleteSouvenir;
    QRadioButton *button_addToTrip;
    QPushButton *button_startingCollege;
    QLabel *label_collegeLogo;
    QLabel *label_tripColleges;
    QLabel *label_totalDistance;
    QPushButton *button_reset;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 643);
        actionUniversity_Of_California_Irvine = new QAction(MainWindow);
        actionUniversity_Of_California_Irvine->setObjectName("actionUniversity_Of_California_Irvine");
        actionArizona_State_University = new QAction(MainWindow);
        actionArizona_State_University->setObjectName("actionArizona_State_University");
        actionAdmin = new QAction(MainWindow);
        actionAdmin->setObjectName("actionAdmin");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        button_go = new QPushButton(centralwidget);
        button_go->setObjectName("button_go");
        button_go->setEnabled(false);
        button_go->setGeometry(QRect(680, 520, 80, 24));
        box_collegeNames = new QGroupBox(centralwidget);
        box_collegeNames->setObjectName("box_collegeNames");
        box_collegeNames->setGeometry(QRect(20, 20, 241, 431));
        verticalLayout = new QVBoxLayout(box_collegeNames);
        verticalLayout->setObjectName("verticalLayout");
        list_collegeNames = new QListWidget(box_collegeNames);
        list_collegeNames->setObjectName("list_collegeNames");
        list_collegeNames->setWordWrap(true);

        verticalLayout->addWidget(list_collegeNames);

        box_collegeInfo = new QGroupBox(centralwidget);
        box_collegeInfo->setObjectName("box_collegeInfo");
        box_collegeInfo->setEnabled(true);
        box_collegeInfo->setGeometry(QRect(280, 20, 501, 431));
        label_collegeName = new QLabel(box_collegeInfo);
        label_collegeName->setObjectName("label_collegeName");
        label_collegeName->setGeometry(QRect(20, 30, 461, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(16);
        font.setBold(true);
        label_collegeName->setFont(font);
        label_collegeName->setAlignment(Qt::AlignCenter);
        label_distanceFromSaddlebackPREFIX = new QLabel(box_collegeInfo);
        label_distanceFromSaddlebackPREFIX->setObjectName("label_distanceFromSaddlebackPREFIX");
        label_distanceFromSaddlebackPREFIX->setGeometry(QRect(20, 95, 381, 21));
        QFont font1;
        font1.setPointSize(10);
        label_distanceFromSaddlebackPREFIX->setFont(font1);
        list_souvenirs = new QListWidget(box_collegeInfo);
        list_souvenirs->setObjectName("list_souvenirs");
        list_souvenirs->setGeometry(QRect(20, 140, 221, 192));
        button_addSouvenir = new QPushButton(box_collegeInfo);
        button_addSouvenir->setObjectName("button_addSouvenir");
        button_addSouvenir->setEnabled(false);
        button_addSouvenir->setGeometry(QRect(20, 350, 80, 24));
        button_editSouvenir = new QPushButton(box_collegeInfo);
        button_editSouvenir->setObjectName("button_editSouvenir");
        button_editSouvenir->setEnabled(false);
        button_editSouvenir->setGeometry(QRect(109, 350, 80, 24));
        button_deleteSouvenir = new QPushButton(box_collegeInfo);
        button_deleteSouvenir->setObjectName("button_deleteSouvenir");
        button_deleteSouvenir->setEnabled(false);
        button_deleteSouvenir->setGeometry(QRect(197, 350, 80, 24));
        button_addToTrip = new QRadioButton(box_collegeInfo);
        button_addToTrip->setObjectName("button_addToTrip");
        button_addToTrip->setEnabled(false);
        button_addToTrip->setGeometry(QRect(20, 390, 91, 22));
        button_startingCollege = new QPushButton(box_collegeInfo);
        button_startingCollege->setObjectName("button_startingCollege");
        button_startingCollege->setEnabled(false);
        button_startingCollege->setGeometry(QRect(19, 390, 111, 24));
        label_collegeLogo = new QLabel(box_collegeInfo);
        label_collegeLogo->setObjectName("label_collegeLogo");
        label_collegeLogo->setGeometry(QRect(280, 149, 181, 181));
        label_tripColleges = new QLabel(centralwidget);
        label_tripColleges->setObjectName("label_tripColleges");
        label_tripColleges->setGeometry(QRect(20, 470, 641, 71));
        label_tripColleges->setWordWrap(true);
        label_totalDistance = new QLabel(centralwidget);
        label_totalDistance->setObjectName("label_totalDistance");
        label_totalDistance->setGeometry(QRect(20, 560, 361, 20));
        button_reset = new QPushButton(centralwidget);
        button_reset->setObjectName("button_reset");
        button_reset->setEnabled(true);
        button_reset->setGeometry(QRect(680, 560, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionUniversity_Of_California_Irvine->setText(QCoreApplication::translate("MainWindow", "University Of California Irvine", nullptr));
        actionArizona_State_University->setText(QCoreApplication::translate("MainWindow", "Arizona State University", nullptr));
        actionAdmin->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        button_go->setText(QCoreApplication::translate("MainWindow", "Go!", nullptr));
        box_collegeNames->setTitle(QCoreApplication::translate("MainWindow", "Colleges", nullptr));
        box_collegeInfo->setTitle(QCoreApplication::translate("MainWindow", "College Info", nullptr));
        label_collegeName->setText(QString());
        label_distanceFromSaddlebackPREFIX->setText(QString());
        button_addSouvenir->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        button_editSouvenir->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        button_deleteSouvenir->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        button_addToTrip->setText(QCoreApplication::translate("MainWindow", "Add to Trip", nullptr));
        button_startingCollege->setText(QCoreApplication::translate("MainWindow", "Starting College", nullptr));
        label_collegeLogo->setText(QString());
        label_tripColleges->setText(QString());
        label_totalDistance->setText(QString());
        button_reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
