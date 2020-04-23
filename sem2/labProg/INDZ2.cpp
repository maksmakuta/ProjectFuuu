#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

int rounds = 10;

class BaseHero
{
private:
    int health,force;
public:
    BaseHero() {}
    BaseHero(int h,int f)
    {
        this->health = h;
        this->force = f;
    }

    int getForce()
    {
        return force;
    }
    int getHealth()
    {
        return health;
    }

    void setForce(int f)
    {
        this->force = f;
    }
    void setHealth(int h)
    {
        this->health = h;
    }


};

class Hero : public BaseHero
{
private:
    int speed,damageAny,damageSelf;
public:
    Hero():BaseHero() {}
    Hero(int h,int f,int s,int dA,int dS):BaseHero(h,f)
    {
        this->speed = s;
        this->damageAny = dA;
        this->damageSelf = dS;
    }

    int getSpeed()
    {
        return speed;
    }
    int getDamageAny()
    {
        return damageAny;
    }
    int getDamageSelf()
    {
        return damageSelf;
    }

    void info(string name)
    {
        cout << "\t\t" << name << "\t\t" << endl;
        cout << " Health: " << getHealth() << " Force: " << getForce() << endl
             << " Speed: " << getSpeed() << " DamageAny: " << getDamageAny()
             << " DamageSelf: " << getDamageSelf()  << endl;
    }

    void setSpeed(int s)
    {
        if(s <0 )
            this->speed = 0;
        else
            this->speed = s;
    }
    void setDamageSelf(int dS)
    {
        this->damageSelf = dS;
    }
    void setDamageAny(int dA)
    {
        this->damageAny = dA;
    }
    ~Hero() {}
};

class AntiHero: public BaseHero
{
private:
    int helpAmount;
    bool helpOtherAntiHero;
public:
    AntiHero():BaseHero() {}
    AntiHero(int h,int f,int hA):BaseHero(h,f)
    {
        this->helpAmount = hA;
    }

    void info(string name)
    {
        cout << "\t\t" << name << "\t\t" << endl;
        cout << " Health: " << getHealth() << " Force: " << getForce() << endl
             << " HelpAmount: " << getHelpAmount() << endl;
    }

    int getHelpAmount()
    {
        return helpAmount;
    }

    void setHelpAmount(int s)
    {
        this->helpAmount = s;
    }
    ~AntiHero() {}
};

void info()
{
    cout << "\tInfo\t"<<endl;
    cout << "Press F to attack"<<endl;
    cout << "Press D to defend"<<endl;
    Sleep(1200);
}

void play1(Hero &a,Hero &b,string name)
{
    char action;

    a.info(name);
    b.info("PC");
    cout << name <<" do: ";
    cin >> action;

    if(action == 'F' || action == 'f'){

        int x1 = b.getHealth() - a.getDamageAny()/a.getForce();
        int h1 = (rand() % (x1 - 0 + 1)) + 0;
        b.setHealth(b.getHealth() - h1);
        int x2 = b.getHealth() - a.getDamageSelf();
        int h2 = (rand() % (x2 - 0 + 1)) + 0;
        a.setHealth(a.getHealth() - h2);
        a.setSpeed(a.getSpeed()/(3/2));

        }else if(action == 'd' || action == 'D'){

        int x3 = b.getHealth() - a.getDamageAny()/a.getForce();
        int h3 = (rand() % (x3 - 0 + 1)) + 0;
        a.setHealth(b.getHealth() - h3);
        int x4 = b.getHealth() - a.getDamageSelf();
        int h4 = (rand() % (x4 - 0 + 1)) + 0;
        b.setHealth(a.getHealth() - h4);
        b.setSpeed(a.getSpeed()/(3/2));

    }
}

