#include <iostream>

using namespace std;

#define N 10
struct List
{
    int El[N];
    int last;

    void gen(int x)
    {
        for(int a = 0; a <= x; a ++)
        {
            add(rand() % 10);
        }
    }

    void mkList()
    {
        last=-1;
    };
    void makeNull()
    {
        if(last == -1)
        {
            cout << "List is null" << endl;
        }
        else
        {

            for(int a = 0; a <= last; a++)
            {
                El[a] = 0;//null
            }
        }
    };
    void add(int x)
    {
        if (last==-1)
        {
            El[0]=x;
            last=1;
        }
        else
        {
            El[last]=x;
            last++;
        }
    };
    void del(int pos)
    {
        if (last==-1)
        {

            cout << "List is null" << endl;
        }
        else
        {
            for(int a = 0; a <= last; a ++)
            {

                if(a == pos)
                    El[a]=El[a + 1];
                // else
                //   El[a]=El[a + 2];
            }

            last--;
        }
    };
    void insertPosit(int x, int position)
    {
        if (last==-1)
        {

            cout << "List is null" << endl;
        }
        else
        {

            for(int i=last; i>position; i--)
            {
                El[i]=El[i-1];
            }
            El[position]=x;

            last++;
        }
    };
    void print()
    {
        for(int a = 0; a <= last; a++)
        {
            cout << " " << El[a]<< endl;
        }
    }

};
int main()
{
    List a;
    a.mkList();
    a.gen(10);
    cout << "List" << endl;
    a.print();
    a.insertPosit(5,2);
    a.insertPosit(8,5);
    a.insertPosit(13,1);
    a.insertPosit(26,9);
    cout << " new List" << endl;
    a.print();


}
