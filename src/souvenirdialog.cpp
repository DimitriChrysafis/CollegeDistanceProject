#include "souvenirdialog.h"
#include "ui_souvenirdialog.h"

SouvenirDialog::SouvenirDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SouvenirDialog)
{
    ui->setupUi(this);
}

QString SouvenirDialog::getItem() { return _item; }
double SouvenirDialog::getPrice() { return _price; }
bool SouvenirDialog::getOk() { return _ok; }

SouvenirDialog::~SouvenirDialog()
{
    delete ui;
}

void SouvenirDialog::editSouvenir(QString name, double price)
{
    ui->lineEdit_item->setText(name);
    ui->lineEdit_price->setValue(price);
}

void SouvenirDialog::on_button_cancel_clicked()
{
    ui->lineEdit_item->clear();
    ui->lineEdit_price->clear();
    _ok = false;
    close();
}


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

