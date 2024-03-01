/********************************************************************************
** Form generated from reading UI file 'asudialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASUDIALOG_H
#define UI_ASUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ASUDialog
{
public:
    QLabel *label_number;
    QSpinBox *box_number;
    QPushButton *button_cancel;
    QPushButton *button_ok;

    void setupUi(QDialog *ASUDialog)
    {
        if (ASUDialog->objectName().isEmpty())
            ASUDialog->setObjectName("ASUDialog");
        ASUDialog->resize(389, 120);
        label_number = new QLabel(ASUDialog);
        label_number->setObjectName("label_number");
        label_number->setGeometry(QRect(20, 30, 251, 20));
        box_number = new QSpinBox(ASUDialog);
        box_number->setObjectName("box_number");
        box_number->setGeometry(QRect(280, 28, 81, 26));
        box_number->setMinimum(1);
        button_cancel = new QPushButton(ASUDialog);
        button_cancel->setObjectName("button_cancel");
        button_cancel->setGeometry(QRect(160, 70, 93, 30));
        button_ok = new QPushButton(ASUDialog);
        button_ok->setObjectName("button_ok");
        button_ok->setGeometry(QRect(270, 70, 93, 30));

        retranslateUi(ASUDialog);

        QMetaObject::connectSlotsByName(ASUDialog);
    } // setupUi

    void retranslateUi(QDialog *ASUDialog)
    {
        ASUDialog->setWindowTitle(QCoreApplication::translate("ASUDialog", "Dialog", nullptr));
        label_number->setText(QCoreApplication::translate("ASUDialog", "Enter the number of colleges to visit:", nullptr));
        button_cancel->setText(QCoreApplication::translate("ASUDialog", "Cancel", nullptr));
        button_ok->setText(QCoreApplication::translate("ASUDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ASUDialog: public Ui_ASUDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASUDIALOG_H
