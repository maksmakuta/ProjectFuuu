#include <iostream>
#include <string>

using namespace std;

class Info{
    public:
virtual void info(){}
};
class Animal : public Info{
public:
    string name;
    Animal (string n){this->name = n;}

    string getName(){return name;}
    void setName(string n){this->name = n;}

    void info(){
        cout << "Animal name: " << getName()<<endl;
    }

    ~Animal () {}


};
class Mammal: public Animal{
public:

    Mammal (string n):Animal(n){}

    ~Mammal () {}

};
class Reptile: public Animal{
public:

    Reptile (string n):Animal(n){}

    ~Reptile () {}

};
class Horse: public Mammal{
private:
    int age;
public:

    Horse (int a,string n):Mammal(n){
    this->age = a;
    }

    int getAge(){return age;}
    void setAge(int n){this->age = n;}

    void info(){
        cout << "Horse name: " << getName() << endl;
        cout << "Horse age: " << age << endl;
    }

    ~Horse () {}

};
class Dog: public Mammal{
public:
    int age;
    Dog (int a,string n):Mammal(n){
        this->age = a;
    }

    int getAge(){return age;}
    void setAge(int n){this->age = n;}
    void info(){
        cout << "Dog name: " << getName() << endl;
        cout << "Dog age: " << age << endl;
    }

    ~Dog () {}

};
class WorkingDog: public Dog{
private:
    bool adult;
public:

    WorkingDog (int a,bool ad,string n):Dog(a,n){
    this->adult = ad;
    }

    bool getAdult(){return adult;}
    void setAdult(bool n){this->adult = n;}

    void info(){
        cout << "Dog name: " << name << endl;
        cout << "Dog is adult: " << adult << endl;
        cout << "Dog age: " << age << endl;
    }

    ~WorkingDog () {}

};
class SportingDog: public Dog{
public:
bool adult;
    SportingDog (int a,bool ad,string n):Dog(a,n){
    this->adult = ad;
    }

    bool getAdult(){return adult;}
    void setAdult(bool n){this->adult = n;}

    void info(){
        cout << "Dog name: " << getName() << endl;
        cout << "Dog is adult: " << getAdult() << endl;
        cout << "Dog age: " << getAge() << endl;
    }

    ~SportingDog () {}

};
class TerriersDog: public Dog{
private:
    bool adult;
public:

    TerriersDog (int a,bool ad,string n):Dog(a,n){
    this->adult = ad;
    }

    bool getAdult(){return adult;}
    void setAdult(bool n){this->adult = n;}

    void info(){
        cout << "Dog name: " << getName() << endl;
        cout << "Dog is adult: " << adult << endl;
        cout << "Dog age: " << getAge() << endl;
    }

    ~TerriersDog () {}

};
class Retriavers: public SportingDog{
public:
    string ownerName;
    Retriavers (string o,int a,bool ad,string n):SportingDog(a,ad,n){
    this->ownerName = o;
    }

    string getOwnerName(){return ownerName;}
    void setOwnerName(string n){this->ownerName = n;}

    void info(){
        cout << "Dog name: " << getName() << endl;
        cout << "Dog is adult: " << getAdult() << endl;
        cout << "Dog age: " << getAge() << endl;
        cout << "Dog owner name : " << ownerName << endl;
    }

    ~Retriavers() {}

};
class Spaniels: public SportingDog{
private:
    string ownerName;
public:

    Spaniels (string o,int a,bool ad,string n):SportingDog(a,ad,n){
    this->ownerName = o;
    }

    string getOwnerName(){return ownerName;}
    void setOwnerName(string n){this->ownerName = n;}
    void info(){
        cout << "Dog name: " << getName() << endl;
        cout << "Dog is adult: " << getAdult() << endl;
        cout << "Dog age: " << getAge() << endl;
        cout << "Dog owner name : " << ownerName << endl;
    }

    ~Spaniels() {}

};
class Labradors: public Retriavers{
private:
    bool loyalty;
public:

    Labradors(string o,bool l,int a,bool ad,string n):Retriavers(o,a,ad,n){
    this->loyalty = l;
    }

    bool getLoyalty(){return loyalty;}
    void setLoyalty(bool n){this->loyalty = n;}

    void info(){
        cout << "Dog name: " << getName() << endl;
        cout << "Dog is adult: " << getAdult() << endl;
        cout << "Dog age: " << getAge() << endl;
        cout << "Dog owner name : " << getOwnerName() << endl;
        cout << "Dog is loyalty : " << loyalty << endl;

    }

    ~Labradors() {}

};
class Goidens: public Retriavers{
private:
    bool loyalty;
public:

    Goidens(string o,bool l,int a,bool ad,string n):Retriavers(o,a,ad,n){
    this->loyalty = l;
    }

    bool getLoyalty(){return loyalty;}
    void setLoyalty(bool n){this->loyalty = n;}

    void info(){
        cout << "Dog name: " << getName() << endl;
        cout << "Dog is adult: " << getAdult() << endl;
        cout << "Dog age: " << getAge() << endl;
        cout << "Dog owner name : " << getOwnerName() << endl;
        cout << "Dog is loyalty : " << loyalty << endl;
    }

    ~Goidens() {}

};

int main()
{
    Animal animal("Rick");
    animal.info();
    cout << endl;
    Mammal mammal("Rich");
    mammal.info();
    cout << endl;
    Reptile reptile("Richard");
    reptile.info();
    cout << endl;
    Horse horse(6,"Charlse");
    horse.info();
    cout << endl;
    Dog dog(3,"Luck");
    dog.info();
    cout << endl;
    WorkingDog wdog(6,false,"Ben");
    wdog.info();
    cout << endl;
    SportingDog sdog(4,true,"Chack");
    sdog.info();
    cout << endl;
    TerriersDog tdog(3,true,"Lem");
    tdog.info();
    cout << endl;
    Retriavers retriavers("Mike",2,false,"Boss");
    retriavers.info();
    cout << endl;
    Spaniels spaniels("Jenny",7,true,"Joey");
    spaniels.info();
    cout << endl;
    Labradors labradors("Mike",true,6,false,"Doge");
    labradors.info();
    cout << endl;
    Goidens goidens("Jenny",false,8,true,"Chocky");
    goidens.info();
    cout << endl;

    return 0;
}
