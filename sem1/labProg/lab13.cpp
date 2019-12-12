#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <time.h>

using namespace std;

void gen(int x, int y,string name)
{

    ofstream fs;
    srand(time(0));
    fs.open(name);
    int matrix[x][y];
    fs << x << " " << y << "\n";

    for(int i =0; i < x; i++)
    {
        for(int j =0; j < y; j++)
        {
            if(i <= j){
            matrix[i][j] = rand()%2;
            fs<<matrix[i][j] <<" ";
            }else if(j <= i){
            matrix[i][j] = matrix[j][i];
            fs<<matrix[i][j] <<" ";
            }
        }
        fs<<endl;

    }
    for(int i =0; i < x; i++)
    {
        for(int j =0; j < y; j++)
        {

        }
        fs<<endl;

    }
    fs.close();
    for(int i =0; i < x; i++)
    {
        for(int j =0; j < y; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void listM(string name)
{
    ifstream fs;
    fs.open(name);
    int x,y;
    fs >> x >> y ;
    int matrix[x][y];

    for(int i =0; i < x; i++)
    {
        for(int j =0; j < y; j++)
        {
            fs >> matrix[i][j];
        }

    }
    cout << endl;

    for(int i =0; i < x; i++)
    {
        cout << i+1 << " ";
        for(int j =0; j < y; j++)
        {
            if(matrix[i][j] == 1)
            {
                cout << j+1 << "->";
            }
        }
        cout<<" end " << endl;

    }
}

void getData(string name)
{

    ifstream fs;
    fs.open(name);
    int x,y;
    fs >> x >> y ;
    int matrix[x][y];

    for(int i =0; i < x; i++)
    {
        for(int j =0; j < y; j++)
        {
            fs >> matrix[i][j];
        }

    }
    cout << endl;

    cout << "isolated : ";
    int i = 0;

    for(int j =0; j < y; j++)
    {
        if(matrix[i][j] == 0 && matrix[i][j+1] == 0)
        {
            cout << j+1 <<" ";
            i++;
        }
    }

    cout<< endl;

    cout << "petels : ";
    for(int i =0; i < x; i++)
    {
        if(matrix[i][i] == 1 )
        {
            cout << i+1 <<" ";
        }
    }
    cout<< endl;

    cout << "multiples : ";
    int arr1[x];
    int a = 0;
    for(int i =0; i < x; i++)
    {
        for(int j =0; j < x; j++)
        {
            if(matrix[i][j] == 1 )
            {
                a++;
            }
        }
        arr1[i] = a;
        a = 0;
    }
    for(int j =0; j < x; j++)
    {
        if(arr1[j] != 0)
        {
            if(arr1[j] % 2 == 0)
            {
                cout << j+1 << " ";
            }
        }
    }

    cout<< endl;

}


int main()
{
    string name = "m.txt";
    //gen(5,5,name);
    //listM(name);
    getData(name);
    return 0;
}
