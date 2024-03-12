#include "mainwindow.h"
#include <QDir>
#include <QMapIterator>
#include <QString>
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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
    ui->button_addToTrip->hide();
    ui->button_addSouvenir->hide();
    ui->button_editSouvenir->hide();
    ui->button_deleteSouvenir->hide();

    //Add college logos to logoMap
    int w = ui->label_collegeLogo->width();
    int h = ui->label_collegeLogo->height();
    logoMap["Arizona State University"]
        = QPixmap(":/img/ASU.png").scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    logoMap["California State University, Fullerton"] = QPixmap(":/img/Cal State Fullerton.png")
                                                            .scaled(w,
                                                                    h,
                                                                    Qt::KeepAspectRatio,
                                                                    Qt::SmoothTransformation);
    logoMap["Massachusetts Institute of Technology (MIT)"]
        = QPixmap(":/img/MIT.png").scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    logoMap["Northwestern"] = QPixmap(":/img/Northwestern.png")
                                  .scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    logoMap["Ohio State University"] = QPixmap(":/img/Ohio State University.png")
                                           .scaled(w,
                                                   h,
                                                   Qt::KeepAspectRatio,
                                                   Qt::SmoothTransformation);
    logoMap["Saddleback College"] = QPixmap(":/img/Saddleback.png")
                                        .scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    logoMap["University of California, Irvine (UCI)"]
        = QPixmap(":/img/UCI.png").scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    logoMap["University of California, Los Angeles (UCLA)"]
        = QPixmap(":/img/UCLA.png").scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    logoMap["University of  Michigan"] = QPixmap(":/img/University of Michigan.png")
                                             .scaled(w,
                                                     h,
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation);
    logoMap["University of Oregon"] = QPixmap(":/img/University of Oregon.png")
                                          .scaled(w,
                                                  h,
                                                  Qt::KeepAspectRatio,
                                                  Qt::SmoothTransformation);
    logoMap["University of Texas"] = QPixmap(":/img/University of Texas.png")
                                         .scaled(w,
                                                 h,
                                                 Qt::KeepAspectRatio,
                                                 Qt::SmoothTransformation);
    logoMap["University of the Pacific"] = QPixmap(":/img/University of the Pacific.png")
                                               .scaled(w,
                                                       h,
                                                       Qt::KeepAspectRatio,
                                                       Qt::SmoothTransformation);
    logoMap["University of Wisconsin"] = QPixmap(":/img/University of Wisconsin.png")
                                             .scaled(w,
                                                     h,
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation);

    //Set up menu and actions----------------------------------------------------------------------------
    loginAct = new QAction("Login to Admin", this);
    UCITripAct = new QAction("Preset Trip from UCI", this);
    ASUTripAct = new QAction("Preset Trip from ASU", this);
    SaddlebackTripAct = new QAction("Preset Trip from Saddleback", this);
    SaveToCsv = new QAction("Save changes", this);
    // SaveCsv = new QA

    loginMenu = menuBar()->addMenu("&Login");
    loginMenu->addAction(loginAct);
    presetsMenu = menuBar()->addMenu("Select Preset Trip");
    presetsMenu->addAction(UCITripAct);
    presetsMenu->addAction(ASUTripAct);
    presetsMenu->addAction(SaddlebackTripAct);
    fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(SaveToCsv);
    connect(loginAct, &QAction::triggered, this, &MainWindow::login);
    connect(UCITripAct, &QAction::triggered, this, &MainWindow::tripUCI);
    connect(ASUTripAct, &QAction::triggered, this, &MainWindow::tripASU);
    connect(SaddlebackTripAct, &QAction::triggered, this, &MainWindow::tripSaddleback);
    connect(SaveToCsv, &QAction::triggered, this, &MainWindow::saveToCsv);

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
    cout << souvenirMap["Arizona State University"]["Football Jersey"] << endl;

    for (auto i = distanceMap.cbegin(); i != distanceMap.cend(); i++) {
        addCollege(College(i.key(), souvenirMap[i.key()]));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
            switch (count % 2) {
            case 0:
                row.assign(buffer);
                break;
            case 1:
                col.assign(buffer);
                break;
                // case 2:
                //     val.assign(buffer);
                //     // cout << row << " " << col << " " << val << endl;
                //     break;
            }
            count += 1;
            buffer.assign("");
        }

        else if (ch == '\n') {
            val.assign(buffer);
            buffer.assign("");
            // cout << row << " - " << col << " - " << val << endl;
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

void MainWindow::df_to_csv(string path,
                           QMap<QString, QMap<QString, double>> const dataframe,
                           QString label)
{
    ofstream csv;
    cout << path << endl;
    csv.open(path);

    if (!csv) {
        cout << "Could not open file! :(" << endl;
        return;
    }

    csv << label.toStdString() << "\n";

    for (auto i = dataframe.begin(); i != dataframe.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            bool flag = false;
            foreach (QChar c, i.key()) {
                if (c == ',') {
                    flag = true;
                }
            }

            if (flag) {
                csv << "\"" << i.key().toStdString() << "\""
                    << ",";
            } else {
                csv << i.key().toStdString() << ",";
            }

            flag = false;

            foreach (QChar c, j.key()) {
                if (c == ',') {
                    flag = true;
                }
            }

            if (flag)
                csv << "\"" << j.key().toStdString() << "\""
                    << ",";
            else
                csv << j.key().toStdString() << ",";

            csv << fixed << setprecision(2) << j.value() << "\n";
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
    if (!TripColleges.empty()) {
        ui->label_distanceFromSaddlebackPREFIX->setText(
            "Distance from " + TripColleges[0].name() + ": "
            + QString::number(distanceMap[college.name()][TripColleges[0].name()]));
    }

    while (it.hasNext()) {
        it.next();
        QString souvenir;
        souvenir = it.key() + " - $" + QString::number(it.value(), 'f', 2);
        ui->list_souvenirs->addItem(souvenir);
    }

    //Display college logo using its name
    ui->label_collegeLogo->setPixmap(logoMap[college.name()]);
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
    if (loginDialog->getOk() && loginDialog->getPassword() == "*Saddleback") {
        ui->button_addSouvenir->show();
        ui->button_editSouvenir->show();
        ui->button_deleteSouvenir->show();
    }
}

void MainWindow::tripUCI()
{
    TripColleges.clear();
    for (int i = 0; i < Colleges.length(); i++) {
        Colleges[i].toggleIsStartingCollege(false);
        if (Colleges[i].name() == "University of California, Irvine (UCI)") {
            currentCollege = &Colleges[i];
            on_button_startingCollege_clicked();
        }
    }

    for (int i = 0; i < Colleges.length(); i++) {
        currentCollege = &Colleges[i];
        if (!currentCollege->isStartingCollege()) {
            on_button_addToTrip_clicked(true);
        }
    }
    ui->list_collegeNames->clearSelection();
}

void MainWindow::tripASU()
{
    asuDialog->setMax(Colleges.length() - 1);
    asuDialog->exec();
    if (asuDialog->getOk()) {
        TripColleges.clear();
        for (int i = 0; i < Colleges.length(); i++) {
            Colleges[i].toggleIsStartingCollege(false);
            if (Colleges[i].name() == "Arizona State University") {
                currentCollege = &Colleges[i];
                on_button_startingCollege_clicked();
            }
        }

        for (int i = 0; i < Colleges.length(); i++) {
            currentCollege = &Colleges[i];
            if (!currentCollege->isStartingCollege()) {
                on_button_addToTrip_clicked(true);
            }
        }

        for (int i = 0; i < Colleges.length(); i++) {
            for (int x = TripColleges.length() - 1; x > asuDialog->getNum() - 1; x--) {
                if (Colleges[i].name() == TripColleges[x].name()) {
                    currentCollege = &Colleges[i];
                    on_button_addToTrip_clicked(false);
                }
            }
        }

        ui->list_collegeNames->clearSelection();
    }
    asuDialog->reset();
}

void MainWindow::tripSaddleback()
{
    TripColleges.clear();
    for (int i = 0; i < Colleges.length(); i++) {
        Colleges[i].toggleIsStartingCollege(false);
        if (Colleges[i].name() == "Saddleback College") {
            currentCollege = &Colleges[i];
            on_button_startingCollege_clicked();
        }
    }

    for (int i = 0; i < Colleges.length(); i++) {
        currentCollege = &Colleges[i];
        if (!currentCollege->isStartingCollege()) {
            on_button_addToTrip_clicked(true);
        }
    }
    ui->list_collegeNames->clearSelection();
}

void MainWindow::saveToCsv()
{
    cout << "AAAAAAAAA" << endl;
    QDir souvPath = QDir::current();
    cout << QDir::current().path().toStdString() << endl;
    souvPath.cdUp();
    // cout << souvPath.path().toStdString() << endl;
    string path = souvPath.path().toStdString()
                  + "/CollegeDistanceProject/College Campus Souvenirs.csv";
    // cout << "Path: " << path << endl;
    df_to_csv(path, souvenirMap, "College,Traditional Souvenirs,Cost");
}

//----------------------------Beginning of UI functions (go to slots)-------------------------------------------------

//Enable/disable certain buttons when a new college is clicked
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

//Enable/disable "edit" and "delete" buttons when a souvenir is clicked/unclicked
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

void MainWindow::on_button_addSouvenir_clicked()
{
    souvenirDialog->exec();
    if (souvenirDialog->getOk()) {
        currentCollege->addSouvenir(souvenirDialog->getItem(), souvenirDialog->getPrice());
        souvenirMap[currentCollege->name()][souvenirDialog->getItem()] = souvenirDialog->getPrice();
        displayCollegeInfo(*currentCollege);
    }
    if (souvenirDialog->getOk()) {
    }
}

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

//Add the currently selected college to the trip OR remove it. Also, update trip colleges label and total distance label.
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

void MainWindow::on_button_startingCollege_clicked()
{
    currentCollege->toggleIsStartingCollege(true);
    TripColleges.append(*currentCollege);
    ui->label_tripColleges->setText(currentCollege->name());
    ui->button_startingCollege->hide();
    ui->button_addToTrip->show();
    ui->button_go->setEnabled(true);
}

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

//Returns a pointer to a new vector containing a list of college objects ordered in the most efficient path
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

void MainWindow::on_button_reset_clicked()
{
    TripColleges.clear();
    for (int i = 0; i < Colleges.length(); i++) {
        Colleges[i].toggleIsStartingCollege(false);
        Colleges[i].toggleInTrip(false);
    }
    //currentCollege = nullptr;
    ui->button_addToTrip->setEnabled(false);
    ui->label_tripColleges->clear();
    ui->label_totalDistance->clear();
    ui->button_addToTrip->hide();
    ui->button_startingCollege->show();
    ui->button_go->setEnabled(false);
}
