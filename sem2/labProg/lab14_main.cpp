#include "Train.h"

using namespace std;

void header(){
cout << setw(10)<< "Name" << "|"<<setw(5)<< "Num" << "|" << setw(5)<< "Date" << "|" << setw(5)<< "Time" << endl;
}

int main()
{
    const int s = 5;
    TRAIN AVTOPARK[s] = {TRAIN("bidDAt",    7,  115,    11)
                        ,TRAIN("Goa",       8,  105,    12)
                        ,TRAIN("Rdg",     110,  125,    15)
                        ,TRAIN("CoolDay",  45,  125,    16)
                        ,TRAIN("x337",      1,  135,     9)};
    int x;
    header();
    for(int a = 0; a< s; a++){
        AVTOPARK[a].print();
    }

    cout << "Enter Date "; cin >> x;

    for(int a = 0; a<= s; a++){
            if( (int)AVTOPARK[a].getDate() <= x && (int)AVTOPARK[a].getTime() >= 14 )
                AVTOPARK[a].print();
    }

    return 0;
}
