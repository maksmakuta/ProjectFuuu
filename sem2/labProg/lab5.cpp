#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

enum scale {ounces, kilograms}; //???

class ZooAnimal
{
private:
    string name;
    int cageNumber;
    int weightDate;
    int weight;
public:
    ZooAnimal();
    ZooAnimal(string,int,int,int);
    void Create (string, int, int, int); // create function
    void Destroy (); // destroy function
    void changeWeight (int pounds);
    void changeWeightDate (int today);
    string reptName ();
    int reptWeight ();
    void reptWeight (scale which);
    int reptWeightDate ();
    int daysSinceLastWeighed (int today);
    string getName(); // task 3
};

string ZooAnimal::getName() // task 3
{
    return name;
}

ZooAnimal::ZooAnimal()
{
    this->name = "Nameless";
    this->cageNumber = 9999;
    this->weightDate = 101;
    this->weight = 100;
}

int ZooAnimal::daysSinceLastWeighed(int today) // task 2
{
    return today - weightDate;
}
void ZooAnimal::Destroy()
{
    //delete [] name; // not working
}

int ZooAnimal::reptWeightDate()
{
    return weightDate;    // task 4
}


void ZooAnimal::Create(string animalName, int animalCageNumber, int animalWeightDate, int animalWeight)
{
    this->name = animalName;
    this->cageNumber = animalCageNumber;
    this->weightDate = animalWeightDate;
    this->weight = animalWeight;
}

class Drib
{

private:
    int x,y;
public:
    /*
                 a    x
    drib (a,b) = - or -
                 b    y
    */
    Drib(int a = 1,int b = 1)
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

    void setX(int newX){
        this->x = newX;
    }
    void setY(int newY){
        this->y = newY;
    }

    Drib mul(int num){
        return Drib(x*num,y*num);
    }

    //~Drib();
    Drib minDrib();
    friend Drib operator + (Drib &, Drib &);
    friend Drib operator - (Drib &, Drib &);
    friend Drib operator * (Drib &, Drib &);
    friend Drib operator / (Drib &, Drib &);
    Drib operator = (Drib &a){
        return Drib(a.getX(),a.getY());
    }
};

Drib Drib::minDrib(){
    int m= getX() / getY();
    if( m > 1 || m < -1){
        return Drib((int)(getX() / m), (int)(getY() / m));
    }
}

Drib operator + (Drib &c1, Drib &c2)
{
    if(c1.getY() != c2.getY()){
        int a = c1.getX() * c2.getY();
        int b = c2.getY() * c1.getX();
        int c = c1.getY() * c2.getY();
        return Drib(a + b, c);
    }else
        return Drib(c1.getX() + c2.getX(), c1.getY() );
}

Drib operator - (Drib &c1, Drib &c2)
{
    if(c1.getY() != c2.getY()){
        int a = c1.getX() * c2.getY();
        int b = c2.getY() * c1.getX();
        int c = c1.getY() * c2.getY();
        return Drib(a - b, c);
    }else
        return Drib(c1.getX() - c2.getX(), c1.getY() );
}

Drib operator * (Drib &c1, Drib &c2)
{
        return Drib(c1.getX() * c2.getX(), c1.getY() * c2.getY() );
}

Drib operator / (Drib &c1, Drib &c2)
{
    return Drib(c1.getX() * c2.getY(), c1.getY() * c2.getX() );
}

ostream& operator<<(ostream& a, Drib x)
{
    if(x.getY() != 1)
    a << x.getX() << "\n-\n" << x.getY() << endl;
    else
         a << x.getX() << endl;
}

void toStandartForm(string text, Drib &a){
    int m = a.getX() / a.getY();
    int s = text.size();
    if(m > 0){
        cout << setw(s+3) << (int)(a.getX() - a.getY()*m) <<endl<<text << " " << m << "-" <<endl<< setw(s+3) << a.getY() << endl;
    }
}

void print(string text, Drib &a){
    int x = text.size();
    cout << setw(x+1) << a.getX() <<endl << text << "-" <<endl<< setw(x+1) << a.getY() << endl;
}

class Polynom{

private:
    int r1,r2,r3,r4,x;
public:
    Polynom(int a, int b, int c, int d){
        this->r1 = a;
        this->r2 = b;
        this->r3 = c;
        this->r4 = d;
    }

    void printCoef(){
    cout << "r1 = "<<r1 << " r2 = "<<r2<< " r3 = "<<r3<< " r4 = "<<r4<<endl;
    }

    void print(){
     cout <<r1<<"x+"<<r2<<"x+"<<r3<<"x+"<<r4<<"x"<<endl;
    }

    void calc(){
        cout << "Enter x: ";
        cin >> x;
        int eq = (r1 * x) + (r2 * x) + (r3 * x) + (r4 * x);
        cout <<r1<<" * "<<x<<" + "<<r2<<" * "<<x<<" + "<<r3<<" * "<<x<<" + "<<r4<<" * "<<x<<" = "<<eq<<endl;
    }

};

int main()
{
    cout << "ZooAnimal class" << endl;
    ZooAnimal bozo;
    bozo.Create("Bozo", 408, 1027, 400);
    cout << "This animal's name is " << bozo.getName() << endl;
    //cout << "This animal was last weighed in " << bozo.daysSinceLastWeighed(1299) << endl;
    //bozo.Destroy(); not working  ;)

    cout << endl << "Drib class" << endl;

    Drib a(2,3);
    Drib b(6,3);
    Drib c = a+b;
    Drib d = a-b;
    Drib e = a*b;
    Drib f = a/b;
    Drib g = b.minDrib();
    Drib h = a.mul(3);


    print("a = ",a);
    print("b = ",b);
    print("a+b = ",c);
    print("a-b = ",d);
    print("a*b = ",e);
    print("a/b = ",f);
    print("Min(b) = ",g);

    print("a*3 = " ,h);

    Drib z(15,6);
    print("z = ",z);

    toStandartForm("z = ",z);

    cout << endl << "Polynom class" << endl << endl;

    Polynom p(1,8,6,3);
    p.printCoef();
    p.print();
    p.calc();

    return 0;
}
