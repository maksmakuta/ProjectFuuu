#include <iostream>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int gen(int minR, int maxR)
{
    return minR + ( std::rand() % ( maxR - minR + 1 ) );
}

int genFile()
{
    ofstream myfile;
    myfile.open ("data.txt");

    for(int a = 0; a < 10; a++)
    {
        for(int b = 0; b < 10; b++)
        {
            myfile << gen(15,50) << " ";
        }

        myfile << "\n";
    }

    myfile.close();
    return 0;
}

int readFile()
{
    int arr[10][10];
    ifstream f("data.txt");

    ofstream myfile;
    myfile.open ("data1.txt");

    if(!f)
    {
        return 0;
    }

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            f >> arr[i][j];

    int ar[10];

    for(int q = 0; q < 10; q++)
    {
        for (int i = 0; i < 10; i++)
        {
            ar[i] = arr[i][q];
        }
        int n = sizeof(ar)/sizeof(ar[0]);

        sort(ar, ar + n);
        myfile << ar[0] << " ";

        memset(ar, 0, 10*sizeof(*ar));

    }

    return 0;
}

int main()
{
    int a;
    cin >> a;
    if(a == 1)
    {
        genFile();
    }
    else if (a == 2)
    {
        readFile();
    }
    else if(a <0 && a >= 3)
    {
        return 0;
    }
    return 0;
}


