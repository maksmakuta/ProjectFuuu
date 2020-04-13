#include <iostream>

using namespace std;

class B1
{
private:
    int a;
public:
    B1(int integer)
    {
        this->a = integer;
    }

    int getA()
    {
        return a;
    }

    void setA(int x)
    {
        this->a = x;
    }

    void infoB1()
    {
        cout << "a= "<< a<< endl;
    }

};

class D1:public B1{
private:
    int bInt;
public:
    D1(int a,int b):B1(a){
        this->bInt = b;
    }

    int getB()
    {
        return bInt;
    }

    void setB(int x)
    {
        this->bInt = x;
    }

    void infoD1()
    {
        cout << "b= "<< bInt << endl; infoB1();
    }

};

class D2:private B1{
private:
    int cInt;
public:
    D2(int a,int c):B1(a){
        this->cInt = c;
    }

    int getC()
    {
        return cInt;
    }

    void setC(int x)
    {
        this->cInt = x;
    }

    void infoD2()
    {
        cout << "c= "<< cInt<< endl;infoB1();
    }

};


class D4:public D1,public D2{
private:
    int dInt;
public:
    D4(int a,int b,int c,int d):D1(a,b),D2(a,c){
        this->dInt = d;
    }

    int getD()
    {
        return dInt;
    }

    void setD(int x)
    {
        this->dInt = x;
    }

    void infoD4()
    {
        cout << "d= "<< dInt<<endl; infoD1();  infoD2();
    }

};

class B2:private D4{
private:
    int eInt;
public:
    B2(int a,int b,int c,int d, int e):D4(a,b,c,d){
        this->eInt = e;
    }

    int getE()
    {
        return eInt;
    }

    void setE(int x)
    {
        this->eInt = x;
    }

    void infoB2()
    {
        cout << "e= "<< eInt<<endl; infoD4();
    }

};

int main()
{
    B2 a(1,5,9,6,3);
    a.infoB2();
    return 0;
}
