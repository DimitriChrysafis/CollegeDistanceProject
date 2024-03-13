#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

bool LoginDialog::getOk()
{
    return _ok;
}
QString LoginDialog::getPassword()
{
    return _password;
}

void LoginDialog::on_button_cancel_clicked()
{
    _ok = false;
    ui->line_password->clear();
    close();
}

void LoginDialog::on_button_ok_clicked()
{
    _password = ui->line_password->text();
    _ok = true;
    ui->line_password->clear();
    close();
}
