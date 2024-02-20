#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVector>
#include <QMainWindow>
#include <QListWidgetItem>

#include "college.h"
#include "souvenirdialog.h"
#include "tripdialog.h"

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

private slots:
    void on_list_collegeNames_itemClicked(QListWidgetItem *item);

    void on_button_addSouvenir_clicked();

    void on_button_editSouvenir_clicked();

    void on_list_souvenirs_currentTextChanged(const QString &currentText);

    void on_button_deleteSouvenir_clicked();

    void on_button_addToTrip_clicked(bool checked);

    void on_button_startingCollege_clicked();

    void on_button_go_clicked();

private:
    Ui::MainWindow *ui;
    QVector<College> Colleges;
    QVector<College> TripColleges;
    College* currentCollege;
    SouvenirDialog* souvenirDialog;
    TripDialog* tripDialog;
};
#endif // MAINWINDOW_H
