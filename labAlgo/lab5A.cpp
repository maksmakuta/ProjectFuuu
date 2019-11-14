#include <iostream>
#include <vector>

using namespace std;

class realnum
{
public:

    int a,b;
    float amount;

    realnum()
    {
        this->a = 1;
        this->b = 1;
        this->amount = a/b;
    }

    realnum(const int a,const int b)
    {
        this->a = a;
        this->b = b;
        this->amount = a/b;
    }
    bool operator < (int a)
    {
        if(amount < a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator == ( realnum  x )
    {
        if(amount == x.getAmount())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    float getAmount()
    {
        return amount;
    }

    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }

    void writeF()
    {
        cout<< a<< endl << "-"<< endl << b << endl;
    }
};

class realArr
{
public:

    vector<realnum> arr;
    int aS = 0;

    realArr() {}
    realArr(realnum a)
    {
        addNum2Arr(a);
    }


    void addNum2Arr(realnum a)
    {
        arr.push_back(a);
        aS++;
    }

    void writeFList()
    {


        for(auto x : arr)
        {
            cout << x.getA() << " " ;
        }
        cout << endl;
        for(int a = 0; a < aS; a++)
        {
            cout <<  "-" << " ";
        }
        cout << endl;
        for(auto x : arr)
        {
            cout << x.getB() << " " ;
        }
        cout << endl;
    }

};


int main()
{
    realArr arr;
    for(int a = 1; a <= 7; a++)
    {
        for(int b = 1; b <= 7; b++)
        {
            if(realnum(a,b) < 1)
            {
                arr.addNum2Arr(realnum(a,b));

            }
        }
    }
    arr.writeFList();

    return 0;
}
