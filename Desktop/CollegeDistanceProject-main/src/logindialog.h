#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

/**
 * @brief The LoginDialog class provides a dialog for user login.
 */
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a LoginDialog object.
     * @param parent The parent widget (default is nullptr).
     */
    explicit LoginDialog(QWidget *parent = nullptr);

    /**
     * @brief Destructor for LoginDialog.
     */
    ~LoginDialog();

    /**
     * @brief Returns the status of the login operation.
     * @return True if the login was successful, false otherwise.
     */
    bool getOk();

    /**
     * @brief Returns the password entered by the user.
     * @return The password entered by the user.
     */
    QString getPassword();

private slots:
    /**
     * @brief Slot to handle the cancel button click event.
     */
    void on_button_cancel_clicked();

    /**
     * @brief Slot to handle the ok button click event.
     */
    void on_button_ok_clicked();

private:
    Ui::LoginDialog *ui; /**< Pointer to the UI object. */
    QString _password; /**< Stores the password entered by the user. */
    bool _ok; /**< Stores the status of the login operation. */
};

#endif // LOGINDIALOG_H
