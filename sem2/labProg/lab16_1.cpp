#include <iostream>

using namespace std;

template <class T>
T minNum(T a, T b){
    return a < b ? a : b;
}

int main()
{
    cout << minNum(6,8) << endl;
    return 0;
}
