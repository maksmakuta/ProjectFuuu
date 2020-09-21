#include <iostream>
#include <cmath>

#define N 100
typedef double d;
using namespace std;

d dtr(d x){
    return (3.1415926535897931*x)/180.0;
}

d dcos(d x){
    d X = dtr(x);
    d sum = 0.0, factorial, power;
    for(int i = 0; i <= N; i++) {
        factorial = 1.0;
        power = 1.0;
        for(int j = 1; j <= 2*i; j++) {
            factorial *= j;
            power *= X;
        }
        sum += ((i%2==1?-1.0:1.0)/factorial)*power;
    }
    return sum;
}

d df(d x){
    d X = x;
    if(X > 0 && X < 1.0){
        d sum = 0.0, power;
        for(int i = 0; i <= N; i++) {
            power = 1.0;
            for(int j = 1; j <= i; j++) {
                power *= X;
            }
            sum += i*power;
        }
        return sum;
    }else{
        printf("X < 0 && X > 1.0\n");
        return -1;
    }
}

d dln(d x){
    d X = x;
    if(X > 0 && X < 1.0) {
        d sum = 0.0, factorial, power;
        for (int i = 0; i <= N; i++) {
            factorial = 0.0;
            power = 1.0;
            for (int j = 1; j <= 2 * i + 1; j++) {
                factorial++;
                power *= X;
            }
            sum += ((i % 2 == 1 ? -1.0 : 1.0) * power )/ factorial;
        }
        return sum;
    }else{
        printf("X < 0 && X > 1.0\n");
        return -1;
    }

}

int main()
{
    double x;

    scanf((char*)"%lf",&x);
    printf("cos(%f) = %f\n",x,dcos(x));
    printf("cos(%f) = %f\n",x,cos(dtr(x)));

    scanf((char*)"%lf",&x);
    printf("f(%f) = %f\n",x,df(x));
    printf("f(%f) = not exist in math.h\n",x);

    scanf((char*)"%lf",&x);
    printf("ln(%f) = %f\n",x,dln(x));
    printf("ln(%f) = %f\n",x,log1p(x));
    return 0;
}