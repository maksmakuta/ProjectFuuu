#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

class queue
{
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    queue(int size)
    {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    ~queue()
    {
        delete arr;
    }

    int size(){return count;}

    void dequeue()
    {
        // check for queue underflow
        if (isEmpty())
        {
            cout << "UnderFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Removing " << arr[front] << '\n';

        front = (front + 1) % capacity;
        count--;
    }
    void enqueue(int item)
    {
        // check for queue overflow
        if (isFull())
        {
            cout << "OverFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Inserting " << item << '\n';

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }
    void get(int x){
    cout << arr[x]<< endl;
    }

    void seeQ(){
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


    int peek()
    {
        if (isEmpty())
        {
            cout << "UnderFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        return arr[front];
    }
    int isEmpty()
    {
        return (size() == 0);
    }
    bool isFull()
    {
        return (size() == capacity);
    }
};

int main()
{

    queue pt(SIZE-1);
    int a = 0;
    //cin>>a;
    while(a == 0)
    {
        cout << "###############" << endl;
        cout << "1.Write"<<endl;
        cout << "2.Read"<<endl;
        cout << "3.View Queue"<<endl;
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
                pt.enqueue(tmp);
                a = 0;
                break;
            case 2:

                int a;
                cin >> a;
                pt.get(a);
                a = 0;

                break;
            case 3:
                pt.seeQ();
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


    pt.~queue();
    return 0;
    }
