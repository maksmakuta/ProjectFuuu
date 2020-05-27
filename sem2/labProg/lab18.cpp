#include <iostream>

using namespace std;

int main()
{
    int x[5]= {1,3,5,7,9};

    for(int a = 0; a < 9; a++)
    {
        try
        {
            if(a >= 5)
            {
                throw a;
            }
            else
            {
                x[a]++;
                cout << a << " - " << x[a] << " ";
            }

        }
        catch(int e)
        {
            cout <<a << " - " << "Array length < "<< e ;
        }
        cout << endl;
    }
}
