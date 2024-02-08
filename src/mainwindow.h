#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVector>
#include <QMainWindow>
#include <QListWidgetItem>
#include "college.h"

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

private:
    Ui::MainWindow *ui;
    QVector<College> Colleges;
};
#endif // MAINWINDOW_H
