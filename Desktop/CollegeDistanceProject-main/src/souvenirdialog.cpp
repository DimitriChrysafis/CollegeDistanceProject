#include "souvenirdialog.h"
#include "ui_souvenirdialog.h"

/**
 * @brief Constructs a new SouvenirDialog object.
 * Initializes the SouvenirDialog with its UI components.
 * @param parent Pointer to the parent widget.
 */
SouvenirDialog::SouvenirDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SouvenirDialog)
{
    ui->setupUi(this);
}

/**
 * @brief Gets the name of the souvenir item.
 * @return The name of the souvenir item.
 */
QString SouvenirDialog::getItem() { return _item; }

/**
 * @brief Gets the price of the souvenir item.
 * @return The price of the souvenir item.
 */
double SouvenirDialog::getPrice() { return _price; }

/**
 * @brief Gets the status of the OK button.
 * @return True if the OK button is clicked, otherwise false.
 */
bool SouvenirDialog::getOk() { return _ok; }

/**
 * @brief Destroys the SouvenirDialog object.
 */
SouvenirDialog::~SouvenirDialog()
{
    delete ui;
}

/**
 * @brief Populates the dialog with the information of the souvenir to be edited.
 * @param name The name of the souvenir item.
 * @param price The price of the souvenir item.
 */
void SouvenirDialog::editSouvenir(QString name, double price)
{
    ui->lineEdit_item->setText(name);
    ui->lineEdit_price->setValue(price);
}

/**
 * @brief Handles the click event of the Cancel button.
 * Clears the input fields and sets the status to false.
 */
void SouvenirDialog::on_button_cancel_clicked()
{
    ui->lineEdit_item->clear();
    ui->lineEdit_price->clear();
    _ok = false;
    close();
}

/**
 * @brief Handles the click event of the OK button.
 * Validates the input, sets the souvenir information, and closes the dialog.
 */
void SouvenirDialog::on_button_ok_clicked()
{
    if (ui->lineEdit_item->text() == "")
    {
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
