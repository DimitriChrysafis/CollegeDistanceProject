/********************************************************************************
** Form generated from reading UI file 'souvenirdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUVENIRDIALOG_H
#define UI_SOUVENIRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SouvenirDialog
{
public:
    QPushButton *button_cancel;
    QPushButton *button_ok;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_item;
    QLineEdit *lineEdit_price;
    QLabel *label_price;
    QLineEdit *lineEdit_item;

    void setupUi(QDialog *SouvenirDialog)
    {
        if (SouvenirDialog->objectName().isEmpty())
            SouvenirDialog->setObjectName(QString::fromUtf8("SouvenirDialog"));
        SouvenirDialog->resize(400, 184);
        button_cancel = new QPushButton(SouvenirDialog);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));
        button_cancel->setGeometry(QRect(210, 140, 80, 24));
        button_ok = new QPushButton(SouvenirDialog);
        button_ok->setObjectName(QString::fromUtf8("button_ok"));
        button_ok->setGeometry(QRect(300, 140, 80, 24));
        groupBox = new QGroupBox(SouvenirDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 351, 101));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_item = new QLabel(groupBox);
        label_item->setObjectName(QString::fromUtf8("label_item"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_item);

        lineEdit_price = new QLineEdit(groupBox);
        lineEdit_price->setObjectName(QString::fromUtf8("lineEdit_price"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_price);

        label_price = new QLabel(groupBox);
        label_price->setObjectName(QString::fromUtf8("label_price"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_price);

        lineEdit_item = new QLineEdit(groupBox);
        lineEdit_item->setObjectName(QString::fromUtf8("lineEdit_item"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_item);


        retranslateUi(SouvenirDialog);

        QMetaObject::connectSlotsByName(SouvenirDialog);
    } // setupUi

    void retranslateUi(QDialog *SouvenirDialog)
    {
        SouvenirDialog->setWindowTitle(QCoreApplication::translate("SouvenirDialog", "Dialog", nullptr));
        button_cancel->setText(QCoreApplication::translate("SouvenirDialog", "Cancel", nullptr));
        button_ok->setText(QCoreApplication::translate("SouvenirDialog", "Ok", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SouvenirDialog", "Souvenir", nullptr));
        label_item->setText(QCoreApplication::translate("SouvenirDialog", "Item", nullptr));
        label_price->setText(QCoreApplication::translate("SouvenirDialog", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SouvenirDialog: public Ui_SouvenirDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUVENIRDIALOG_H
