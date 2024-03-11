#include "logindialog.h"
#include "ui_logindialog.h"

/**
 * @brief Constructs a LoginDialog object.
 * @param parent Pointer to the parent widget.
 */
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

/**
 * @brief Destroys the LoginDialog object.
 */
LoginDialog::~LoginDialog()
{
    delete ui;
}

/**
 * @brief Gets the status of the OK button.
 * @return True if the OK button is clicked, otherwise false.
 */
bool LoginDialog::getOk() { return _ok; }

/**
 * @brief Gets the entered password.
 * @return The entered password.
 */
QString LoginDialog::getPassword() { return _password; }

/**
 * @brief Handles the click event of the Cancel button.
 * Closes the dialog without saving any changes.
 */
void LoginDialog::on_button_cancel_clicked()
{
    _ok = false;
    ui->line_password->clear();
    close();
}

/**
 * @brief Handles the click event of the OK button.
 * Saves the entered password and closes the dialog.
 */
void LoginDialog::on_button_ok_clicked()
{
    _password = ui->line_password->text();
    _ok = true;
    ui->line_password->clear();
    close();
}
