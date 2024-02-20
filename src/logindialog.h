#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    bool getOk();
    QString getPassword();

private slots:
    void on_button_cancel_clicked();

    void on_button_ok_clicked();

private:
    Ui::LoginDialog *ui;

    QString _password;
    bool _ok;
};

#endif // LOGINDIALOG_H
