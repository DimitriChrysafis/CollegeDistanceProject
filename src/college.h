#ifndef COLLEGE_H
#define COLLEGE_H
#include <QString>
#include <QMap>

/*---------
College class. Contains a QString for its name and a QMap for all its souvenirs.
Each element in the map contains a QString for the souvenir name and a double for its price.
----------*/
class College
{
public:

    College(QString name);
    College(QString name, QMap<QString, double> souvenirList);
    College(QString name, QMap<QString, double> souvenirList, int distance);

    //Accessors
    QString name();
    int distance();
    QMap<QString, double> souvenirList();
    double souvenirPrice(QString item);
    bool isInTrip();

    //Mutators
    void addSouvenir(QString name, double price);
    void removeSouvenir(QString name);
    void toggleInTrip(bool inTrip);

private:
    QString _name;
    QMap<QString, double> _souvenirList;
    int _distance;
    bool _isInTrip = false;
};

#endif // COLLEGE_H
