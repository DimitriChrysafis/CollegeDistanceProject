/**
 * @file mainwindow.cpp
 * @brief Implementation of the MainWindow class
 */

#include "mainwindow.h"
#include <QDir>
#include <QMapIterator>
#include <QString>
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Constructor for the MainWindow class
 * @param parent The parent widget
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    souvenirDialog = new SouvenirDialog;
    tripDialog = new TripDialog;
    loginDialog = new LoginDialog;
    asuDialog = new ASUDialog;

    //Hide certain buttons until the user logs in or clicks on the first college-------------------------
    //ui->label_distanceFromSaddleback->hide();
    ui->button_addSouvenir->hide();
    ui->button_editSouvenir->hide();
    ui->button_deleteSouvenir->hide();

    //Set up menu and actions----------------------------------------------------------------------------
    loginAct = new QAction("Login to Admin", this);
    UCITripAct = new QAction("Preset Trip from UCI", this);
    ASUTripAct = new QAction("Preset Trip from ASU", this);
    SaddlebackTripAct = new QAction("Preset Trip from Saddleback", this);

    loginMenu = menuBar()->addMenu("&Login");
    loginMenu->addAction(loginAct);
    presetsMenu = menuBar()->addMenu("Select Preset Trip");
    presetsMenu->addAction(UCITripAct);
    presetsMenu->addAction(ASUTripAct);
    presetsMenu->addAction(SaddlebackTripAct);
    connect(loginAct, &QAction::triggered, this, &MainWindow::login);
    connect(UCITripAct, &QAction::triggered, this, &MainWindow::tripUCI);
    connect(ASUTripAct, &QAction::triggered, this, &MainWindow::tripASU);
    connect(SaddlebackTripAct, &QAction::triggered, this, &MainWindow::tripSaddleback);

    //Read CSV to data-------------------------------------------------------------------------------
    QDir distPath;
    distPath.cdUp();
    string path = distPath.path().toStdString()
                  + "/CollegeDistanceProject/College Campus Distances.csv";
    csv_to_df(path, distanceMap);

    QDir souvPath = QDir::current();
    cout << QDir::current().path().toStdString() << endl;
    souvPath.cdUp();
    cout << souvPath.path().toStdString() << endl;
    path = souvPath.path().toStdString() + "/CollegeDistanceProject/College Campus Souvenirs.csv";
    cout << "Path: " << path << endl;
    csv_to_df(path, souvenirMap);
    // cout << souvenirMap["Arizona State University"]["Football Jersey"] << endl;

    for (auto i = distanceMap.cbegin(); i != distanceMap.cend(); i++) {
        addCollege(College(i.key(), souvenirMap[i.key()]));
    }
}

/**
 * @brief Destructor for the MainWindow class
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Reads a CSV file and populates a data frame
 * @param path The path to the CSV file
 * @param dataframe The data frame to populate
 */
