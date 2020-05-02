#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class TRAIN{

private:
    string Nazv;
    int Numer;
    int Date;
    int Time;

public:
    TRAIN(string name, int num, int date, int time){
        this->Nazv = name;
        this->Date = date;
        this->Numer = num;
        this->Time = time;
    }

    int getDate(){return Date;}
    int getTime(){return Time;}

    void print(){
        cout << setw(10)<< Nazv << "|"<<setw(5)<< Numer << "|" << setw(5)<< Date << "|" << setw(5)<< Time << endl;
    }

};

#endif // TRAIN_H_INCLUDED
