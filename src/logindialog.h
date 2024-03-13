#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
    class LoginDialog;
}

/**
 * @brief The LoginDialog class represents a dialog window for user login.
 *
 * This dialog allows the user to input their password to authenticate.
 */
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new LoginDialog object.
     * @param parent Pointer to the parent widget.
     */
    explicit LoginDialog(QWidget *parent = nullptr);

    /**
     * @brief Destroys the LoginDialog object.
     */
    ~LoginDialog();

    /**
     * @brief Checks if the login process was successful.
     * @return True if the login was successful, otherwise false.
     */
    bool getOk();

    /**
     * @brief Gets the password entered by the user.
     * @return The password entered by the user.
     */
    QString getPassword();

private slots:
            /**
             * @brief Handles the click event of the Cancel button.
             *
             * Sets the login status to false, clears the password field, and closes the dialog.
             */
            void on_button_cancel_clicked();

    /**
     * @brief Handles the click event of the OK button.
     *
     * Retrieves the password entered by the user, sets the login status to true,
     * clears the password field, and closes the dialog.
     */
    void on_button_ok_clicked();

private:
    Ui::LoginDialog *ui; /**< UI object for LoginDialog. */
    QString _password; /**< The password entered by the user. */
    bool _ok = false; /**< Login status (true if successful, false otherwise). */
};

#endif // LOGINDIALOG_H
