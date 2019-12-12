#include <iostream>

using namespace std;

int digitCount(int k){
    int countK;

        if(k <10)
            countK = 1;
        else if(k <100 )
            countK = 2;
        else if(k <1000 )
            countK = 3;
        else if(k <10000 )
            countK = 4;
        else if(k <100000 )
            countK = 5;
        else if(k <1000000 )
            countK = 6;
        else if(k <10000000 )
            countK = 7;
        else if(k <100000000 )
            countK = 8;

            return countK;
}

int main()
{
    int x[10] = {12,165,1598,14862,125687,1,15,163,1826,15000};
    for(int a = 0; a<= 10;a++){
        cout << " "<< digitCount(x[a]) << endl;
    }
    cout << endl;

    return 0;
}
