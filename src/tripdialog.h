#ifndef TRIPDIALOG_H
#define TRIPDIALOG_H

#include <QAction>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QStackedWidget>
#include <QVector>

#include <QDialog>
#include "college.h"
#include "storewidget.h"

/**
 * @brief The TripDialog class provides a dialog for managing a trip itinerary.
 */
class TripDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new TripDialog object.
     * @param parent Pointer to the parent widget.
     */
    explicit TripDialog(QWidget *parent = nullptr);
    ~TripDialog();

    /**
     * @brief Receives college data.
     * @param vector Vector containing College objects.
     */
    void getColleges(QVector<College> vector);

    /**
     * @brief Receives distance data.
     * @param vector Vector containing distances.
     */
    void getDistances(QVector<int> vector);

    /**
     * @brief Receives souvenir data.
     * @param souvenirs Map containing souvenir information.
     */
    void getSouvenirs(const QMap<QString, QMap<QString, double>> &);

    /**
     * @brief Displays the name of the college.
     * @param index The index of the college.
     */
    void displayName(int index);

    /**
     * @brief Displays the distance from the previous college.
     * @param index The index of the college.
     */
    void displayPreviousDistance(int index);

    /**
     * @brief Displays the distance to the next college.
     * @param index The index of the college.
     */
    void displayNextDistance(int index);

    /**
     * @brief Resets the dialog to its initial state.
     */
    void reset();

private slots:
    /**
             * @brief Handles the "Next" button click.
             */
    void on_button_next_clicked();

    /**
     * @brief Handles the "Previous" button click.
     */
    void on_button_previous_clicked();

protected:
    /**
     * @brief Calculates and displays trip details.
     */
    void calculateTripDetails();

    /**
     * @brief Updates the cart total label.
     */
    void updateCartTotal();

    /**
     * @brief Handles the paint event.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent *event) override;

private:
    int index = 0;             /**< Index of the current college in the trip. */
    QVector<College> colleges; /**< Vector containing information about colleges in the trip. */
    QVector<int> distances;    /**< Vector containing distances between colleges. */

    QLabel *collegeName;          /**< Label for displaying the name of the college. */
    QStackedWidget *storesHolder; /**< Stacked widget for displaying stores at each college. */
    QLabel *distToPrev;           /**< Label for displaying distance from the previous college. */
    QLabel *distToNext;           /**< Label for displaying distance to the next college. */
    QLabel *cartTotal;            /**< Label for displaying the total cart amount. */
    QPushButton *previous;        /**< Button for navigating to the previous college. */
    QPushButton *next;            /**< Button for navigating to the next college. */
    QLabel *tripOverview;         /**< Label for displaying trip overview. */
};

#endif // TRIPDIALOG_H
