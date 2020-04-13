#include <iostream>
#include <math.h>
#include <fstream>
#include <bits/stdc++.h>

#define n 3

using namespace std;

float change(float mat[n][n+1]){

for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(abs((int)mat[i][i]) < abs((int)mat[j][i]))
            {
                for(int  k=0; k<n+1; k++)
                {
                    mat[i][k]=mat[i][k]+mat[j][k];
                    mat[j][k]=mat[i][k]-mat[j][k];
                    mat[i][k]=mat[i][k]-mat[j][k];
                }
            }
        }
    }
    return mat[n][n+1];
}

void Gauss(string name)
{
    int i,j,k;
    float mat[n][n+1];
    float res[n];
    ifstream x(name);


    for(i=0; i<n; i++)
    {
        for(j=0; j<n+1; j++)
        {
            x>>mat[i][j];
        }
    }
    x.close();
    mat[n][n+1] = change(mat);

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            float f=mat[j][i]/mat[i][i];
            for(k=0; k<n+1; k++)
            {
                mat[j][k]=mat[j][k]-f*mat[i][k];
            }
        }
    }
    for(i=n-1; i>=0; i--)
    {
        res[i]=mat[i][n];

        for(j=i+1; j<n; j++)
        {
            if(i!=j)
            {
                res[i]=res[i]-mat[i][j]*res[j];
            }
        }
        res[i]=res[i]/mat[i][i];
    }

    cout<<"\nAnswers =>\n";
    for(i=0; i<n; i++)
    {
        cout<<res[i]<<"\n";
    }
}

double determinantOfMatrix(double mat[3][3])
{
    double ans;
    ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
          - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
          + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    return ans;
}

void Cramer(string name)
{
     ifstream x;
     x.open(name);
     double coeff[n][n+1];

     for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            x >> coeff[i][j];
        }
    }
    x.close();

    double d[3][3] =
    {
        { coeff[0][0], coeff[0][1], coeff[0][2] },
        { coeff[1][0], coeff[1][1], coeff[1][2] },
        { coeff[2][0], coeff[2][1], coeff[2][2] },
    };
    double d1[3][3] =
    {
        { coeff[0][3], coeff[0][1], coeff[0][2] },
        { coeff[1][3], coeff[1][1], coeff[1][2] },
        { coeff[2][3], coeff[2][1], coeff[2][2] },
    };
    double d2[3][3] =
    {
        { coeff[0][0], coeff[0][3], coeff[0][2] },
        { coeff[1][0], coeff[1][3], coeff[1][2] },
        { coeff[2][0], coeff[2][3], coeff[2][2] },
    };
    double d3[3][3] =
    {
        { coeff[0][0], coeff[0][1], coeff[0][3] },
        { coeff[1][0], coeff[1][1], coeff[1][3] },
        { coeff[2][0], coeff[2][1], coeff[2][3] },
    };

    double D = determinantOfMatrix(d);
    double D1 = determinantOfMatrix(d1);
    double D2 = determinantOfMatrix(d2);
    double D3 = determinantOfMatrix(d3);
    cout <<"D is : "<< D << endl;
    cout <<"D1 is : "<< D1 << endl;
    cout <<"D2 is : "<< D2 << endl;
    cout <<"D3 is : "<< D3 << endl;

    if (D != 0)
    {
        double x = D1 / D;
        double y = D2 / D;
        double z = D3 / D;
        cout << "Value of x is :"<< x << endl;;
        cout << "Value of y is :"<< y << endl;;
        cout << "Value of z is :"<< z << endl;;
    }
    else
    {
        if (D1 == 0 && D2 == 0 && D3 == 0)
            printf("Infinite solutions\n");
        else if (D1 != 0 || D2 != 0 || D3 != 0)
            printf("No solutions\n");
    }
}

int main()
{
    cout << "Gauss method" << endl;
    Gauss("data.txt");
    cout << "Cramer method" << endl;
    Cramer("data.txt");


    return 0;
}
