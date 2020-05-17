#include <iostream>

using namespace std;

template <class T>
float pers(int s, T arr[])
{
    float even = 0.0f;

    for(int q = 0; q < s; q++)
    {
        if(arr[q] % 2 == 0)
            even += 100.0f/s;
    }
    return even;
}

int main()
{
    int s = 10;
    int a[s] = {1,8,4,6,5,2,1,4,56,156};
    cout << "Even = " << pers(s,a) << "%" << endl;
    cout << "Odd = " << 100.0f - pers(s,a) << "%" << endl;
    return 0;
}
