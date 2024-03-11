#ifndef COLLEGE_H
#define COLLEGE_H

#include <QString>
#include <QMap>

/**
 * @brief The College class represents a college entity.
 *
 * This class contains a QString for the college's name and a QMap for its souvenirs.
 * Each element in the map consists of a QString for the souvenir name and a double for its price.
 */
class College
{
public:
    /**
     * @brief Constructs a College object with a specified name.
     * @param name The name of the college.
     */
    College(QString name);

    /**
     * @brief Constructs a College object with a specified name and a map of souvenirs.
     * @param name The name of the college.
     * @param souvenirList A QMap containing souvenirs and their prices.
     */
    College(QString name, QMap<QString, double> souvenirList);

    // Accessors

    /**
     * @brief Retrieves the name of the college.
     * @return The name of the college.
     */
    QString name();

    /**
     * @brief Retrieves the souvenir list of the college.
     * @return A QMap containing souvenirs and their prices.
     */
    QMap<QString, double> souvenirList();

    /**
     * @brief Retrieves the price of a specific souvenir.
     * @param item The name of the souvenir.
     * @return The price of the specified souvenir.
     */
    double souvenirPrice(QString item);

    /**
     * @brief Checks if the college is included in the trip.
     * @return True if the college is included in the trip, otherwise false.
     */
    bool isInTrip();

    /**
     * @brief Checks if the college is set as the starting point of the trip.
     * @return True if the college is the starting point, otherwise false.
     */
    bool isStartingCollege();

    // Mutators

    /**
     * @brief Adds a new souvenir to the college's souvenir list.
     * @param name The name of the souvenir to add.
     * @param price The price of the souvenir to add.
     */
    void addSouvenir(QString name, double price);

    /**
     * @brief Removes a souvenir from the college's souvenir list.
     * @param name The name of the souvenir to remove.
     */
    void removeSouvenir(QString name);

    /**
     * @brief Toggles the college's inclusion in the trip.
     * @param inTrip True to include the college in the trip, otherwise false.
     */
    void toggleInTrip(bool inTrip);

    /**
     * @brief Toggles the college's status as the starting point of the trip.
     * @param isStarting True to set the college as the starting point, otherwise false.
     */
    void toggleIsStartingCollege(bool isStarting);

private:
    QString _name; /**< The name of the college. */
    QMap<QString, double> _souvenirList; /**< A QMap containing souvenirs and their prices. */
    int _distance; /**< The distance of the college from a reference point. */
    bool _isInTrip = false; /**< Indicates whether the college is included in the trip. */
    bool _isStartingCollege = false; /**< Indicates whether the college is the starting point of the trip. */
};

#endif // COLLEGE_H
