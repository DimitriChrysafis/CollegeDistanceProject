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
    if (colleges.size() <= 1) {
        ui->button_next->setEnabled(false);
    } else {
        ui->button_next->setEnabled(true);
    }
}

void TripDialog::getDistances(QVector<int> vector)
{
    distances = vector;
}

void TripDialog::displayName(int index)
{
    ui->label_collegeName->setText(colleges[index].name());
}

void TripDialog::displayPreviousDistance(int index)
{
    if (index >= 0 && index < distances.size())
        ui->label_distance_previous->setText(QString::number(distances[index]));
    else
        ui->label_distance_previous->setText("N/A");
}


void TripDialog::displayNextDistance(int index)
{
    if (index >= 0 && index < distances.size())
        ui->label_distance_next->setText(QString::number(distances[index]));
    else
        ui->label_distance_next->setText("N/A");
}

void TripDialog::on_button_next_clicked()
{
    index++;
    if (index == colleges.size() - 1)
        ui->button_next->setEnabled(false);
    if (index > 0)
        ui->button_previous->setEnabled(true);
    displayName(index);
    displayPreviousDistance(index - 1);
    displayNextDistance(index);
}

void TripDialog::on_button_previous_clicked()
{
    index--;
    if (index == 0)
        ui->button_previous->setEnabled(false);
    if (index < colleges.size() - 1)
        ui->button_next->setEnabled(true);
    displayName(index);
    displayPreviousDistance(index - 1);
    displayNextDistance(index);
}


