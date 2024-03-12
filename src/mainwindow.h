#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAction>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QPixmap>
#include <QVector>
#include <string>

#include "asudialog.h"
#include "college.h"
#include "logindialog.h"
#include "souvenirdialog.h"
#include "tripdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
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
    void tripUCI();
    void tripASU();
    void tripSaddleback();
    void saveToCsv();
    void loadCsv();

private slots:
    void csv_to_df(std::string path, QMap<QString, QMap<QString, double>> &datagframe);

    void df_to_csv(std::string path,
                   QMap<QString, QMap<QString, double>> const dataframe,
                   QString labels);

    void on_list_collegeNames_itemClicked(QListWidgetItem *item);

    void on_button_addSouvenir_clicked();

    void on_button_editSouvenir_clicked();

    void on_list_souvenirs_currentTextChanged(const QString &currentText);

    void on_button_deleteSouvenir_clicked();

    void on_button_addToTrip_clicked(bool checked);

    void on_button_startingCollege_clicked();

    void on_button_go_clicked();

    QVector<College> *find_shortest_path(QString location, int n, QVector<College> *trip = nullptr);

    void on_button_reset_clicked();

private:
    Ui::MainWindow *ui;
    QVector<College> Colleges;
    QVector<College> TripColleges;
    QVector<College> shortestPath;
    College *currentCollege;
    SouvenirDialog *souvenirDialog;
    TripDialog *tripDialog;
    LoginDialog *loginDialog;
    ASUDialog *asuDialog;
    QMap<QString, QMap<QString, double>> distanceMap;
    QMap<QString, QMap<QString, double>> souvenirMap;
    QMap<QString, QPixmap> logoMap;

    QMenu *loginMenu;
    QMenu *presetsMenu;
    QMenu *fileMenu;
    QAction *loginAct;
    QAction *UCITripAct;
    QAction *ASUTripAct;
    QAction *SaddlebackTripAct;
    QAction *SaveToCsv;
    QAction *LoadCsv;
};
#endif // MAINWINDOW_H
