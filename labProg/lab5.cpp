#include <iostream>
#include <math.h>

using namespace std;

double f(double x)
{
  return x * cos(2*x);
}

int main()
{
    int i;
  double Integral;
  double a = 0.0, b = M_PI/2;
  double h = 0.1;
  double n = (b - a) / h;

   Integral = 0.0;
  for(i = 1; i <= n; i++)
	Integral = Integral + h * f(a + h * (i - 0.5));
  cout << "f(x) = " << Integral << "\n";

    return 0;
}
