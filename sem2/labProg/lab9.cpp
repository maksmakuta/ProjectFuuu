#include <iostream>
#include <string>
#include <vector>

using namespace std;

class vec
{
private:
    int x,y;
public:
    vec(int a, int b)
    {
        this->x = a;
        this->y = b;
    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    void setX(int a)
    {
        this->x = a;
    }
    void setY(int a)
    {
        this->y = a;
    }

    void p()
    {
        cout << "(" <<x << ";"<< y <<")" << endl;
    }
    ~vec() {}
};

class Person:public vec
{
private:
    string name;
public:
    Person(int x,int y,string n):vec(x,y)
    {
        this->name = n;
    }

    string getName()
    {
        return name;
    }

    void setName(string n)
    {
        this->name = n;
    }

    void info()
    {
        cout << "Person name: " << name << " Coordinates : ";
        p();
    }
    ~Person() {}

};

class PersonQueve
{

private :
    vector<Person> q;
public:
    PersonQueve() {}

    void add(int x,int y,string n)
    {
        Person newP(x,y,n);
        q.push_back(newP);
    }

    void del(int pos)
    {
        q.erase(q.begin() + pos);
        cout << endl;
    }


    void printQueve()
    {

        for(int a = 0; a < q.size(); a++)
        {
            cout << "Pos: " << a << " ";
            q[a].info();
        }

    }

    ~PersonQueve() {}
};

int main()
{
    /*
    vec a(4,8);
    a.p();
    Person p(48,56,"Viktor");
    p.info();
    */
    PersonQueve pq;
    pq.add(1,6,"Nick");
    pq.add(8,68,"Dan");
    pq.add(786,4354,"Joey");
    pq.add(54,454,"Tim");
    pq.add(48,87,"Ben");
    pq.printQueve();

    pq.del(2);

    pq.printQueve();

    return 0;
}
