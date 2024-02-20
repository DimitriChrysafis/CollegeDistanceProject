#include "mainwindow.h"

#include <fstream>
#include <QApplication>
#include <iostream>
#include <QDir>
#include <QString>
#include <string>
#include <cstring>

using namespace std;

//nested map datatype used for colleges. Use two subscripts to index two colleges and get their distance
typedef map<QString, map<QString, int>> dataframe;

dataframe df;    //Dataframe object containing colleges and their distances


//Accepts custom df datatype by reference and reads CSV data into it
void csvToDF(map<QString, map<QString, int>> &mp){
    QDir csvPath;
    csvPath.cdUp();
    // csvPath.cdUp();
    cout << csvPath.path().toStdString() << endl;

    ifstream csv(csvPath.path().toStdString() + "/CollegeDistanceProject/College Campus Distances and Souvenirs.csv");

    if(!csv){
        cout << "Could not open file! :(" << endl;
    }

    char buffer[128];
    while (csv.getline(buffer, 1024)){ //reads data into buffer
        //tokenize data with "," delimiter and add to df
        const char * row = strtok( buffer, ",");
        const char * col = strtok( NULL, ",");
        const char * val = strtok( NULL, ",");
        mp[QString::fromStdString(row)][QString::fromStdString(col)] = atoi(val);
    }
}


void findShortestPath(QString location, vector<QString> &trip, int n){
    if (n >= 1){
        int min = 100000;
        QString next;
        for (auto i = df[location].begin(); i != df[location].end(); i++){
            if (i->second < min && find(trip.begin(), trip.end(), i->first) == trip.end()){
                min = i->second;
                next = i->first;
            }
        }
        trip.push_back(next);
        cout << next.toStdString() << endl;
        findShortestPath(location, trip, n-1);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    csvToDF(df);


    vector<QString> trip;

    findShortestPath("Arizona State University", trip, df["Arizona State University"].size());

    for (int i = 0; i < trip.size(); i++){
        cout << i << ": " << trip[i].toStdString() << endl;
    }

    return a.exec();
}
