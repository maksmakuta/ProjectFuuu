#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <sstream>

//3, 23

using namespace std;

struct Refrigerator{
    string name, city;
    int count,size,year,month,price;

    Refrigerator(){
        name   = "NoName";
        city   = "NoCity";
        count  = 0;
        size   = 0;
        year   = 0;
        month  = 0;
        price  = 0;
    }

    Refrigerator(string n,string c,int cn,int s, int y, int m,int p){
        name   = std::move(n);
        city   = std::move(c);
        count  = cn;
        size   = s;
        year   = y;
        month  = m;
        price  = p;
    }

    string toString() const {
        stringstream ss;
        ss << name << " " << city << " " << count<< " " << size << " "<< year << " " << month << " " << price << "\n";
        return ss.str();
    }
};
struct Item{
        string name,date;
        int count,price,dateP;

        Item(){
            name = "NoName";
            date = "NoDate";
            count = 0;
            price = 0;
            dateP = 0;
        }

        Item(string n, string d,int c,int p ,int q){
            name = std::move(n);
            date = std::move(d);
            count = c;
            price = p;
            dateP = q;
        }

        string toString() const {
            stringstream ss;
            ss << name << " " << count<< " " << date << " " << dateP << " " << price << "\n";
            return ss.str();
        }
};

void t23();
void t3();
bool f = true;
vector<Refrigerator> data;
vector<Item> data1;

void save(){
    ofstream of("data.txt");
    for(auto & a : data){
        of << a.toString();
    }
}
void add(){

    string name, city;
    int count,size,year,month,price;
    printf("==== ==== Add ==== ====\n");
    printf("Enter data\n");
    printf("Name\tCity\tCount\tSize\tYear\tMonth\tPrice\t\n");
    printf("str \tstr \t  int\t int\t int\t  int\t  int\t\n");
    cin >> name >> city >> count >> size >> year >> month >> price;
    Refrigerator it(name,city,count,size,year,month,price);
    data.push_back(it);
    printf("Data Saved\n");
    t3();
}
void removeItem(){
    int p;
    printf("Enter position to remove (from 0) "); cin >> p;
    data[p] = data[data.size()-1];
    data.erase(data.end());
    printf("Removed..\n");
    t3();
}
void print(){

    printf("Name City Count Size Year Month Price \n");
    for(auto & a : data){
        cout << a.toString();
    }
    t3();
}
void printSorted(){
    printf("Name City Count Size Year Month Price \n");
    for(auto & a : data){
     if(a.year > 2009) cout << a.toString();
    }
    t3();
}
void read(){
    ifstream ifs("data.txt");
    string name, city;
    int count,size,year,month,price;
    while (ifs >> name >> city >> count >> size >> year >> month >> price) {
        Refrigerator R(name, city, count, size, year, month, price);
        data.push_back(R);
    }
    f = false;
    t3();
}
void t3(){
    if(f) read();
    int action;
    printf("Main Menu: \n");
    printf("\t0. Exit\n");
    printf("\t1. Add\n");
    printf("\t2. Remove\n");
    printf("\t3. Print\n");
    printf("\t4. Print & sort\n");
    cin >> action;

    switch (action) {
        case 0:save();          break;
        case 1:add();           break;
        case 2:removeItem();    break;
        case 3:print();         break;
        case 4:printSorted();   break;
        default: t3();
    }
}

void qsave(){
    ofstream of("data1.txt");
    for(auto & a : data1){
        of << a.toString();
    }
}
void qadd(){

    string name,date;
    int count,price,dateP;
    printf("==== ==== Add ==== ====\n");
    printf("Enter data\n");
    printf("Name\tCount\tDate\tDateEnd\tPrice\t\n");
    printf("str \t  int\t str\t    int\t  int\t\n");
    cin >> name >> count >> date >> dateP >> price ;
    Item it(name,date,count,dateP,price);
    data1.push_back(it);
    printf("Data Saved\n");
    t23();
}
void qremoveItem(){
    int p;
    printf("Enter position to remove (from 0) "); cin >> p;
    data1[p] = data1[data1.size()-1];
    data1.erase(data1.end());
    printf("Removed..\n");
    t23();
}
void qprint(){
    printf("Name Count Date DateEnd Price\n");
    for(auto & a : data1){
        cout << a.toString();
    }
    t23();
}
void qprintSorted(){
    int p;
    printf("Enter min price "); cin >> p;
    printf("Name Count Date DateEnd Price\n");
    for(auto & a : data1){
        if(a.price > p) cout << a.toString();
    }
    t23();
}
void qread(){
    ifstream ifs("data1.txt");
    string name,date;
    int count,price,dateP;
    if(ifs.width() > 10){
        while (cin >> name >> count >> date >> dateP >> price){
            Item it(name,date,count,dateP,price);
            data1.push_back(it);
        }
    }
    f = false;
    t23();
}
void t23(){
    if(f) qread();
    int action;
    printf("Main Menu: \n");
    printf("\t0. Exit\n");
    printf("\t1. Add\n");
    printf("\t2. Remove\n");
    printf("\t3. Print\n");
    printf("\t4. Print & sort\n");
    cin >> action;

    switch (action) {
        case 0:qsave();          break;
        case 1:qadd();           break;
        case 2:qremoveItem();    break;
        case 3:qprint();         break;
        case 4:qprintSorted();   break;
        default: t23();
    }
}

int main() {
    t23();
    return 0;
}
