#include "college.h"

College::College(QString name): _name(name) {};
College::College(QString name, QMap<QString, double> souvenirList): _name(name), _souvenirList(souvenirList) {};

//Accessors
QString College::name() { return _name; }
QMap<QString, double> College::souvenirList() { return _souvenirList; }
double College::souvenirPrice(QString item) { return _souvenirList[item]; }
bool College::isInTrip() { return _isInTrip; }
bool College::isStartingCollege() { return _isStartingCollege; }

//Mutators
void College::addSouvenir(QString name, double price)
{
    _souvenirList[name] = price;
}

void College::removeSouvenir(QString name)
{
    _souvenirList.remove(name);
}

void College::toggleInTrip(bool inTrip)
{
    _isInTrip = inTrip;
}

void College::toggleIsStartingCollege(bool isStarting)
{
    _isStartingCollege = isStarting;
}
