#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

 int data[3] = {50, 650,20};
  int money = 3000;

class priceList
{
public:
    vector<int> plist;

    bool isHave = false;

    priceList() {}

    void add(const int price)
    {
        plist.push_back(price);
    }

    void write()
    {
        for(auto x : plist)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    bool buy(int day){
        int & e = plist[day];
        money =- e;
        isHave = true;
        return true;
        }

    bool sell(int day){
        if(isHave){
        int & e = plist[day];
        money =+ e;
        isHave = false;
        return true;
        }else{
        cout << "You need to buy"<< endl;
        }
    }

    void gen(int minR, int maxR, int countR)
    {
        for(int a = 0; a < countR; a++)
        {
            int num = (rand() % (maxR - minR + 1)) + minR;
            add(num);
        }

    }

    void findMin()
    {
        cout <<*min_element(plist.begin(), plist.end());
    }
    void findMax()
    {
        cout <<*max_element(plist.begin(), plist.end()) ;

    }
    int findMinId()
    {
        int minElementIndex = std::min_element(plist.begin(),plist.end()) - plist.begin();
        return minElementIndex+1 ;
    }
    int findMaxId()
    {
        int maxElementIndex = std::max_element(plist.begin(),plist.end()) - plist.begin();
        return maxElementIndex+1 ;
    }
    bool verify()
    {

        if(findMinId() > findMaxId())
        {
            return true;
        }

        return false;
    }

};

int game()
{

int action = 0,day;
    srand(time(0)); //random seed
    priceList a;
    a.gen(data[0],data[1],data[2]);
    cout << "Price for 20 days:" << endl;
    a.write();

    cout << "Smallest price : ";
    a.findMin();
    cout << " ,day "
    << a.findMinId() << endl;

    cout << "Biggest price : ";
    a.findMax();
    cout << " ,day "
    << a.findMaxId() << endl;


    cout << endl <<
    "Choose you action:" << endl <<
    "1.Buy" << endl<<
    "2.Sell" << endl <<
    "3.Exit" << endl;

    cout << "Your money " << money<< endl;

    cin >> action;

    if(action == 1){
        action =0;
        cout << "You buy!!!" << endl;
        cout << "Enter day : " ;
        cin >> day;
        a.buy(day);

        game();

    }else if(action == 2){
        action =0;
        cout << "You sell!!!" << endl;
        cout << "Enter day : " ;
        cin >> day;
        a.sell(day);

        game();

    }else if (action == 3){
    return -1;
    }else if(action < 0 && action >= 4){
    game();
    }
}

int main(){
    srand(time(0)); //random seed
    priceList a;
    a.gen(data[0],data[1],data[2]);
    cout << "Price for 20 days:" << endl;
    a.write();

    cout << "Smallest price : ";
    a.findMin();
    cout << " ,day "
    << a.findMinId() << endl;

    cout << "Biggest price : ";
    a.findMax();
    cout << " ,day "
    << a.findMaxId() << endl;

return 0;
}
