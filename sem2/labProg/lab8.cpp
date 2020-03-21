#include <iostream>
#include <string>

using namespace std;

class Engine{

private:
    int power, volume;
public:
    Engine(){
        this->power = 0;
        this->volume = 0;
    }

    Engine(int p, int v){
        this->power = p;
        this->volume = v;
    }

    /////////////////set ////////////

    void setPower(int p){this->power = p;}
    void setVolume(int v){this->volume = v;}

    ///////////////get ///////////

    int getPower(){return power;}
    int getVolume(){return volume;}

    friend ostream& operator <<(ostream &a, Engine &e){
        a << "\tPower - " << e.getPower() << endl << "\tVolume - " << e.getVolume();
        return a;
    }

    Engine& operator =(Engine &e){
       power = e.getPower();
       volume = e.getVolume();
        return *this;
    }

    ~Engine(){}

};

class Truck{
private:
    string marka;
    int reg, weigth;
    Engine truckEngine;

public:
    Truck(string &m, int r, int w, Engine &e){
        this->marka = m;
        this->reg = r;
        this->weigth = w;
        this->truckEngine = e;
    }

    //set

    void setMarka(string *m){this->marka = *m;}
    void setReg(int r){this->reg = r;}
    void setWeigth(int w){this->weigth = w;}
    void setEngine(Engine &e){this->truckEngine = e;}

    ///////////get //////////////

    string getMarka(){return marka;}
    int getReg(){return reg;}
    int getWeigth(){return weigth;}
    Engine& getEngine(){return truckEngine;}

    friend ostream& operator <<(ostream &a, Truck &t){
        a << "Marka - " << t.getMarka() << endl
          << "Reg - " << t.getReg() << endl
          << "Weigth - " << t.getWeigth() << endl
          << "Engine:" << endl << t.getEngine();
          return a;
    }

};

int main()
{
    Engine a(100,300);
    string m = "LADA";
    Truck b(m, 600,400,a);
    cout << b << endl;
    return 0;
}
