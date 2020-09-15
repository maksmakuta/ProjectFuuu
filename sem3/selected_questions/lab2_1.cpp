#include <string>
#include <sstream>
#include <iostream>
#define PI 3.1415926

// task 1 (1 ,3 ,5)
// task 2 (11, 14, 17, 20) ?? not created ??

double pow(double a, int b){
    double tmp = 1;
    for(int i = 0; i < b; i++){
        tmp *= a;
    }
    return tmp;
}
double fact(int x){
    double tmp = 1;
    while(x > 1){
        tmp *= x;
        x--;
    }
    return tmp;
}

// task 1.1
double cos(double x,int p){
    double c = 0;
    for(int i = 0; i < p;i++){
        c += (pow(-1,i) * pow(x,2*i))/(fact(2*i));
    }
    return c;
}
// task 1.3
double f1(double x,int p){
    if(x > 0 && x < 1.0 ) {
        double c = 0;
        for (int i = 0; i < p; i++) {
            c += (i + 1) * pow(x, i);
        }
        return c;
    }else{
        printf("f1(x) -> x > 0 and x < 1 (Error)\n");
        return -1;
    }
}
//task 1.5
double ln(double x,int p){
    if(x > 0 && x < 1.0 ) {
        double c = 0;
        for (int i = 0; i < p; i++) {
            c += (pow(-1,i) * pow(x,(2*i)+1))/((2*i)+1);
        }
        return c;
    }else{
        printf("ln(x) -> x > 0 and x < 1 (Error)\n");
        return -1;
    }
}

double parseString(char* data,int s){
    double x;
    double v = 1;
    std::stringstream  num;
        for (int a = 0; a <= s; a++) {
            if (data[a] >= '0' && data[a] <= '9' || data[a] <= '.') {
                num << data[a];
            }
            if (data[a] == 'P' && data[a + 1] == 'I') {
                v *= PI;
            }
        }
        if (!num.str().empty()) {
            x = std::stod(num.str());
        } else {
            x = 1.0;
        }
        v *= x;
        return v;

}

int main() {
    int p;double d;
    char* str = new char[10];
    printf("========================== COS ==========================\n");
    printf("Enter precision         : "); std::cin >> p;
    printf("Enter value      Ex(2PI): "); std::cin >> str;
    d = parseString(str,10);
    std::cout << "Cos(" << d << ") = " << cos(d,p) << "\n";
    printf("========================== F1 ==========================\n");
    printf("Enter precision         : "); std::cin >> p;
    printf("Enter value      Ex(0.6): "); std::cin >> d;
    std::cout << "F1(" << d << ") = " << f1(d,p) << "\n";
    printf("========================== LN ==========================\n");
    printf("Enter precision         : "); std::cin >> p;
    printf("Enter value      Ex(0.2): "); std::cin >> d;
    std::cout << "ln(" << d << ") = " << ln(d,p) << "\n";
    return 0;
}
