#include <iostream>

using namespace std;

class E1{
public:int e;
    E1(){}
    E1(int x){this->e = x;}
    int getE(){return e;}
    void setE(int x){this->e = x;}
    friend istream& operator >> (istream&i,E1 &e1){
        int a;
        cout << "Enter e for E1 class : "; i >> a;
        e1.setE(a);
        return i;
    }
    friend ostream& operator << (ostream&i,E1 &e1){
        i << "E1(e) = " << e1.getE();
        return i;
    }
};

class D1:public E1{
public:int d;
    D1(){}
    D1(int x,int y):E1(y){this->d = x;}
    int getD(){return d;}
    void setD(int x){this->d = x;}
    friend istream& operator >> (istream&i,D1 &e1){
        int a;
        cout << "Enter d for D1 class : "; i >> a;
        e1.setD(a);
        return i;
    }
    friend ostream& operator << (ostream&i,D1 &e1){
        i << "D1(d) = " << e1.getD();
        return i;
    }
};

class D2:public E1{
public:int d;
    D2(){}
    D2(int x,int y):E1(y){this->d = x;}
    int getD(){return d;}
    void setD(int x){this->d = x;}
    friend istream& operator >> (istream&i,D2 &e1){
        int a;
        cout << "Enter d for D2 class : "; i >> a;
        e1.setD(a);
        return i;
    }
    friend ostream& operator << (ostream&i,D2 &e1){
        i << "D2(d) = " << e1.getD();
        return i;
    }
};

class C1:private D1{
public:int c;
    C1(){}
    C1(int x,int y):D1(x,y){this->c = x;}
    int getC(){return c;}
    void setC(int x){this->c = x;}
    friend istream& operator >> (istream&i,C1 &e1){
        int a;
        cout << "Enter c for C1 class : "; i >> a;
        e1.setC(a);
        return i;
    }
    friend ostream& operator << (ostream&i,C1 &e1){
        i << "C1(c) = " << e1.getC();
        return i;
    }
};

class C2:public D1,protected D2{
public:int d;
    C2(){}
    C2(int x,int y):D1(x,y),D2(x,y){this->d = x;}
    int getC(){return d;}
    void setC(int x){this->d = x;}
    friend istream& operator >> (istream&i,C2 &e1){
        int a;
        cout << "Enter c for C2 class : "; i >> a;
        e1.setC(a);
        return i;
    }
    friend ostream& operator << (ostream&i,C2 &e1){
        i << "C2(c) = " << e1.getC();
        return i;
    }
};

class B1:protected C1, private C2{
public:int b;
    B1(){}
    B1(int x,int y, int z, int i):C1(x,y),C2(z,i){this->b = x;}
    int getB(){return b;}
    void setB(int x){this->b = x;}
    friend istream& operator >> (istream&i,B1 &e1){
        int a;
        cout << "Enter b for B1 class : "; i >> a;
        e1.setB(a);
        return i;
    }
    friend ostream& operator << (ostream&i,B1 &e1){
        i << "B1(b) = " << e1.getB();
        return i;
    }
};

class B2:public C1,public C2{
public:int b;
    B2(){}
    B2(int x,int y, int z, int i):C1(x,y),C2(z,i){this->b = x;}
    int getB(){return b;}
    void setB(int x){this->b = x;}
    friend istream& operator >> (istream&i,B2 &e1){
        int a;
        cout << "Enter b for B2 class : "; i >> a;
        e1.setB(a);
        return i;
    }
    friend ostream& operator << (ostream&i,B2 &e1){
        i << "B2(b) = " << e1.getB();
        return i;
    }
};

class B3:protected C2{
public:int b;
    B3(){}
    B3(int x,int y):C2(x,y){this->b = x;}
    int getB(){return b;}
    void setB(int x){this->b = x;}
    friend istream& operator >> (istream&i,B3 &e1){
        int a;
        cout << "Enter b for B3 class : "; i >> a;
        e1.setB(a);
        return i;
    }
    friend ostream& operator << (ostream&i,B3 &e1){
        i << "B3 (b) = " << e1.getB();
        return i;
    }
};

class A1:private B1, public B2{
public:int a;
    A1(){}
    A1(int x,int y, int z, int i,int s, int w,int d ,int a):B1(x,y,s,w),B2(z,i,a,d){this->a = x;}
    int getA(){return a;}
    void setA(int x){this->a = x;}
    friend istream& operator >> (istream&i,A1 &e1){
        int a;
        cout << "Enter a for A1 class : "; i >> a;
        e1.setA(a);
        return i;
    }
    friend ostream& operator << (ostream&i,A1 &e1){
        i << "B1(b) = " << e1.getA();
        return i;
    }
};

class A2:public B1,private B2,public B3{
public:int a;
    A2(){}
    A2(int x,int y,int z,int i,int s,int w,int d,int a,int q,int e):B1(x,y,z,i),B2(s,w,d,a),B3(q,e){this->a = x;}
    int getA(){return a;}
    void setA(int x){this->a = x;}
    friend istream& operator >> (istream&i,A2 &e1){
        int a;
        cout << "Enter a for A2 class : "; i >> a;
        e1.setA(a);
        return i;
    }
    friend ostream& operator << (ostream&i,A2 &e1){
        i << "A2(a) = " << e1.getA();
        return i;
    }
};

int main()
{
    int data[10] = {1,2,3,4,5,6,7,8,9,10};

    A2 a(data[0],data[1],data[2],data[3],data[4],
         data[5],data[6],data[7],data[8],data[9]);
    cout <<"A2 -> B1 "<<a.B1::getB() <<endl;
    cout <<"A2 -> B3 "<<a.B3::getB() <<endl;

    A1 b(data[0],data[1],data[2],data[3],data[4],
         data[5],data[6],data[7]);
    cout <<"A1 -> B2 "<< b.B2::getB() << endl;

    B1 d(data[0],data[1],data[2],data[3]);
     cout <<"B1 "<< d.getB() << endl;

    B2 c(data[4],data[5],data[6],data[7]);
    cout <<"B2 -> C1 "<< c.C1::getC() << endl;
    cout <<"B2 -> C2 "<< c.C2::getC() << endl;

    B3 e(data[7],data[8]);
    cout <<"B3 "<< e.getB() << endl;

    C1 f(data[8],data[9]);
    cout <<"C1 "<< f.getC() << endl;
    C2 g(data[5],data[6]);
    cout <<"C2 -> D1 "<< g.D1::getD() << endl;

    D1 i(data[8],data[9]);
    cout <<"D1 -> E1 "<< i.E1::getE() << endl;
    D2 k(data[5],data[6]);
    cout <<"D2 -> E1 "<< k.E1::getE() << endl;

    E1 l(data[9]);
    cout <<"E1 "<< l.getE() << endl;


    return 0;
}
