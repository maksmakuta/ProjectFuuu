#include <iostream>

using namespace std;

int main(void)
{
    int ro, co ;
    cin >> ro>> co;

    int **array = new int* [ro];

    for(int i = 0; i < ro; i++)
    {
        array[i] = new int [co];
    }
    for(int i = 0; i < ro; i++)
    {
        for(int j = 0; j < co; j++)
        {

            if(i < j )
                array[i][j] = i + j;
            else if(i > j)
                array[i][j] = i * j;
            else if (i == j )
                array[i][j] = 2;

            if(array[i][j] < 10)
                cout <<" " << array[i][j] << " ";
            else
                cout << array[i][j] << " ";

        }
        cout << endl;
    }

    int rowToDel ;
    cin >> rowToDel;
    delete [] array[rowToDel];
    int **tmp = new int*[ro - 1];
    int tmpI = 0;
    for(int i = 0; i < ro; ++i)
        if(i != rowToDel)
            tmp[tmpI++] = array[i];
    delete [] array;
    array = tmp;
    ro = ro - 1;

    cout << "Array after deleting " << rowToDel << "-th row\n";
    for(int i = 0; i < ro; i++)
    {
        for(int j = 0; j < co; j++)
        {
            if(array[i][j] < 10)
                cout <<" " << array[i][j] << " ";
            else
                cout << array[i][j] << " ";
        }
        cout << endl;
    }


    cout << "######################" << endl;
    int rowToAdd;
    cin >> rowToAdd;
    tmp = new int* [ro+1];
    tmpI=0;
    for (int i=0; i<rowToAdd; i++)
    {
        tmp[tmpI++] = array[i];
    }
    int tmpRow[co];
    for (int j=0; j<co; j++)
    {
        tmpRow[j]=0-rand()%10;
    }

    tmp[rowToAdd]=tmpRow;
    tmpI++;
    for (int i=rowToAdd++; i<ro+1; i++)
    {
        tmp[tmpI++] = array[i];
    }
    delete [] array;
    array=tmp;
    ro=ro+1;

    cout << "Array after inserting " << rowToAdd - 1 << "-th row\n";
    for (int i=0; i<ro; i++)
    {
        for (int j=0; j<co; j++)
        {
            if(array[i][j] <= 9 && array[i][j] >= 1)
                cout <<" " << array[i][j] << " ";
            else if (array[i][j] <= -1 || array[i][j] >= 10)
                cout << array[i][j] << " ";
            else
                cout << " "<< array[i][j] << " ";

        }
        cout<<endl;
    }

    for (int i=0; i<ro; i++)
    {
        delete[] array[i];
    }
    delete[]array;


return 0;
}
