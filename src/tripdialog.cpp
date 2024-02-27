#include "tripdialog.h"
#include "ui_tripdialog.h"

TripDialog::TripDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripDialog)
{
    ui->setupUi(this);

}

TripDialog::~TripDialog()
{
    delete ui;
}

void TripDialog::getColleges(QVector<College> vector)
{
    colleges = vector;
}

void TripDialog::display(int index)
{
    ui->label_collegeName->setText(colleges[index].name());
}


void TripDialog::on_button_next_clicked()
{
    index++;
    if (index == colleges.size() - 1) ui->button_next->setEnabled(false);
    display(index);
}

void TripDialog::on_button_previous_clicked()
{
    index--;
    if (index == 0) ui->button_previous->setEnabled(false);
    display(index);
}

