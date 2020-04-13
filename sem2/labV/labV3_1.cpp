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

};

matrix sub(matrix first , matrix second){
    matrix newMatrix (first.a - second.a,first.b - second.b,first.c - second.c,first.d - second.d);
    return newMatrix;
}

int main()
{

    matrix A(1,6,5,4);
    matrix B(1,9,2,4);
    matrix C(6,39,27,24);

    cout << "Ax+B=C Task" << endl;
    matrix r = sub(C,B);
    int x = r.a / A.a;
    int g = r.b / A.b;
    int i = r.c / A.c;
    int l = r.d / A.d;
    if( x == g && i == l && g == i)
        cout << "x = " << x << endl;
    else
        cout <<"Incorrect data"<< endl;
    return 0;
}
