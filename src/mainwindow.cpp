#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMapIterator>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    souvenirDialog = new SouvenirDialog;

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

//Displays all college info within the UI, including name, distance from starting college, and all souvenirs.
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

//Adds the college to the "Colleges" vector within MainWindow. Also adds the college name to the UI.
void MainWindow::addCollege(College college)
{
    Colleges.append(college);
    ui->list_collegeNames->addItem(college.name());
}

//----------------------------Beginning of UI functions (go to slots)-------------------------------------------------

void MainWindow::on_list_collegeNames_itemClicked(QListWidgetItem *item)
{
    QString collegeName = item->text();

    for (int i = 0; i < Colleges.length(); i++)
    {
        if (collegeName == Colleges[i].name())
        {
            displayCollegeInfo(Colleges[i]);
            currentCollege = &Colleges[i];
        }
    }

    ui->button_addSouvenir->setEnabled(true);
    ui->button_addToTrip->setEnabled(true);
    ui->button_addToTrip->setChecked(currentCollege->isInTrip());
}

//Enable/disable "edit" and "delete" buttons when a souvenir is clicked/unclicked
void MainWindow::on_list_souvenirs_currentTextChanged(const QString &currentText)
{
    if (currentText != "")
    {
        ui->button_editSouvenir->setEnabled(true);
        ui->button_deleteSouvenir->setEnabled(true);
    }
    else
    {
        ui->button_editSouvenir->setEnabled(false);
        ui->button_deleteSouvenir->setEnabled(false);
    }
}

void MainWindow::on_button_addSouvenir_clicked()
{
    souvenirDialog->exec();
    if (souvenirDialog->getOk())
    {
        currentCollege->addSouvenir(souvenirDialog->getItem(), souvenirDialog->getPrice());
        displayCollegeInfo(*currentCollege);
    }
}


void MainWindow::on_button_editSouvenir_clicked()
{
    QString key;
    QString souvenir;
    souvenir = ui->list_souvenirs->currentItem()->text();
    for (int i = 0; i < souvenir.length(); i++)
    {
        if (souvenir[i] != "-")
        {
            key.append(souvenir[i]);
        }
        else
        {
            key.chop(1);
            break;
        }
    }

    souvenirDialog->editSouvenir(key, currentCollege->souvenirPrice(key));
    currentCollege->removeSouvenir(key);
    souvenirDialog->exec();
    if (souvenirDialog->getOk())
    {
        currentCollege->addSouvenir(souvenirDialog->getItem(), souvenirDialog->getPrice());
        displayCollegeInfo(*currentCollege);
    }
}



void MainWindow::on_button_deleteSouvenir_clicked()
{
    QString key;
    QString souvenir;
    souvenir = ui->list_souvenirs->currentItem()->text();
    for (int i = 0; i < souvenir.length(); i++)
    {
        if (souvenir[i] != "-")
        {
            key.append(souvenir[i]);
        }
        else
        {
            key.chop(1);
            break;
        }
    }

    currentCollege->removeSouvenir(key);
    displayCollegeInfo(*currentCollege);
}


void MainWindow::on_button_addToTrip_clicked(bool checked)
{
    QString text = "";
    currentCollege->toggleInTrip(checked);

    if (checked) TripColleges.append(*currentCollege);
    //else TripColleges.remove();

    ui->label_tripColleges->clear();

    for (int i = 0; i < TripColleges.length() - 1; i++)
    {
        text += TripColleges[i].name() + " > ";
    }
    text += TripColleges[TripColleges.length() - 1].name();
    ui->label_tripColleges->setText(text);
}

