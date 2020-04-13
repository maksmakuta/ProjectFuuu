#include <iostream>

using namespace std;
/*
   / a  b \
   \ c  d /
*/

class matrix{ // 2x2 matrix
    public:
    int a,b,c,d;
    matrix(int z,int x,int c,int v){
        this->a = z;
        this->b = x;
        this->c = c;
        this->d = v;
    }

    void print(){
        cout << "\t/" << a << "  " << b<<"\\" << endl;
        cout << "\t\\" << c << "  " << d <<"/"<< endl;
    }

};

matrix mul(matrix f , matrix s){
    int x = (f.a * s.a) + (f.b * s.c);
    int g = (f.a * s.b) + (f.b * s.d);
    int i = (f.c * s.a) + (f.d * s.c);
    int l = (f.c * s.b) + (f.d * s.d);
    matrix newMatrix (x,g,i,l);
    return newMatrix;
}

int main()
{

    matrix A(1,6,5,4);
    matrix B(1,9,2,4);

    cout << "AxB Task" << endl;

    matrix C = mul(A,B);

    C.print();

    return 0;
}
