#include <iostream>
using namespace std;
int h, m;
int addMin(int min){
m +=  min ;
if(m >= 60){
    m -= 60;
    h++;
}
}
int main()
{
    cout << "Enter time:" << endl;
    cin >> h >>  m ;
    //cout << h << ":" << m << endl;

    if(h >= 0 && h <= 24){
            if(m >= 0 && m <= 59){

                if(h >=7 && h <= 13 && m >= 0 && m <= 59 || h >= 15 && h <= 19 && m >= 0 && m <= 59  ){
                    cout << "v magazin";
                }else if(h >=8 && h <= 14 && m >= 0 && m <= 59 || h >= 16 && h <= 20 && m >= 0 && m <= 59){
                  addMin(20);
                    cout << "v gastronom";
                }else if(h >=8 && h <= 23 && m >= 0 && m <= 59){
                    addMin(45);
                    cout << "v supermarket";
                }else{
                    cout << "vdoma";
                }
        }
    }else{
    cout << "Enter correct time" << endl;
    }
    return 0;
}
