#include "asudialog.h"
#include "ui_asudialog.h"

/**
 * @brief Constructs a new ASUDialog object.
 * @param parent Pointer to the parent widget.
 */
ASUDialog::ASUDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ASUDialog)
{
    ui->setupUi(this);
}

/**
 * @brief Destroys the ASUDialog object.
 */
ASUDialog::~ASUDialog()
{
    delete ui;
}

/**
 * @brief Gets the number of colleges to visit.
 * @return The number of colleges to visit.
 */
int ASUDialog::getNum() { return _num; }

/**
 * @brief Gets the status of the OK button.
 * @return True if the OK button is clicked, otherwise false.
 */
bool ASUDialog::getOk() { return _ok; }

/**
 * @brief Sets the maximum number of colleges that can be input.
 * @param max The maximum number of colleges.
 */
void ASUDialog::setMax(int max) { ui->box_number->setMaximum(max); }

/**
 * @brief Resets the number of colleges to visit to the default value (1).
 */
void ASUDialog::reset() { ui->box_number->setValue(1); }

/**
 * @brief Handles the click event of the OK button.
 * Sets the number of colleges to visit and closes the dialog.
 */
void ASUDialog::on_button_ok_clicked()
{
    _num = ui->box_number->value();
    _ok = true;
    close();
}

/**
 * @brief Handles the click event of the Cancel button.
 * Closes the dialog without saving any changes.
 */
void ASUDialog::on_button_cancel_clicked()
{
    _ok = false;
    close();
}
