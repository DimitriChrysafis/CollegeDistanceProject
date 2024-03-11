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
#include "asudialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class represents the main window of the application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new MainWindow object.
     * @param parent Pointer to the parent widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the MainWindow object.
     */
    ~MainWindow();

    /**
     * @brief Displays information about the specified college in the UI.
     * @param college The College object to display information about.
     */
    void displayCollegeInfo(College college);

    /**
     * @brief Adds a college to the "Colleges" vector within MainWindow and updates the UI.
     * @param college The College object to add.
     */
    void addCollege(College college);

    /**
     * @brief Handles the login functionality.
     * Opens the login dialog and shows certain buttons if the login is successful.
     */
    void login();

    /**
     * @brief Handles the trip to University of California, Irvine (UCI).
     * Clears TripColleges vector, sets UCI as the starting college, and adds other colleges to the trip.
     */
    void tripUCI();

    /**
     * @brief Handles the trip to Arizona State University (ASU).
     * Clears TripColleges vector, sets ASU as the starting college, adds other colleges to the trip, and handles ASU-specific dialog.
     */
    void tripASU();

    /**
     * @brief Handles the trip to Saddleback College.
     * Clears TripColleges vector, sets Saddleback College as the starting college, and adds other colleges to the trip.
     */
    void tripSaddleback();

private slots:
    /**
     * @brief Converts CSV data to a QMap data structure.
     * @param path The path to the CSV file.
     * @param datagframe The data structure to store the CSV data.
     */
    void csv_to_df(std::string path, QMap<QString, QMap<QString, double>> &datagframe);

    /**
     * @brief Handles enabling/disabling certain buttons when a new college is clicked.
     * @param item The clicked QListWidgetItem.
     */
    void on_list_collegeNames_itemClicked(QListWidgetItem *item);

    /**
     * @brief Handles adding a souvenir to the current college.
     * Displays a dialog for adding a souvenir to the current college.
     */
    void on_button_addSouvenir_clicked();

    /**
     * @brief Handles editing a souvenir associated with the current college.
     * Retrieves the selected souvenir, displays a dialog for editing its details, and updates the souvenir information.
     */
    void on_button_editSouvenir_clicked();

    /**
     * @brief Handles enabling/disabling "edit" and "delete" buttons when a souvenir is clicked/unclicked.
     * @param currentText The text of the currently selected souvenir.
     */
    void on_list_souvenirs_currentTextChanged(const QString &currentText);

    /**
     * @brief Handles deleting a souvenir associated with the current college.
     * Removes the selected souvenir from the current college's souvenir list and updates the college information.
     */
    void on_button_deleteSouvenir_clicked();

    /**
     * @brief Handles adding or removing the currently selected college to/from the trip.
     * Updates the trip colleges list and recalculates the total distance of the trip.
     * @param checked A boolean indicating whether the college is added to (true) or removed from (false) the trip.
     */
    void on_button_addToTrip_clicked(bool checked);

    /**
     * @brief Handles marking the current college as the starting college for the trip.
     * Marks the current college as the starting point for the trip, adds it to the trip colleges list, and enables the "Go" button.
     */
    void on_button_startingCollege_clicked();

    /**
     * @brief Handles initiating the trip when the "Go" button is clicked.
     * Prepares necessary data for the trip and displays the trip dialog with relevant information.
     */
    void on_button_go_clicked();

    /**
     * @brief Finds the shortest path of colleges for the trip.
     * Calculates the most efficient path of colleges based on their distances.
     * @param location The starting location for finding the shortest path.
     * @param n The number of colleges to consider.
     * @param trip A pointer to the vector containing the colleges to be included in the trip.
     * @return A pointer to the vector containing the most efficient path of colleges.
     */
    QVector<College> *find_shortest_path(QString location, int n, QVector<College> *trip = nullptr);

private:
    Ui::MainWindow *ui; /**< The UI object pointer. */
    QVector<College> Colleges; /**< Vector to store College objects. */
    QVector<College> TripColleges; /**< Vector to store colleges included in the trip. */
    QVector<College> shortestPath; /**< Vector to store the shortest path of colleges for the trip. */
    College* currentCollege; /**< Pointer to the current College object. */
    SouvenirDialog* souvenirDialog; /**< Pointer to the SouvenirDialog object. */
    TripDialog* tripDialog; /**< Pointer to the TripDialog object. */
    LoginDialog* loginDialog; /**< Pointer to the LoginDialog object. */
    ASUDialog* asuDialog; /**< Pointer to the ASUDialog object. */
    QMap<QString, QMap<QString, double>> distanceMap; /**< QMap to store distances between colleges. */
    QMap<QString, QMap<QString, double>> souvenirMap; /**< QMap to store souvenir data. */
    QMenu *loginMenu; /**< Pointer to the login menu. */
    QMenu *presetsMenu; /**< Pointer to the presets menu. */
    QAction *loginAct; /**< Pointer to the login action. */
    QAction *UCITripAct; /**< Pointer to the UCI trip action. */
    QAction *ASUTripAct; /**< Pointer to the ASU trip action. */
    QAction *SaddlebackTripAct; /**< Pointer to the Saddleback trip action. */
};
#endif // MAINWINDOW_H
