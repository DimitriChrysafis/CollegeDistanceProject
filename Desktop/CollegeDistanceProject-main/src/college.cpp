#include "college.h"

/**
 * @brief Constructs a College object with the given name.
 * @param name The name of the college.
 */
College::College(QString name) : _name(name) {}

/**
 * @brief Constructs a College object with the given name and souvenir list.
 * @param name The name of the college.
 * @param souvenirList A QMap containing souvenir items and their prices.
 */
College::College(QString name, QMap<QString, double> souvenirList) : _name(name), _souvenirList(souvenirList) {}


/**
 * @brief Gets the name of the college.
 * @return The name of the college.
 */
QString College::name() { return _name; }

/**
 * @brief Gets the souvenir list of the college.
 * @return A QMap containing souvenir items and their prices.
 */
QMap<QString, double> College::souvenirList() { return _souvenirList; }

/**
 * @brief Gets the price of a specific souvenir item.
 * @param item The name of the souvenir item.
 * @return The price of the souvenir item.
 */
double College::souvenirPrice(QString item) { return _souvenirList[item]; }

/**
 * @brief Checks if the college is included in the trip.
 * @return True if the college is included in the trip, otherwise false.
 */
bool College::isInTrip() { return _isInTrip; }

/**
 * @brief Checks if the college is set as the starting point of the trip.
 * @return True if the college is the starting point, otherwise false.
 */
bool College::isStartingCollege() { return _isStartingCollege; }

// Mutators

/**
 * @brief Adds a new souvenir item to the college's souvenir list.
 * @param name The name of the souvenir item.
 * @param price The price of the souvenir item.
 */
void College::addSouvenir(QString name, double price)
{
    _souvenirList[name] = price;
}

/**
 * @brief Removes a souvenir item from the college's souvenir list.
 * @param name The name of the souvenir item to be removed.
 */
void College::removeSouvenir(QString name)
{
    _souvenirList.remove(name);
}

/**
 * @brief Toggles the inclusion of the college in the trip.
 * @param inTrip True to include the college in the trip, false otherwise.
 */
void College::toggleInTrip(bool inTrip)
{
    _isInTrip = inTrip;
}

/**
 * @brief Toggles the status of the college as the starting point of the trip.
 * @param isStarting True to set the college as the starting point, false otherwise.
 */
void College::toggleIsStartingCollege(bool isStarting)
{
    _isStartingCollege = isStarting;
}
