#include <iostream>

using namespace std;

int main()
{
    const int s = 5;
    int a1[s] = {1,2,3,1,2};
    int a2[s] = {3,2,1,3,2};
    int f = 0;

    for(int a = 0; a < s; a++){
        if(a1[a] == a2[a]){
            f++;
        }
        if(a1[a] == a2[a - 1]){
            f++;
        }
        if(a1[a] == a2[a + 1]){
            f++;
        }
    }

    cout << f << endl;


    return 0;
}
