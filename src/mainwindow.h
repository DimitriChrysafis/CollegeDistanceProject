#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVector>
#include <QMainWindow>
#include <QListWidgetItem>
#include <QAction>
#include <string>

#include "college.h"
#include "souvenirdialog.h"
#include "tripdialog.h"
#include "logindialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayCollegeInfo(College college);
    void addCollege(College college);
    void login();

private slots:
    void csv_to_df(std::string path, std::map<QString, std::map<QString, float>> &datagframe);

    void on_list_collegeNames_itemClicked(QListWidgetItem *item);

    void on_button_addSouvenir_clicked();

    void on_button_editSouvenir_clicked();

    void on_list_souvenirs_currentTextChanged(const QString &currentText);

    void on_button_deleteSouvenir_clicked();

    void on_button_addToTrip_clicked(bool checked);

    void on_button_startingCollege_clicked();

    void on_button_go_clicked();

    QVector<College> *find_shortest_path(QString location, int n, QVector<College> *trip = nullptr);

private:
    Ui::MainWindow *ui;
    QVector<College> Colleges;
    QVector<College> TripColleges;
    QVector<College> shortestPath;
    College* currentCollege;
    SouvenirDialog* souvenirDialog;
    TripDialog* tripDialog;
    LoginDialog* loginDialog;
    std::map<QString, std::map<QString, float>> distanceMap;
    std::map<QString, std::map<QString, float>> souvenirMap;

    QMenu *loginMenu;
    QMenu *presetsMenu;
    QAction *loginAct;
    QAction *UCITripAct;
    QAction *ASUTripAct;
};
#endif // MAINWINDOW_H
