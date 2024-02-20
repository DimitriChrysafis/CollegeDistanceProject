/********************************************************************************
** Form generated from reading UI file 'tripdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPDIALOG_H
#define UI_TRIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TripDialog
{
public:
    QPushButton *button_previous;
    QPushButton *button_next;

    void setupUi(QDialog *TripDialog)
    {
        if (TripDialog->objectName().isEmpty())
            TripDialog->setObjectName(QString::fromUtf8("TripDialog"));
        TripDialog->resize(539, 456);
        button_previous = new QPushButton(TripDialog);
        button_previous->setObjectName(QString::fromUtf8("button_previous"));
        button_previous->setGeometry(QRect(20, 420, 80, 24));
        button_next = new QPushButton(TripDialog);
        button_next->setObjectName(QString::fromUtf8("button_next"));
        button_next->setGeometry(QRect(430, 420, 80, 24));

        retranslateUi(TripDialog);

        QMetaObject::connectSlotsByName(TripDialog);
    } // setupUi

    void retranslateUi(QDialog *TripDialog)
    {
        TripDialog->setWindowTitle(QCoreApplication::translate("TripDialog", "Dialog", nullptr));
        button_previous->setText(QCoreApplication::translate("TripDialog", "Previous", nullptr));
        button_next->setText(QCoreApplication::translate("TripDialog", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TripDialog: public Ui_TripDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPDIALOG_H
