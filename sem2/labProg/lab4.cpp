#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Date
{
    int y, m, d;
};
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int countLeapYears(Date d)
{
    int years = d.y;
    if (d.m <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2) // calc number of days from 2000.01.01
{
    long int n1 = dt1.y*365 + dt1.d;
    for (int i=0; i<dt1.m - 1; i++)
        n1 += monthDays[i];
    n1 += countLeapYears(dt1);

    long int n2 = dt2.y*365 + dt2.d;
    for (int i=0; i<dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    return (n2 - n1);
}

class Shop{
private:
    int price, endDate;

public:
    Shop(int p, int d){
        this->endDate = d;
        this->price = p;
    }

    Shop(Shop &s){
        this->endDate = s.getEndDate();
        this->price = s.getPrice();
    }

    int getPrice(){return price;}
    int getEndDate(){return endDate;}

    void setPrice(int p){
        this->price = p;
    }

    void setEndDate(int d){
        this->endDate = d;
    }

    void Sale(int today){
int newPrice = getPrice() - getPrice()*0.15f;
        if(today < getEndDate()){
            cout <<setw(5) << newPrice <<"\t    Pridatniy "<< endl;
        }else{
            cout <<setw(5) << newPrice <<"\t Ne Pridatniy "<< endl;
        }

    }

};
int main()
{
    Shop sa(150,  6500);
    Shop sb(130,  7200);
    Shop sc(180,  8600);
    Shop sd(230,  6550);
    Shop se(10,   7652);
    Shop sf(960,  7537);
    Shop sg(1650, 5573);
    Shop sh(3000, 7667);
    Shop si(350,  6012);
    Shop sl(600,  5224);

    Shop z[10] = {sa,sb,sc,sd,se,sf,sg,sh,si,sl};
    int y,m,d;
    cout << "Enter today date:(yyyy mm dd) ";
    cin >> y>> m>> d;
    Date e = {y,m,d};
    Date i = {2000,1,1};

    for(int a = 0; a < 10;a++){
        z[a].Sale(getDifference(i,e));
    }
    return 0;
}