void play2(Hero &a,AntiHero &b,string name)
{
    char action;

    a.info(name);
    b.info("PC");
    cout << name <<" do: ";
    cin >> action;

    if(action == 'F' || action == 'f'){

        int x5 = b.getHealth() - a.getDamageAny()/a.getForce();
        int h5 = (rand() % (x5 - 0 + 1)) + 0;
        b.setHealth(b.getHealth() - h5);
        int x6 = b.getHealth() - a.getForce();
        int h6 = (rand() % (x6 - 0 + 1)) + 0;
        a.setHealth(a.getHealth() - h6);

       }else if(action == 'D' || action == 'd'){

        int x7 = a.getHealth() - b.getForce();
        int h7 = (rand() % (x7 - 0 + 1)) + 0;
        a.setHealth(b.getHealth() - h7);
        int x8 = b.getHealth() - a.getDamageAny()/a.getForce();
        int h8 = (rand() % (x8 - 0 + 1)) + 0;
        b.setHealth(a.getHealth() - h8);

    }
}

void play3(AntiHero &a,Hero &b,string name)
{
    char action;

    a.info(name);
    b.info("PC");
    cout << name <<" do: ";
    cin >> action;

    if(action == 'F' || action == 'f'){

        int x9 = a.getHealth() - b.getDamageAny()/b.getForce();
        int h9 = (rand() % (x9 - 0 + 1)) + 0;
        a.setHealth(b.getHealth() - h9);
        int x10 = b.getHealth() - a.getForce();
        int h10 = (rand() % (x10 - 0 + 1)) + 0;
        b.setHealth(a.getHealth() - h10);

       }else if(action == 'D' || action == 'd'){

        int x11 = b.getHealth() - a.getForce();
        int h11 = (rand() % (x11 - 0 + 1)) + 0;
        b.setHealth(b.getHealth() - h11);
        int x12 = a.getHealth() - b.getDamageAny()/b.getForce();
        int h12 = (rand() % (x12 - 0 + 1)) + 0;
        a.setHealth(a.getHealth() - h12);
    }
}

void play4(AntiHero &a,AntiHero &b,string name)
{
    char action;

    a.info(name);
    b.info("PC");
    cout << name <<" do: ";
    cin >> action;

    if(action == 'F' || action == 'f'){
        int x13 = b.getHealth() + a.getHelpAmount();
        int h13 = (rand() % (x13 - 0 + 1)) + 0;
        b.setHealth(b.getHealth() + h13);
        int x14 = b.getHealth() + a.getHelpAmount();
        int h14 = (rand() % (x14 - 0 + 1)) + 0;
        a.setHealth(a.getHealth() + h14);

    }else if(action == 'D' || action == 'd'){

        int x15 = a.getHealth() - b.getForce()/b.getHelpAmount();
        int h15 = (rand() % (x15 - 0 + 1)) + 0;
        a.setHealth(b.getHealth() - h15);
        int x16 = b.getHealth() - a.getForce()/a.getHelpAmount();
        int h16 = (rand() % (x16 - 0 + 1)) + 0;
        b.setHealth(a.getHealth() - h16);
    }
}

void check1(Hero &a,Hero &b,string name)
{
    a.info(name);
    b.info("PC");
    if(a.getHealth() == b.getHealth())
    {
        cout <<"Nobody won" << endl;
    }
    else
    {
        if(a.getHealth() > b.getHealth())
        {
            cout << name << " win" << endl;
        }
        else
        {
            cout << "PC win" << endl;
        }
    }

}

void check2(Hero &a,AntiHero &b,string name)
{
    a.info(name);
    b.info("PC");
    if(a.getHealth() == b.getHealth())
    {
        cout <<"Nobody won" << endl;
    }
    else
    {
        if(a.getHealth() > b.getHealth())
        {
            cout << name << " win" << endl;
        }
        else
        {
            cout << "PC win" << endl;
        }
    }

}

void check3(AntiHero &a,Hero &b,string name)
{
    a.info(name);
    b.info("PC");
    if(a.getHealth() == b.getHealth())
    {
        cout <<"Nobody won" << endl;
    }
    else
    {
        if(a.getHealth() > b.getHealth())
        {
            cout << name << " win" << endl;
        }
        else
        {
            cout << "PC win" << endl;
        }
    }
}

