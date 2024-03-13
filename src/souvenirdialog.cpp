#include "souvenirdialog.h"
#include "ui_souvenirdialog.h"

/**
 * @brief Constructs a new SouvenirDialog object.
 *
 * @param parent The parent widget.
 */
SouvenirDialog::SouvenirDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SouvenirDialog)
{
    ui->setupUi(this);
}

/**
 * @brief Destroys the SouvenirDialog object.
 */
SouvenirDialog::~SouvenirDialog()
{
    delete ui;
}

/**
 * @brief Gets the item name entered in the dialog.
 *
 * @return QString The item name.
 */
QString SouvenirDialog::getItem()
{
    return _item;
}

/**
 * @brief Gets the price entered in the dialog.
 *
 * @return double The price.
 */
double SouvenirDialog::getPrice()
{
    return _price;
}

/**
 * @brief Gets the status of the dialog (OK or not).
 *
 * @return true If the OK button was clicked.
 * @return false If the Cancel button was clicked.
 */
bool SouvenirDialog::getOk()
{
    return _ok;
}

/**
 * @brief Sets the item name and price for editing.
 *
 * @param name The item name.
 * @param price The price.
 */
void SouvenirDialog::editSouvenir(QString name, double price)
{
    ui->lineEdit_item->setText(name);
    ui->lineEdit_price->setValue(price);
}

/**
 * @brief Handles the Cancel button click event.
 */
void SouvenirDialog::on_button_cancel_clicked()
{
    ui->lineEdit_item->clear();
    ui->lineEdit_price->clear();
    _ok = false;
    close();
}

/**
 * @brief Handles the OK button click event.
 *
 * Validates input and sets the item name and price.
 */
void SouvenirDialog::on_button_ok_clicked()
{
    if (ui->lineEdit_item->text() == "") {
        QMessageBox::warning(this, "Error", "Item must have a name.");
        return;
    }

    _item = ui->lineEdit_item->text();
    _price = ui->lineEdit_price->text().toDouble();
    ui->lineEdit_item->clear();
    ui->lineEdit_price->clear();

    _ok = true;
    close();
}
