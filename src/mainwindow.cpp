#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMapIterator>
#include <iostream>
#include <QString>
#include <QDir>
#include <QString>
#include <string>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    souvenirDialog = new SouvenirDialog;
    tripDialog = new TripDialog;
    loginDialog = new LoginDialog;

    //Hide certain buttons until the user logs in or clicks on the first college-------------------------
    ui->label_distanceFromSaddleback->hide();
    ui->button_addSouvenir->hide();
    ui->button_editSouvenir->hide();
    ui->button_deleteSouvenir->hide();

    //Set up menu and actions----------------------------------------------------------------------------
    loginAct = new QAction("Login to Admin", this);
    UCITripAct = new QAction("Preset Trip from UCI", this);
    ASUTripAct = new QAction("Preset Trip from ASU", this);

    loginMenu = menuBar()->addMenu("&Login");
    loginMenu->addAction(loginAct);
    presetsMenu = menuBar()->addMenu("Select Preset Trip");
    presetsMenu->addAction(UCITripAct);
    presetsMenu->addAction(ASUTripAct);
    connect(loginAct, &QAction::triggered, this, &MainWindow::login);

    //Add dummy test colleges-----------------------------------------------------------------------------
    // QMap<QString, double> dummySouvenirList;
    // dummySouvenirList["Shirt"] = 15.50;
    // dummySouvenirList["Lanyard"] = 4.00;
    // dummySouvenirList["Hoodie"] = 25.00;

    // addCollege(College("Saddleback College", dummySouvenirList));
    // dummySouvenirList.remove("Shirt");
    // dummySouvenirList.remove("Lanyard");
    // dummySouvenirList["Water Flask"] = 8.25;
    // addCollege(College("Arizona State University", dummySouvenirList));

    // dummySouvenirList["Sweater"] = 18.00;
    // addCollege(College("University of California, Irvine (UCI)", dummySouvenirList));

    //Read CSV to data-------------------------------------------------------------------------------
    QDir distPath;
    distPath.cdUp();
    string path = distPath.path().toStdString() + "/CollegeDistanceProject/College Campus Distances.csv";
    csv_to_df(path, distanceMap);

    QDir souvPath = QDir::current();
    cout << QDir::current().path().toStdString() << endl;
    souvPath.cdUp();
    cout << souvPath.path().toStdString() << endl;
    path = souvPath.path().toStdString() + "/CollegeDistanceProject/College Campus Souvenirs.csv";
    cout << "Path: " << path << endl;
    csv_to_df(path, souvenirMap);
    // cout << souvenirMap["Arizona State University"]["Football Jersey"] << endl;

    for (auto i = distanceMap.cbegin(); i != distanceMap.cend(); i++){
        addCollege(College(i.key(), souvenirMap[i.key()]));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::csv_to_df(string path, QMap<QString, QMap<QString, double>> &dataframe){
    ifstream csv(path);

    if(!csv){
        cout << "Could not open file! :(" << endl;
    }
    char ch;
    string buffer;
    unsigned quotes = 0, count = 0;
    string row, col, val;

    csv.ignore(1000, '\n');
    while((ch = csv.get()) != EOF){
        if (ch == ',' && quotes % 2 == 0) {
            switch(count%3){
            case 0:
                row.assign(buffer);
                break;
            case 1:
                col.assign(buffer);
                break;
            case 2:
                val.assign(buffer);
                // cout << row << " " << col << " " << val << endl;
                break;
            }
            count += 1;
            buffer.assign("");
        }

        else if (ch == '\n') {
            // cout << row << " " << col << " " << val << endl;
            dataframe[QString::fromStdString(row)][QString::fromStdString(col)] = std::stof(val);
        }

        else if (ch == '\"') {
            quotes += 1;
        }

        else{
            buffer += ch;
        }
    }
}

//Displays all college info within the UI, including name, distance from starting college, and all souvenirs.
void MainWindow::displayCollegeInfo(College college)
{
    QMapIterator<QString, double> it(college.souvenirList());
    //Reset the souvenir list, so that any previous souvenirs are deleted
    ui->list_souvenirs->clear();

    ui->label_collegeName->setText(college.name());
    if (!TripColleges.empty()){
        ui->label_distanceFromSaddleback->setText(QString::number(distanceMap[college.name()][TripColleges[0].name()]));
    }

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

void MainWindow::login()
{
    loginDialog->exec();
    if (loginDialog->getOk() && loginDialog->getPassword() == "Test")
    {
        ui->button_addSouvenir->show();
        ui->button_editSouvenir->show();
        ui->button_deleteSouvenir->show();
    }
}

//----------------------------Beginning of UI functions (go to slots)-------------------------------------------------

//Enable/disable certain buttons when a new college is clicked
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
    ui->button_addToTrip->setChecked(currentCollege->isInTrip());
    ui->button_startingCollege->setEnabled(true);
    if (TripColleges.length() != 0 && !currentCollege->isStartingCollege()) ui->button_addToTrip->setEnabled(true);
    else ui->button_addToTrip->setEnabled(false);
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
        if (souvenir[i] != '-')
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
    souvenirDialog->exec();
    if (souvenirDialog->getOk())
    {
        currentCollege->removeSouvenir(key);
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
        if (souvenir[i] != '-')
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
    else
    {
        for (int i = 0; i < TripColleges.length(); i++)
        {
            if (TripColleges[i].name() == currentCollege->name())
            {
                TripColleges.remove(i);
                break;
            }
        }
    }

    TripColleges = *find_shortest_path(TripColleges[0].name(), TripColleges.length());

    ui->label_tripColleges->clear();

    int totalDistance = 0;
    for (int i = 0; i < TripColleges.length() - 1; i++)
    {
        totalDistance += distanceMap[TripColleges[i].name()][TripColleges[i+1].name()];
        text += TripColleges[i].name() +
                " > " +
                QString::number(distanceMap[TripColleges[i].name()][TripColleges[i+1].name()]) +
                "mi > ";
    }

    if (TripColleges.length() != 0) text += TripColleges[TripColleges.length() - 1].name(); //+
                                            " -- Total Distance: " + QString::number(totalDistance);
    ui->label_tripColleges->setText(text);
    ui->label_totalDistance->setText("Total Distance: " + QString::number(totalDistance));
}

void MainWindow::on_button_startingCollege_clicked()
{
    TripColleges.append(*currentCollege);
    ui->label_tripColleges->setText(currentCollege->name());
    ui->button_startingCollege->hide();
    currentCollege->toggleIsStartingCollege(true);
    ui->button_go->setEnabled(true);
    ui->label_distanceFromSaddleback->show();
    ui->label_distanceFromSaddlebackPREFIX->setText("Distance From " + currentCollege->name() + ":");
}

void MainWindow::on_button_go_clicked()
{
    QVector<int> distances;
    for (int i = 0; i < TripColleges.size() - 1; i++)
    {
        distances.append(distanceMap[TripColleges[i].name()][TripColleges[i + 1].name()]);
    }
    tripDialog->getColleges(TripColleges);
    tripDialog->getDistances(distances);
    tripDialog->displayName(0);
    tripDialog->displayNextDistance(0);
    tripDialog->displayPreviousDistance(-1);
    tripDialog->exec();
}

//Returns a pointer to a new vector containing a list of college objects ordered in the most efficient path
QVector<College> *MainWindow::find_shortest_path(QString location, int n, QVector<College> *trip)
{
    if (trip == nullptr){
        trip = new QVector<College> {};
    }
    trip->push_back(location);

    if (n > 1){
        int min = 100000;
        QString next;
        for (auto i = TripColleges.begin(); i != TripColleges.end(); i++){
            const auto eqCollegeName = [i] ( College& s ) { return s.name() == i->name() ; };
            if (distanceMap[location][i->name()] < min && std::find_if(trip->begin(), trip->end(), eqCollegeName) == trip->end()){
                min = distanceMap[location][i->name()];
                next = i->name();
            }
        }
        // cout << next.toStdString() << endl;
        return find_shortest_path(next, n-1, trip);
    }
    else{
        return trip;
    }
}


