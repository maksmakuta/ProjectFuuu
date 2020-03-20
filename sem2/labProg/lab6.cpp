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

int main(){
        TRAIN AVTOPARK[5] = {TRAIN("bidDAt",    7,  115,    11)
                            ,TRAIN("Goa",       8,  105,    12)
                            ,TRAIN("Rdg",     110,  125,    15)
                            ,TRAIN("CoolDay",  45,  125,    16)
                            ,TRAIN("x337",      1,  135,     9)
                            };
         int x;
cout << setw(10)<< "Name" << "|"<<setw(5)<< "Num" << "|" << setw(5)<< "Date" << "|" << setw(5)<< "Time" << endl;
                            for(int a = 0; a< 5; a++){
                                AVTOPARK[a].print();
                            }

                            cout << "Enter Date";
                            cin >> x;

                            for(int a = 0; a<= 5; a++){
                                    if(x >= AVTOPARK[a].getDate() && AVTOPARK[a].getTime() >= 15 )
                                        AVTOPARK[a].print();
                            }

    return 0;
}
