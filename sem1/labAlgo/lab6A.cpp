#include<bits/stdc++.h>
using namespace std;

#define EPSILON 0.01

// #15 from table

double func(double x)
{
    return 2*x*x*x - 9*x*x - 60 * x + 1;  // 2õ^3-9õ^2-60x+1=0;
}


void bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << " a * b > 0\n";
        return;
    }

    double c = a;
    while ((b-a) >= EPSILON)
    {
        c = (a+b)/2;

        if (func(c) == 0.0)
            break;

        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "Answer : " << c;
}

int main()
{

    double a =-1, b = 6;
    bisection(a, b);
    return 0;
}