void MainWindow::csv_to_df(string path, QMap<QString, QMap<QString, double>> &dataframe)
{
    ifstream csv(path);

    if (!csv) {
        cout << "Could not open file! :(" << endl;
    }
    char ch;
    string buffer;
    unsigned quotes = 0, count = 0;
    string row, col, val;

    csv.ignore(1000, '\n');
    while ((ch = csv.get()) != EOF) {
        if (ch == ',' && quotes % 2 == 0) {
            switch (count % 3) {
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

        else {
            buffer += ch;
        }
    }
}

/**
 * @brief Displays college information within the UI
 * @param college The college object to display information for
 */
void MainWindow::displayCollegeInfo(College college)
{
    QMapIterator<QString, double> it(college.souvenirList());
    //Reset the souvenir list, so that any previous souvenirs are deleted
    ui->list_souvenirs->clear();

    ui->label_collegeName->setText(college.name());
    if (!TripColleges.empty()) {
        ui->label_distanceFromSaddlebackPREFIX->setText("Distance from " + TripColleges[0].name() + ": " +
            QString::number(distanceMap[college.name()][TripColleges[0].name()]));
    }

    while (it.hasNext()) {
        it.next();
        QString souvenir;
        souvenir = it.key() + " - $" + QString::number(it.value(), 'f', 2);
        ui->list_souvenirs->addItem(souvenir);
    }
}

/**
 * @brief Adds a college to the "Colleges" vector and the UI list
 * @param college The college object to add
 */
void MainWindow::addCollege(College college)
{
    Colleges.append(college);
    ui->list_collegeNames->addItem(college.name());
}

/**
 * @brief Displays the login dialog
 *
 * If the correct password is entered, it shows the buttons for adding,
 * editing, and deleting souvenirs.
 */
void MainWindow::login()
{
    loginDialog->exec();
    if (loginDialog->getOk() && loginDialog->getPassword() == "*Saddleback") {
        ui->button_addSouvenir->show();
        ui->button_editSouvenir->show();
        ui->button_deleteSouvenir->show();
    }
}

/**
 * @brief Handles the trip to University of California, Irvine (UCI).
 *
 * Clears TripColleges vector, sets UCI as the starting college,
 * and adds other colleges to the trip.
 */
void MainWindow::tripUCI()
{
    TripColleges.clear();
    for (int i = 0; i < Colleges.length(); i++)
    {
        Colleges[i].toggleIsStartingCollege(false);
        if (Colleges[i].name() == "University of California, Irvine (UCI)")
        {
            currentCollege = &Colleges[i];
            on_button_startingCollege_clicked();
        }
    }

    for (int i = 0; i < Colleges.length(); i++)
    {
        currentCollege = &Colleges[i];
        if (!currentCollege->isStartingCollege())
        {
            on_button_addToTrip_clicked(true);
        }
    }
    ui->list_collegeNames->clearSelection();
}

/**
 * @brief Handles the trip from Arizona State University (ASU).
 *
 * Sets ASU as the starting college, adds other colleges to the trip
 * based on the user-specified number, and removes excess colleges
 * from the trip.
 */
void MainWindow::tripASU()
{
    asuDialog->setMax(Colleges.length() - 1);
    asuDialog->exec();
    TripColleges.clear();
    for (int i = 0; i < Colleges.length(); i++)
    {
        Colleges[i].toggleIsStartingCollege(false);
        if (Colleges[i].name() == "Arizona State University")
        {
            currentCollege = &Colleges[i];
            on_button_startingCollege_clicked();
        }
    }

    for (int i = 0; i < Colleges.length(); i++)
    {
        currentCollege = &Colleges[i];
        if (!currentCollege->isStartingCollege())
        {
            on_button_addToTrip_clicked(true);
        }
    }

    for (int i = 0; i < Colleges.length(); i++)
    {
        for (int x = TripColleges.length() - 1; x > asuDialog->getNum(); x--)
        {
            if (Colleges[i].name() == TripColleges[x].name())
            {
                currentCollege = &Colleges[i];
                on_button_addToTrip_clicked(false);
            }
        }
    }

    ui->list_collegeNames->clearSelection();
    asuDialog->reset();
}

/**
 * @brief Handles the trip from Saddleback College.
 *
 * Clears TripColleges vector, sets Saddleback College as the starting college,
 * and adds other colleges to the trip.
 */
void MainWindow::tripSaddleback()
{
    TripColleges.clear();
    for (int i = 0; i < Colleges.length(); i++)
    {
        Colleges[i].toggleIsStartingCollege(false);
        if (Colleges[i].name() == "Saddleback College")
        {
            currentCollege = &Colleges[i];
            on_button_startingCollege_clicked();
        }
    }

    for (int i = 0; i < Colleges.length(); i++)
    {
        currentCollege = &Colleges[i];
        if (!currentCollege->isStartingCollege())
        {
            on_button_addToTrip_clicked(true);
        }
    }
    ui->list_collegeNames->clearSelection();
}

/**
 * @brief Slot function for handling item clicks in the college names list
 * @param item The clicked list widget item
 */
void MainWindow::on_list_collegeNames_itemClicked(QListWidgetItem *item)
{
    QString collegeName = item->text();

    for (int i = 0; i < Colleges.length(); i++) {
        if (collegeName == Colleges[i].name()) {
            displayCollegeInfo(Colleges[i]);
            currentCollege = &Colleges[i];
        }
    }

    ui->button_addSouvenir->setEnabled(true);
    ui->button_addToTrip->setChecked(currentCollege->isInTrip());
    ui->button_startingCollege->setEnabled(true);
    if (TripColleges.length() != 0 && !currentCollege->isStartingCollege())
        ui->button_addToTrip->setEnabled(true);
    else
        ui->button_addToTrip->setEnabled(false);
}

/**
 * @brief Slot function for handling changes in the selected souvenir item
 * @param currentText The current text of the selected souvenir item
 */
void MainWindow::on_list_souvenirs_currentTextChanged(const QString &currentText)
{
    if (currentText != "") {
        ui->button_editSouvenir->setEnabled(true);
        ui->button_deleteSouvenir->setEnabled(true);
    } else {
        ui->button_editSouvenir->setEnabled(false);
        ui->button_deleteSouvenir->setEnabled(false);
    }
}

/**
 * @brief Slot function for handling the "Add Souvenir" button click
 */
void MainWindow::on_button_addSouvenir_clicked()
{
    souvenirDialog->exec();
    if (souvenirDialog->getOk()) {
        currentCollege->addSouvenir(souvenirDialog->getItem(), souvenirDialog->getPrice());
        souvenirMap[currentCollege->name()][souvenirDialog->getItem()] = souvenirDialog->getPrice();
        displayCollegeInfo(*currentCollege);
    }
    if(souvenirDialog->getOk()) {
    }
}

/**
 * @brief Slot function for handling the "Edit Souvenir" button click
 */
void MainWindow::on_button_editSouvenir_clicked()
{
    QString key;
    QString souvenir;
    souvenir = ui->list_souvenirs->currentItem()->text();
    for (int i = 0; i < souvenir.length(); i++) {
        if (souvenir[i] != '-') {
            key.append(souvenir[i]);
        } else {
            key.chop(1);
            break;
        }
    }

    souvenirDialog->editSouvenir(key, currentCollege->souvenirPrice(key));
    souvenirDialog->exec();
    if (souvenirDialog->getOk()) {
        currentCollege->removeSouvenir(key);
        currentCollege->addSouvenir(souvenirDialog->getItem(), souvenirDialog->getPrice());

        auto iter = souvenirMap[currentCollege->name()].find(key);
        souvenirMap[currentCollege->name()].erase(iter);
        souvenirMap[currentCollege->name()][souvenirDialog->getItem()] = souvenirDialog->getPrice();

        displayCollegeInfo(*currentCollege);
    }
}

/**
 * @brief Slot function for handling the "Delete Souvenir" button click
 */
void MainWindow::on_button_deleteSouvenir_clicked()
{
    QString key;
    QString souvenir;
    souvenir = ui->list_souvenirs->currentItem()->text();
    for (int i = 0; i < souvenir.length(); i++) {
        if (souvenir[i] != '-') {
            key.append(souvenir[i]);
        } else {
            key.chop(1);
            break;
        }
    }

    currentCollege->removeSouvenir(key);
    auto iter = souvenirMap[currentCollege->name()].find(key);
    souvenirMap[currentCollege->name()].erase(iter);
    displayCollegeInfo(*currentCollege);
}
/**
 * @brief Slot function for handling the "Add to Trip" button click
 * @param checked Whether the button is checked or not
 */
void MainWindow::on_button_addToTrip_clicked(bool checked)
{
    QString text = "";
    currentCollege->toggleInTrip(checked);

    if (checked)
        TripColleges.append(*currentCollege);
    else {
        for (int i = 0; i < TripColleges.length(); i++) {
            if (TripColleges[i].name() == currentCollege->name()) {
                TripColleges.remove(i);
                break;
            }
        }
    }

    TripColleges = *find_shortest_path(TripColleges[0].name(), TripColleges.length());

    ui->label_tripColleges->clear();

    int totalDistance = 0;
    for (int i = 0; i < TripColleges.length() - 1; i++) {
        totalDistance += distanceMap[TripColleges[i].name()][TripColleges[i + 1].name()];
        text += TripColleges[i].name() + " > "
                + QString::number(distanceMap[TripColleges[i].name()][TripColleges[i + 1].name()])
                + "mi > ";
    }

    if (TripColleges.length() != 0)
        text += TripColleges[TripColleges.length() - 1].name();
    ui->label_tripColleges->setText(text);
    ui->label_totalDistance->setText("Total Distance: " + QString::number(totalDistance));
}

/**
 * @brief Slot function for handling the "Set Starting College" button click
 *
 * Sets the currently selected college as the starting college for the trip
 * and enables the "Go" button.
 */
void MainWindow::on_button_startingCollege_clicked()
{
    currentCollege->toggleIsStartingCollege(true);
    TripColleges.append(*currentCollege);
    ui->label_tripColleges->setText(currentCollege->name());
    ui->button_startingCollege->hide();
    ui->button_go->setEnabled(true);
}

/**
 * @brief Slot function for handling the "Go" button click
 *
 * Displays the TripDialog with the current trip details,
 * allowing the user to purchase souvenirs during the trip.
 */
void MainWindow::on_button_go_clicked()
{
    QVector<int> distances;
    for (int i = 0; i < TripColleges.size() - 1; i++) {
        distances.append(distanceMap[TripColleges[i].name()][TripColleges[i + 1].name()]);
    }
    tripDialog->getColleges(TripColleges);
    tripDialog->getDistances(distances);
    tripDialog->getSouvenirs(souvenirMap);
    tripDialog->displayName(0);
    tripDialog->displayNextDistance(0);
    tripDialog->displayPreviousDistance(-1);
    tripDialog->exec();
    tripDialog->reset();
}

/**
 * @brief Finds the shortest path between the given colleges
 * @param location The starting college for the path
 * @param n The number of colleges to visit
 * @param trip The vector to store the path (optional)
 * @return A pointer to a vector containing the ordered colleges in the shortest path
 */
QVector<College> *MainWindow::find_shortest_path(QString location, int n, QVector<College> *trip)
{
    if (trip == nullptr) {
        trip = new QVector<College>{};
    }
    trip->push_back(location);

    if (n > 1) {
        int min = 100000;
        QString next;
        for (auto i = TripColleges.begin(); i != TripColleges.end(); i++) {
            const auto eqCollegeName = [i](College &s) { return s.name() == i->name(); };
            if (distanceMap[location][i->name()] < min
                && std::find_if(trip->begin(), trip->end(), eqCollegeName) == trip->end()) {
                min = distanceMap[location][i->name()];
                next = i->name();
            }
        }
        // cout << next.toStdString() << endl;
        return find_shortest_path(next, n - 1, trip);
    } else {
        return trip;
    }
}
