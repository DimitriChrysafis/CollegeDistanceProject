#include "mainwindow.h"

#include <fstream>
#include <QApplication>
#include <iostream>
#include <QString>
#include <string>
#include <cstring>

using namespace std;

//nested map datatype used for colleges. Use two subscripts to index two colleges and get their distance
typedef map<QString, map<QString, int>> dataframe;


//Accepts custom df datatype by reference and reads CSV data into it
void csvToDF(map<QString, map<QString, int>> &mp){
    ifstream csv("C:/Users/Rowan Speckman/Documents/Code/School/CS1D/CollegeDistanceProject/College Campus Distances and Souvenirs.csv");

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    dataframe df;    //Dataframe object containing colleges and their distances

    csvToDF(df);


    return a.exec();
}