void check4(AntiHero &a,AntiHero &b,string name)
{
    a.info(name);
    b.info("PC");
    if(a.getHealth() == b.getHealth())
    {
        cout <<"Nobody won" << endl;
    }
    else
    {
        if(a.getHealth() > b.getHealth())
        {
            cout << name << " win" << endl;
        }
        else
        {
            cout << "PC win" << endl;
        }
    }
}

int main()
{
    Hero a1(100,    15, 20,10, 5);
    AntiHero a2(100,    15,  5);
    Hero b1(95,     12, 18, 9, 4);
    AntiHero b2(95,     12,  4);
    Hero c1(120,    10, 22,12, 6);
    AntiHero c2(70,     6,   2);
    Hero d1(70,     6,  17, 7, 2);
    AntiHero d2(120,    10,  6);
    Hero e1(80,     8,  18, 8, 2);
    AntiHero e2(50,     3,   3);
    Hero f1(30,     20, 10, 3, 1);
    AntiHero f2(30,     20,  1);
    Hero g1(150,    25, 25,15, 7);
    AntiHero g2(75,     4,   4);
    Hero h1(75,     4,  15, 8, 4);
    AntiHero h2(150,    25,  7);
    Hero i1(50,     3,  12, 5, 3);
    AntiHero i2(80,     8,   2);
    Hero l1(250,    30, 30,25,10);
    AntiHero l2(250,    30, 10);
    Hero     player1[10] =  {a1,b1,c1,d1,e1,f1,g1,h1,i1,l1};
    AntiHero player2[10] =  {a2,b2,c2,d2,e2,f2,g2,h2,i2,l2};
    string name;
    cout << "Enter your name"; cin >> name;
    int t1,t2;
    int p1,p2;
    cout <<"Enter type of Hero for " << name << ": \n \t1.Hero\n \t2.AntiHero\n";
    cin >> t1;
    srand(-2);
    srand(rand());t2 = (rand() % (1 - 1 + 1)) + 1;
    srand(rand()%1200);p1 = (rand() % (9 - 0 + 1)) + 0;
    srand(rand()%120000);p2 = (rand() % (9 - 0 + 1)) + 0;
    Hero ph1,ph2;
    AntiHero ah1,ah2;
    if(t1 == 1)
        ph1 = player1[p1-1];
    else if(t1 == 2)
        ah1 = player2[p1-1];
    else
    {
        cout << name <<" : Error" << endl;
        return 0;
    }

    if(t2 == 1)
        ph2 = player1[p2-1];
    else if(t2 == 2)
        ah2 = player2[p2-1];
    else
    {
        cout << "PC : Error" << endl;
        return 0;
    }
    system("cls");
    info();
    while(1)
    {
        system("cls");
        if(rounds > 0 )
        {
            if(ph1.getHealth() >0 || ph2.getHealth() >0 || ah1.getHealth() >0 || ah2.getHealth() >0 )
            {
                cout << "Round : " << rounds << endl;
                rounds--;
                if(t1 == 2 && t2 == 2)
                    play4(ah1,ah2,name);
                else if(t1 == 1 && t2 == 2)
                    play2(ph1,ah1,name);
                else if(t1 == 2 && t2 == 1)
                    play3(ah1,ph2,name);
                else
                    play1(ph1, ph2,name);
            }
            else
            {
                if(t1 == 2 && t2 == 2)
                     check4(ah1,ah2,name);
                else if(t1 == 1 && t2 == 2)
                    check2(ph1,ah1,name);
                else if(t1 == 2 && t2 == 1)
                    check3(ah1,ph2,name);
                else
                    check1(ph1, ph2,name);

                cout <<"Wait for exit" << endl;
                Sleep(1200);
                return 0;
            }
        }else
            {
                if(t1 == 2 && t2 == 2)
                     check4(ah1,ah2,name);
                else if(t1 == 1 && t2 == 2)
                    check2(ph1,ah1,name);
                else if(t1 == 2 && t2 == 1)
                    check3(ah1,ph2,name);
                else
                    check1(ph1, ph2,name);

                cout <<"Wait for exit" << endl;
                Sleep(1200);
                return 0;
            }
    }
    return 0;
}


