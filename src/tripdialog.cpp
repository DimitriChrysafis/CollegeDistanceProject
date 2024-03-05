#include "tripdialog.h"
#include "ui_tripdialog.h"

TripDialog::TripDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TripDialog)
{
    ui->setupUi(this);

    collegeName = new QLabel();
    collegeName->setStyleSheet("font-weight: bold; font-size: 15pt; text-decoration: underline");
    QGridLayout* layout_ = new QGridLayout(this);
    storesHolder = new QStackedWidget(this);
    layout_->addWidget(collegeName, 0, 0, 1, 2, Qt::AlignCenter);
    layout_->addWidget(storesHolder, 1, 0, 1, 2, Qt::AlignCenter);
    layout_->addWidget(new QPushButton("mPrevious"), 2, 0, Qt::AlignLeft);
    layout_->addWidget(new QPushButton("mNext"), 2, 1, Qt::AlignLeft);
}

TripDialog::~TripDialog()
{
    delete ui;
}

void TripDialog::getColleges(QVector<College> vector)
{
    colleges = vector;
    //if (colleges.size() <= 1) {
        //ui->button_next->setEnabled(false);
    //} else {
        //ui->button_next->setEnabled(true);
    //}
}

void TripDialog::getDistances(QVector<int> vector)
{
    distances = vector;
}

void TripDialog::getSouvenirs(const QMap<QString, QMap<QString, double>>& souvenirs) {
  for(auto& college: colleges) {
    CampusStore* newStore = new CampusStore(college.name(), this);
    for(auto [key, value]: souvenirs[college.name()].asKeyValueRange()) {
      newStore->addItem(key, "", value);
    }
    storesHolder->addWidget(newStore);
  }
}

void TripDialog::displayName(int index)
{
    collegeName->setText(colleges[index].name());
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
    if (index == colleges.size())
    {
        ui->button_next->setText("Finish");
        collegeName->setText("End of the Trip!");
        ui->label_distance_next->setHidden(true);
        ui->label_distance_previous->setHidden(true);
        ui->label_next->setHidden(true);
        ui->label_previous->setHidden(true);
    }
    else if (index > colleges.size())
    {
        close();
    }
    else
    {
        displayName(index);
        displayPreviousDistance(index - 1);
        displayNextDistance(index);
    }
    ui->button_previous->setEnabled(true);

}

void TripDialog::on_button_previous_clicked()
{
    index--;
    if (index == 0)
        ui->button_previous->setEnabled(false);
    if (index < colleges.size())
    {
        ui->label_distance_next->setHidden(false);
        ui->label_distance_previous->setHidden(false);
        ui->label_next->setHidden(false);
        ui->label_previous->setHidden(false);
        ui->button_next->setText("Next");
    }
    displayName(index);
    displayPreviousDistance(index - 1);
    displayNextDistance(index);

    storesHolder->setCurrentIndex(index);
}

void TripDialog::reset()
{
    index = 0;
    ui->button_next->setText("Next");
    ui->button_next->setEnabled(true);
    ui->button_previous->setEnabled(false);
    ui->label_distance_next->setHidden(false);
    ui->label_distance_previous->setHidden(false);
    ui->label_next->setHidden(false);
    ui->label_previous->setHidden(false);
}
