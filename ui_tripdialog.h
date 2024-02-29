/********************************************************************************
** Form generated from reading UI file 'tripdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPDIALOG_H
#define UI_TRIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TripDialog
{
public:
    QPushButton* button_previous;
    QPushButton* button_next;
    QLabel* label_collegeName;
    QLabel* label_distance_next;
    QLabel* label_next;
    QLabel* label_previous;
    QLabel* label_distance_previous;

    void setupUi(QDialog* TripDialog)
    {
        if (TripDialog->objectName().isEmpty())
            TripDialog->setObjectName("TripDialog");
        TripDialog->resize(603, 513);
        button_previous = new QPushButton(TripDialog);
        button_previous->setObjectName("button_previous");
        button_previous->setEnabled(false);
        button_previous->setGeometry(QRect(80, 440, 80, 18));
        button_next = new QPushButton(TripDialog);
        button_next->setObjectName("button_next");
        button_next->setGeometry(QRect(450, 440, 80, 18));
        label_collegeName = new QLabel(TripDialog);
        label_collegeName->setObjectName("label_collegeName");
        label_collegeName->setGeometry(QRect(40, 30, 521, 41));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setUnderline(true);
        label_collegeName->setFont(font);
        label_collegeName->setAlignment(Qt::AlignCenter);
        label_distance_next = new QLabel(TripDialog);
        label_distance_next->setObjectName("label_distance_next");
        label_distance_next->setGeometry(QRect(550, 410, 51, 21));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(false);
        label_distance_next->setFont(font1);
        label_distance_next->setAlignment(Qt::AlignCenter);
        label_next = new QLabel(TripDialog);
        label_next->setObjectName("label_next");
        label_next->setGeometry(QRect(400, 410, 151, 20));
        QFont font2;
        font2.setBold(true);
        font2.setUnderline(true);
        label_next->setFont(font2);
        label_next->setAlignment(Qt::AlignCenter);
        label_previous = new QLabel(TripDialog);
        label_previous->setObjectName("label_previous");
        label_previous->setGeometry(QRect(10, 410, 181, 20));
        label_previous->setFont(font2);
        label_previous->setAlignment(Qt::AlignCenter);
        label_distance_previous = new QLabel(TripDialog);
        label_distance_previous->setObjectName("label_distance_previous");
        label_distance_previous->setGeometry(QRect(190, 410, 61, 21));
        label_distance_previous->setFont(font1);
        label_distance_previous->setAlignment(Qt::AlignCenter);

        retranslateUi(TripDialog);

        QMetaObject::connectSlotsByName(TripDialog);
    } // setupUi

    void retranslateUi(QDialog* TripDialog)
    {
        TripDialog->setWindowTitle(QCoreApplication::translate("TripDialog", "Dialog", nullptr));
        button_previous->setText(QCoreApplication::translate("TripDialog", "Previous", nullptr));
        button_next->setText(QCoreApplication::translate("TripDialog", "Next", nullptr));
        label_collegeName->setText(QString());
        label_distance_next->setText(QString());
        label_next->setText(QCoreApplication::translate("TripDialog", "Distance To Next College:", nullptr));
        label_previous->setText(QCoreApplication::translate("TripDialog", "Distance From Previous College:", nullptr));
        label_distance_previous->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TripDialog : public Ui_TripDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPDIALOG_H
