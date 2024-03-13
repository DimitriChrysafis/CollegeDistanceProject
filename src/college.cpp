#include "college.h"

/**
     * @brief Constructs a new College object with the given name.
     * @param name The name of the college.
     */
College::College(QString name)
    : _name(name){};

/**
     * @brief Constructs a new College object with the given name and souvenir list.
     * @param name The name of the college.
     * @param souvenirList The list of souvenirs available at the college.
     */
College::College(QString name, QMap<QString, double> souvenirList)
    : _name(name)
    , _souvenirList(souvenirList){};

//Accessors
/**
     * @brief Gets the name of the college.
     * @return The name of the college.
     */
QString College::name()
{
    return _name;
}

/**
     * @brief Gets the list of souvenirs available at the college.
     * @return The map of souvenir names to their prices.
     */
QMap<QString, double> College::souvenirList()
{
    return _souvenirList;
}

/**
     * @brief Gets the price of a specific souvenir at the college.
     * @param item The name of the souvenir.
     * @return The price of the souvenir.
     */
double College::souvenirPrice(QString item)
{
    return _souvenirList[item];
}

/**
     * @brief Checks if the college is included in the trip.
     * @return True if the college is included in the trip, otherwise false.
     */
bool College::isInTrip()
{
    return _isInTrip;
}

/**
     * @brief Checks if the college is the starting point of the trip.
     * @return True if the college is the starting point, otherwise false.
     */
bool College::isStartingCollege()
{
    return _isStartingCollege;
}

//Mutators
/**
     * @brief Adds a souvenir to the college's list.
     * @param name The name of the souvenir.
     * @param price The price of the souvenir.
     */
void College::addSouvenir(QString name, double price)
{
    _souvenirList[name] = price;
}

/**
     * @brief Removes a souvenir from the college's list.
     * @param name The name of the souvenir to remove.
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
     * @brief Toggles whether the college is the starting point of the trip.
     * @param isStarting True if the college is the starting point, false otherwise.
     */
void College::toggleIsStartingCollege(bool isStarting)
{
    _isStartingCollege = isStarting;
}
