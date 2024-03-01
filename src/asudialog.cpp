#include "asudialog.h"
#include "ui_asudialog.h"

ASUDialog::ASUDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ASUDialog)
{
    ui->setupUi(this);
}

ASUDialog::~ASUDialog()
{
    delete ui;
}

int ASUDialog::getNum() { return _num; }

bool ASUDialog::getOk() { return _ok; }

void ASUDialog::reset() { ui->box_number->setValue(1); }

void ASUDialog::on_button_ok_clicked()
{
    _num = ui->box_number->value();
    _ok = true;
    close();
}


void ASUDialog::on_button_cancel_clicked()
{
    _ok = false;
    close();
}

