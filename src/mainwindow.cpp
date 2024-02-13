#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMapIterator>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMap<QString, double> dummySouvenirList;
    dummySouvenirList["Shirt"] = 15.50;
    dummySouvenirList["Lanyard"] = 4.00;
    dummySouvenirList["Hoodie"] = 25.00;

    addCollege(College("Saddleback College", dummySouvenirList, 55));
    dummySouvenirList.remove("Shirt");
    dummySouvenirList.remove("Lanyard");
    dummySouvenirList["Water Flask"] = 8.25;
    addCollege(College("Arizona State University", dummySouvenirList, 166));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayCollegeInfo(College college)
{
    QMapIterator<QString, double> it(college.souvenirList());
    //Reset the souvenir list, so that any previous souvenirs are deleted
    ui->list_souvenirs->clear();

    ui->label_collegeName->setText(college.name());
    ui->label_distanceFromSaddleback->setText(QString::number(college.distance()));

    while (it.hasNext())
    {
        it.next();
        QString souvenir;
        souvenir = it.key() + " - $" + QString::number(it.value(), 'f', 2);
        ui->list_souvenirs->addItem(souvenir);
    }
}

void MainWindow::addCollege(College college)
{
    Colleges.append(college);
    ui->list_collegeNames->addItem(college.name());
}

void MainWindow::on_list_collegeNames_itemClicked(QListWidgetItem *item)
{
    QString collegeName = item->text();

    for (int i = 0; i < Colleges.length(); i++)
    {
        if (collegeName == Colleges[i].name()) { displayCollegeInfo(Colleges[i]); }
    }
}