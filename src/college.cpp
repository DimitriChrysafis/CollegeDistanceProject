#include "college.h"

College::College(QString name): _name(name) {};
College::College(QString name, QMap<QString, double> souvenirList): _name(name), _souvenirList(souvenirList) {};
College::College(QString name, QMap<QString, double> souvenirList, int distance): _name(name), _souvenirList(souvenirList), _distance(distance) {};

//Accessors
QString College::name() { return _name; }
QMap<QString, double> College::souvenirList() { return _souvenirList; }
int College::distance() { return _distance; }

//Mutators
void College::addSouvenir(QString name, double price)
{
    _souvenirList[name] = price;
}
