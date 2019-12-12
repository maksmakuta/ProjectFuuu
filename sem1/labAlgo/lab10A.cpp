#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

class stack
{
    int *arr;
    int top;
    int capacity;

public:
    stack()
    {
        arr = new int[SIZE];
        capacity = SIZE;
        top = -1;
    }
    ~stack()
    {
        delete arr;
    }
    void push(int x)
    {
        if (isFull())
        {
            cout << "OverFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Inserting " << x << endl;
        arr[++top] = x;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "UnderFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Removing " << peek() << endl;

        return arr[top--];
    }
    int peek()
    {
        if (!isEmpty())
            return arr[top];
        else
            exit(EXIT_FAILURE);
    }

    void get(int a)
    {

        cout << "Element #"<< a << "  " << arr[a] <<endl;

    }

    void seeStack(){
         for(int a = size(); a >= 0 ; a--)
        {
            cout << " "<< arr[a];
        }
    }

    void seeArr()
    {
        for(int a = 0; a <= SIZE; a++)
        {
            cout << " "<< arr[a];
        }
    }


    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == capacity - 1;
    }
};
int main()
{
    stack pt;
    int a = 0;
    cin>>a;
    while(a == 0)
    {
        cout << "###############" << endl;
        cout << "1.Write"<<endl;
        cout << "2.Read"<<endl;
        cout << "3.View Stack"<<endl;
        cout << "4.View Array"<<endl;
        cout << "5.Exit"<<endl;
        cin>>a;

        if(a == -1)
        {
            return 0;
        }
        else
        {

            switch(a)
            {
            case 1:
                int tmp;
                cin >> tmp;
                pt.push(tmp);
                a = 0;
                break;
            case 2:

                int a;
                cin >> a;
                pt.get(a);
                a = 0;

                break;
            case 3:
                pt.seeStack();
                a = 0;
                break;
            case 4:
                pt.seeArr();
                a = 0;
                break;
            case 5:
                a = -1;
                break;

            }

        }


    }


    pt.~stack();
    return 0;
}
