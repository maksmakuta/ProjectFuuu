#include <iostream>
#include <string>

using namespace std;

bool isPrime1(int num){
    if (num <= 3)
        return num > 1;
    else if (num % 2 == 0 || num % 3 == 0)
        return false;
    else{
        for (int i = 5; i * i <= num; i += 6)
          if (num % i == 0 || num % (i + 2) == 0)
              return false;
        return true;
    }
}

bool isPrime2(int n){
    if (n <= 1) return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(int argc,char** argv){
    if(argc < 2){
        cout << "Usage : " << argv[0] << " num\n";
    }else{
        int N = stoi(string(argv[1]));
        for(int a = 1;a <= N;a++){
            if(isPrime1(a) and isPrime2(a))
                cout << a << " ";
        }
        cout << "\n";
    }
    return 0;
}
