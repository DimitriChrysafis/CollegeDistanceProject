

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

/**
 * @brief The Ui_SouvenirDialog class manages the UI elements and setup methods for the SouvenirDialog.
 */
class Ui_SouvenirDialog
{
public:
    QPushButton *button_cancel; /**< Pointer to the Cancel button. */
    QPushButton *button_ok;     /**< Pointer to the Ok button. */
    QGroupBox *groupBox;        /**< Pointer to the group box. */
    QFormLayout *formLayout;    /**< Pointer to the form layout. */
    QLabel *label_item;         /**< Pointer to the label for the item. */
    QLineEdit *lineEdit_price;  /**< Pointer to the line edit for the price. */
    QLabel *label_price;        /**< Pointer to the label for the price. */
    QLineEdit *lineEdit_item;   /**< Pointer to the line edit for the item. */

    /**
     * @brief setupUi initializes the UI components for the SouvenirDialog.
     * @param SouvenirDialog Pointer to the SouvenirDialog object.
     */
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

    /**
     * @brief retranslateUi translates the UI components for the SouvenirDialog.
     * @param SouvenirDialog Pointer to the SouvenirDialog object.
     */
    void retranslateUi(QDialog *SouvenirDialog)
    {
        SouvenirDialog->setWindowTitle(
            QCoreApplication::translate("SouvenirDialog", "Dialog", nullptr));
        button_cancel->setText(QCoreApplication::translate("SouvenirDialog", "Cancel", nullptr));
        button_ok->setText(QCoreApplication::translate("SouvenirDialog", "Ok", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SouvenirDialog", "Souvenir", nullptr));
        label_item->setText(QCoreApplication::translate("SouvenirDialog", "Item", nullptr));
        label_price->setText(QCoreApplication::translate("SouvenirDialog", "Price", nullptr));
    } // retranslateUi
};

namespace Ui {
/**
     * @brief The SouvenirDialog class provides access to the UI elements and setup methods for the SouvenirDialog.
     */
class SouvenirDialog : public Ui_SouvenirDialog
{};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUVENIRDIALOG_H
