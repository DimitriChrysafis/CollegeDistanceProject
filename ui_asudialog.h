

#ifndef UI_ASUDIALOG_H
#define UI_ASUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

/**
 * @brief The Ui_ASUDialog class contains the UI elements and setup methods for the ASUDialog.
 */
class Ui_ASUDialog
{
public:
    QLabel *label_number; /**< Pointer to the label indicating the number of colleges to visit. */
    QSpinBox *box_number; /**< Pointer to the spin box for entering the number of colleges. */
    QPushButton *button_cancel; /**< Pointer to the Cancel button. */
    QPushButton *button_ok; /**< Pointer to the OK button. */

    /**
     * @brief setupUi initializes the UI components for the ASUDialog.
     * @param ASUDialog Pointer to the ASUDialog object.
     */
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

    /**
     * @brief retranslateUi translates the UI components for the ASUDialog.
     * @param ASUDialog Pointer to the ASUDialog object.
     */
    void retranslateUi(QDialog *ASUDialog)
    {
        ASUDialog->setWindowTitle(QCoreApplication::translate("ASUDialog", "Dialog", nullptr));
        label_number->setText(QCoreApplication::translate("ASUDialog", "Enter the number of colleges to visit:", nullptr));
        button_cancel->setText(QCoreApplication::translate("ASUDialog", "Cancel", nullptr));
        button_ok->setText(QCoreApplication::translate("ASUDialog", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
/**
     * @brief The ASUDialog class provides access to the UI elements and setup methods for the ASUDialog.
     */
class ASUDialog: public Ui_ASUDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASUDIALOG_H
// End of file

// /Users/dimitri.chrysafis/Repos/CollegeDistanceProject/ui_asudialog.h
