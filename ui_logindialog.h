/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *button_cancel;
    QPushButton *button_ok;
    QLabel *label_password;
    QLineEdit *line_password;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(400, 112);
        button_cancel = new QPushButton(LoginDialog);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));
        button_cancel->setGeometry(QRect(200, 70, 80, 24));
        button_ok = new QPushButton(LoginDialog);
        button_ok->setObjectName(QString::fromUtf8("button_ok"));
        button_ok->setGeometry(QRect(300, 70, 80, 24));
        label_password = new QLabel(LoginDialog);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(20, 29, 61, 16));
        line_password = new QLineEdit(LoginDialog);
        line_password->setObjectName(QString::fromUtf8("line_password"));
        line_password->setGeometry(QRect(90, 24, 281, 24));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        button_cancel->setText(QCoreApplication::translate("LoginDialog", "Cancel", nullptr));
        button_ok->setText(QCoreApplication::translate("LoginDialog", "Ok", nullptr));
        label_password->setText(QCoreApplication::translate("LoginDialog", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
