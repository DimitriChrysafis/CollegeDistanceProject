#ifndef TRIPDIALOG_H
#define TRIPDIALOG_H
#include <QAction>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QMainWindow>
#include <QVector>

#include "college.h"
//#include "souvenirdialog.h"
#include "storewidget.h"
#include <QDialog>

namespace Ui {
class TripDialog;
}

class TripDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TripDialog(QWidget *parent = nullptr);
    ~TripDialog();
    void getColleges(QVector<College> vector);
    void getDistances(QVector<int> vector);
    void getSouvenirs(const QMap<QString, QMap<QString, double>>&);
    void displayName(int index);
    void displayPreviousDistance(int index);
    void displayNextDistance(int index);
    void reset();

private slots:
    void on_button_next_clicked();
    void on_button_previous_clicked();

private:
    Ui::TripDialog *ui;
    int index = 0;
    QVector<College> colleges;
    QVector<int> distances;

    QLabel* collegeName;
    QStackedWidget* storesHolder;
};

#endif // TRIPDIALOG_H
