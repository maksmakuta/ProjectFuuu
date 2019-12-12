#include <iostream>
#include <random>

static std::random_device rd;  // Random device engine, usually based on /dev/random on UNIX-like systems
static std::mt19937_64 rng(rd()); // Initialize Mersennes' twister using rd to generate the seed


using namespace std;



int main()
{
    int n;
     cout << "Enter cinema lenght :" << endl;
    cin >> n;

    std::uniform_int_distribution<int> distribution(0, 1);
        int matrix[n][n];
    for(int a = 0; a < n; a++)
    {
        for(int b = 0; b < n; b++)
        {
            matrix[a][b] = distribution(rng);
        }
    }


    for(int a = 0; a < n; a++)
    {
        for(int b = 0; b < n; b++)
        {
            cout << matrix[a][b] ;
        }
        cout << endl;
    }




    int x,y;

    cout << "Enter your line : " << endl;
    cin >> x;
    cout << "Enter your place : " << endl;
    cin >> y;

    if(matrix[x][y] == 0)
    {
        cout << "Your place is free" << endl;
    }
    else
    {
        cout << "Find new place..." << endl;
    }

    return 0;
}
