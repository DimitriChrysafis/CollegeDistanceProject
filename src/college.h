#ifndef COLLEGE_H
#define COLLEGE_H

#include <QMap>
#include <QString>

/**
 * @brief The College class represents a college in the college trip project.
 *
 * This class stores information about a college, including its name, list of souvenirs, and trip status.
 */
class College
{
public:
    /**
     * @brief Constructs a new College object with the given name.
     * @param name The name of the college.
     */
    College(QString name);

    /**
     * @brief Constructs a new College object with the given name and souvenir list.
     * @param name The name of the college.
     * @param souvenirList The list of souvenirs available at the college.
     */
    College(QString name, QMap<QString, double> souvenirList);

    // Accessors

    /**
     * @brief Gets the name of the college.
     * @return The name of the college.
     */
    QString name();

    /**
     * @brief Gets the list of souvenirs available at the college.
     * @return The map of souvenir names to their prices.
     */
    QMap<QString, double> souvenirList();

    /**
     * @brief Gets the price of a specific souvenir at the college.
     * @param item The name of the souvenir.
     * @return The price of the souvenir.
     */
    double souvenirPrice(QString item);

    /**
     * @brief Checks if the college is included in the trip.
     * @return True if the college is included in the trip, otherwise false.
     */
    bool isInTrip();

    /**
     * @brief Checks if the college is the starting point of the trip.
     * @return True if the college is the starting point, otherwise false.
     */
    bool isStartingCollege();

    // Mutators

    /**
     * @brief Adds a souvenir to the college's list.
     * @param name The name of the souvenir.
     * @param price The price of the souvenir.
     */
    void addSouvenir(QString name, double price);

    /**
     * @brief Removes a souvenir from the college's list.
     * @param name The name of the souvenir to remove.
     */
    void removeSouvenir(QString name);

    /**
     * @brief Toggles the inclusion of the college in the trip.
     * @param inTrip True to include the college in the trip, false otherwise.
     */
    void toggleInTrip(bool inTrip);

    /**
     * @brief Toggles whether the college is the starting point of the trip.
     * @param isStarting True if the college is the starting point, false otherwise.
     */
    void toggleIsStartingCollege(bool isStarting);

private:
    QString _name; /**< The name of the college. */
    QMap<QString, double> _souvenirList; /**< The list of souvenirs available at the college. */
    bool _isInTrip = false; /**< Indicates whether the college is included in the trip. */
    bool _isStartingCollege = false; /**< Indicates whether the college is the starting point of the trip. */
};

#endif // COLLEGE_H
