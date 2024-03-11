#ifndef TRIPDIALOG_H
#define TRIPDIALOG_H

#include <QAction>
#include <QListWidgetItem>
#include <QStackedWidget>
#include <QMainWindow>
#include <QVector>

#include "college.h"
#include "storewidget.h"
#include <QDialog>

/**
 * @brief The TripDialog class represents a dialog window for managing a trip.
 */
class TripDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Constructs a new TripDialog object.
     * @param parent Pointer to the parent widget.
     */
    explicit TripDialog(QWidget *parent = nullptr);

    /**
     * @brief Destroys the TripDialog object.
     */
    ~TripDialog();

    /**
     * @brief Gets the colleges for the trip.
     * @param vector Vector of College objects.
     */
    void getColleges(QVector<College> vector);

    /**
     * @brief Gets the distances between colleges for the trip.
     * @param vector Vector of distances.
     */
    void getDistances(QVector<int> vector);

    /**
     * @brief Gets the souvenirs for the trip.
     * @param souvenirs Map of souvenirs with distances.
     */
    void getSouvenirs(const QMap<QString, QMap<QString, double>>& souvenirs);

    /**
     * @brief Displays the name of the current college.
     * @param index The index of the current college.
     */
    void displayName(int index);

    /**
     * @brief Displays the distance to the previous college.
     * @param index The index of the current college.
     */
    void displayPreviousDistance(int index);

    /**
     * @brief Displays the distance to the next college.
     * @param index The index of the current college.
     */
    void displayNextDistance(int index);

    /**
     * @brief Resets the trip dialog.
     */
    void reset();

private slots:
    /**
     * @brief Handles the click event of the "Next" button.
     */
    void on_button_next_clicked();

    /**
     * @brief Handles the click event of the "Previous" button.
     */
    void on_button_previous_clicked();

protected:
    /**
     * @brief Calculates and displays trip details.
     */
    void calculateTripDetails();

private:
    int index = 0; /**< The index of the current college. */
    QVector<College> colleges; /**< Vector of College objects for the trip. */
    QVector<int> distances; /**< Vector of distances between colleges. */
    QLabel* collegeName; /**< Label to display the name of the current college. */
    QStackedWidget* storesHolder; /**< Stacked widget for displaying store widgets. */
    QLabel* distToPrev; /**< Label to display the distance to the previous college. */
    QLabel* distToNext; /**< Label to display the distance to the next college. */
    QPushButton* previous; /**< Button to navigate to the previous college. */
    QPushButton* next; /**< Button to navigate to the next college. */
    QLabel* tripOverview; /**< Label to display trip overview information. */
};

#endif // TRIPDIALOG_H
