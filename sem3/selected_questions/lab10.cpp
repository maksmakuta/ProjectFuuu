#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
//3, 23, 12

struct Player{
    std::string n;
    int b;

    Player(std::string &str, int i) {
        n = str;
        b = i;
    }
};

bool cmp(const Player &a, const Player &b)
{
    return a.b > b.b;
}


struct Magnitofon{
    std::string name;
    int price, classMgf;


    Magnitofon(std::string &s,int p, int c){
        name = s;
        price = p;
        classMgf = c;
    }
};

struct Row{
    std::string name;
    int *d = new int[5];

    Row(std::string &n, const int *f){
        name = n;
        d[0] = f[0];
        d[1] = f[1];
        d[2] = f[2];
        d[3] = f[3];
        d[4] = f[4];
    }
    Row(std::string &n,int f1,int f2,int f3,int f4,int f5){
        name = n;
        d[0] = f1;
        d[1] = f2;
        d[2] = f3;
        d[3] = f4;
        d[4] = f5;
    }

    std::string toString(){
        std::stringstream ss;
        ss << name << " " << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << d[4] << '\n';
        return ss.str();
    }

    void print(){
        std::cout << std::setw(10) << name << std::setw(5) << d[0] << std::setw(5)
        << d[1] << std::setw(5) << d[2] << std::setw(5) << d[3] << std::setw(5) << d[4] << std::endl;
    }

    //~Row(){delete [] d;} //error
};

void t3(){
    std::vector<Player> data;
    std::ifstream f("data.txt");
    if(!f){
        printf("!File\n");
    }else {
        std::string n,i;
        int b;
        while (f >> n >> i) {
            b = std::stoi(i);
            Player p(n, b);
            data.push_back(p);
        }
        f.close();
    }
    std::sort(data.begin(), data.end(), cmp);

    for(int a = 0; a < 3; a++){
        std::string N =data[a].n;
        printf("%s\n",N.c_str());
    }
}

void t12(){
    std::vector<Magnitofon> data;
    std::ifstream f("mgf.txt");
    if(!f){
        printf("!File\n");
    }else {
        std::string n,p,c;
        int pr,cl;
        while (f >> n >> p >> c) {
            pr = std::stoi(p);
            cl = std::stoi(c);
            Magnitofon p(n, pr,cl);
            data.push_back(p);
        }
        f.close();
    }

    printf("\tName\tPrice\n");
    for(int a = 0; a < data.size(); a++){
        Magnitofon m = data[a];
        if(m.classMgf == 1){
            printf("\t%s\t%i\n",m.name.c_str(), m.price);
        }
    }
}

std::vector<Row> table;
void t23();

void init() {
    std::ifstream data("data.txt");

    if (!data) {
        printf("File is null");
    } else {
        //table.clear();
        std::string n;
        while (data >> n) {
            int *d = new int[5];
            for (int a = 0; a < 5; a++) {
                std::string tmp;
                data >> tmp;
                if(!tmp.empty())
                    d[a] = std::stoi(tmp);
            }
            Row r(n, d);
            table.push_back(r);
            delete [] d;
        }
    }
}
void print(){
    if(table.empty())
        init();

    for(Row e : table){
        e.print();
    }
    t23();
}
void add(){
    printf("Enter name d1 d2 d3 d4 d5\n");
    std::string n;
    int d1,d2,d3,d4,d5;
    std::cin >> n >> d1 >> d2 >> d3 >> d4 >> d5;
    Row r(n,d1,d2,d3,d4,d5);
    std::ofstream dataF("data.txt");
    if(!dataF){
        printf("File is null");
    }else{
        dataF.seekp(0,std::ios::end);
        dataF << r.toString();
    }
    dataF.close();
    table.push_back(r);
    t23();
}

void save(){
    std::ofstream data("data.txt");
    data.clear();
    for(Row a : table){
        data.seekp(0,std::ios::end);
        data << a.toString();
    }
    data.close();
}

void clear(){
    table.clear();
    std::ifstream data("data.txt");
    data.clear();
    data.close();
    t23();
}
void remove(){
    int p;
    printf("Enter pos -> ");
    std::cin >> p;
    table[p] = table[table.size() - 1];
    table.erase(table.end());
    save();
    printf("Data removed");
    t23();
}

void t23(){
    int t;
    printf("Menu:\n\n");
    printf("0. Clear file\n");
    printf("1. Print\n");
    printf("2. Add\n");
    printf("3. Remove\n");
    printf("4. Exit\n\n");
    std::cin >> t;
    switch (t) {
        case 0:  clear();    break;
        case 1:  print();    break;
        case 2:  add();      break;
        case 3:  remove();   break;
        case 4:  save();     break;
        default: t23();      break;
    }
}
int main() {
    t23();
    return 0;
}
