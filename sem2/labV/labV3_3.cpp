#include <iostream>

using namespace std;

class matrix2{ // 2x2 matrix
    public:
    int a,b,c,d;
    matrix2(int z,int x,int c,int v){
        this->a = z;
        this->b = x;
        this->c = c;
        this->d = v;
        /*
                / a  b \
                \ c  d /
        */
    }

    void print(){
        cout << "\t/" << a << "  " << b<<"\\" << endl;
        cout << "\t\\" << c << "  " << d <<"/"<< endl;
    }

};

class matrix3{
public:
    int a,b,c,
        d,e,f,
        g,h,i;
    matrix3(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9){
    this->a = a1;   this->b = a2;   this->c = a3;
    this->d = a4;   this->e = a5;   this->f = a6;
    this->g = a7;   this->h = a8;   this->i = a9;
    }

    void print(){
      cout << "\t/" << a << "  " << b<<"  " << c << "\\" << endl;
      cout << "\t|" << d << "  " << e<<"  " << f << "|" << endl;
      cout << "\t\\" << g << "  " << h<<"  " << i << "/" << endl;
    }

};

int det2(matrix2 m){
    return ( m.a * m.d ) - ( m.b * m.c );
}

int det3(matrix3 m){
    matrix2 A(m.e, m.f, m.h, m.i);int dA = det2(A);
    matrix2 B(m.d, m.f, m.g, m.i);int dB = det2(B);
    matrix2 C(m.d, m.e, m.g, m.h);int dC = det2(C);
    return (m.a * dA) - (m.b * dB) + (m.c * dC);
}

int main()
{

    matrix2 A(1,6,
              5,4);

    matrix3 B(1,9,2,
              4,5,3,
              7,8,6);

    cout << "determinant matrix2 and matrix3 Task" << endl;
    A.print();
    cout <<"[A]= " <<det2(A) << endl;
    B.print();
    cout <<"[B]= " <<det3(B) << endl;
    return 0;
}
