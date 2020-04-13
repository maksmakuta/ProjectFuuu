#include <iostream>

using namespace std;

class Tvir{
private:
string nazva,avtor,zhanr;
int rik;
public:
    Tvir(string n,string a, string z, int r){
        this->nazva = n;
        this->avtor = a;
        this->zhanr = z;
        this->rik = r;
    }

    string getNazva(){  return nazva;}
    string getAvtor(){  return avtor;}
    string getZhanr(){  return zhanr;}
    int getRik(){       return rik;}

    void    setNazva(string n){     this->nazva = n;}
    void    setAvtor(string a){     this->avtor = a;}
    void    setZhanr(string z){     this->zhanr = z;}
    void    setRik(int r){          this->rik = r;}

    void printTvir(){
    cout <<     "Avtor : " << avtor << endl <<
                "Nazva : " << nazva << endl <<
                "Zhanr : " << zhanr << endl <<
                "Rik : " << rik << endl;
    }
};

class Tehnika{
private:
    string tehnika,material;
public:
    Tehnika(string t, string m){
        this->tehnika = t;
        this->material = m;
    }

    string getTehnika(){  return tehnika;}
    string getMaterial(){ return material;}

    void    setTehnika(string t){     this->tehnika = t;}
    void    setMaterial(string m){    this->material = m;}

    void printTehnika(){
    cout <<     "Tehnika : " << tehnika << endl <<
                "Material : " << material << endl;
    }

};

class Kartina : public Tvir,public Tehnika{
private:
    int shirina, visota, tcina;
public:
    Kartina(string name, string autorname, string genre,
            int year, string technik, string material,
            int w, int h, int price):Tvir(name,autorname,genre,year),Tehnika(technik,material){
        this->shirina = w;
        this->visota = h;
        this->tcina = price;
    }

    int     getShirina(){   return shirina;}
    int     getVisota(){    return visota;}
    int     getTcina(){     return tcina;}

    void setShirina(int s){     this->shirina = s;}
    void setVisota(int v){      this->visota = v;}
    void setTcina(int t){       this->tcina = t;}

    void info(){
        printTvir();
    cout <<     "Dimensions : " << shirina << "x" << visota << endl <<
                "Price : " << tcina << "$" << endl;
        printTehnika();
    }



};

int main()
{
    Kartina p("The parents' house in Kirillovka","T.Shevchenko","classic",1843,
              "italian pencil","paper",17,26,250000);
    p.info();
    return 0;
}
