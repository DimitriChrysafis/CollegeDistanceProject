#include "logindialog.h"
#include "ui_logindialog.h"

/**
 * @brief Constructs a new LoginDialog object.
 *
 * Initializes the dialog with the provided parent widget.
 *
 * @param parent Pointer to the parent widget.
 */
LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

/**
 * @brief Destroys the LoginDialog object.
 *
 * Deletes the UI object associated with the dialog.
 */
LoginDialog::~LoginDialog()
{
    delete ui;
}

/**
 * @brief Checks if the login process was successful.
 * @return True if the login was successful, otherwise false.
 */
bool LoginDialog::getOk()
{
    return _ok;
}

/**
 * @brief Gets the password entered by the user.
 * @return The password entered by the user.
 */
QString LoginDialog::getPassword()
{
    return _password;
}

/**
 * @brief Handles the click event of the Cancel button.
 *
 * Sets the login status to false, clears the password field, and closes the dialog.
 */
void LoginDialog::on_button_cancel_clicked()
{
    _ok = false;
    ui->line_password->clear();
    close();
}

/**
 * @brief Handles the click event of the OK button.
 *
 * Retrieves the password entered by the user, sets the login status to true,
 * clears the password field, and closes the dialog.
 */
void LoginDialog::on_button_ok_clicked()
{
    _password = ui->line_password->text();
    _ok = true;
    ui->line_password->clear();
    close();
}
