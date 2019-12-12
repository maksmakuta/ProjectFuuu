#include <iostream>

using namespace std;

struct Ads
{

    long viewed, clicked;
    float avgPrice;

    void init()
    {
        cin >> viewed >> clicked >> avgPrice;
        getMoney(viewed,clicked,avgPrice);
    }

    void getMoney(int a, int b, float c)
    {
        cout <<  a*b*c << endl;
    }

};

int main()
{
    Ads a;
    a.init();
    return 0;
}
