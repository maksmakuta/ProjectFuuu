#include <iostream>

using namespace std;

int r(int x, int a)
{
    if (a != 0)
        return (x*r(x, a-1));
    else
        return 1;
}
long long fib(int x) {
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fib(x-1)+fib(x-2));
   }
}

int main()
{
    cout << "Task 1" << endl;

    cout << r(2,9) << endl;

     cout << "Task 2" << endl;

    int x = 10 , i=0;

   while(i < x) {
      cout << " " << fib(i);
      i++;
   }
   return 0;


    return 0;
}
