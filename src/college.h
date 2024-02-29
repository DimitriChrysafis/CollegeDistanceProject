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

    //Accessors
    QString name();
    QMap<QString, double> souvenirList();
    double souvenirPrice(QString item);
    bool isInTrip();
    bool isStartingCollege();

    //Mutators
    void addSouvenir(QString name, double price);
    void removeSouvenir(QString name);
    void toggleInTrip(bool inTrip);
    void toggleIsStartingCollege(bool isStarting);

private:
    QString _name;
    QMap<QString, double> _souvenirList;
    int _distance;
    bool _isInTrip = false;
    bool _isStartingCollege = false;
};

#endif // COLLEGE_H
