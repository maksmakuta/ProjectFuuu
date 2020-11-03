#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//3, 26, 12, 22

void t3(){
    std::ofstream f("f.txt");
    std::ofstream g("g.txt");

    f.clear();
    g.clear();

    int num;

    for(int a = 1; a <= 150;a++)
        f << std::to_string(a) << " ";

    f.close();

    std::ifstream ifs("f.txt");
    std::string numData;
    while(ifs >> numData){
        num = std::stoi(numData);
        if(num % 3 == 0 && num % 7 != 0 )
            g << num << " ";

    }
    printf("Task3 finish -> true");
}

void t26(){
    std::ofstream f("f1.txt");
    f.clear();
    f << "1 3 4 2 5 7 8 16 44 77 10"; // specify data
    f.close();

    std::ifstream f1("f1.txt");
    f1.clear();
    std::vector<int> data;
    std::string n;
    while (f1 >> n){
        int num = std::stoi(n);
        data.push_back(num);
    }
    std::sort(data.begin(), data.end());
    f1.close();

    std::ofstream f2("f1.txt");
    f2.clear();

    for(int a : data){
        f2 << a << " ";
    }
    f2.close();


    std::ifstream F("f1.txt");
    std::ofstream g1("g1.txt");
    std::ofstream g2("g2.txt");

    g1.clear();
    g2.clear();


    while (F >> n){
        int num = std::stoi(n);

        if(num % 2 == 0){
            g1 << num << " ";
        } else{
            g2 << num << " ";
        }
    }


}

void t12(){
    std::ofstream f("f.txt");
    f.clear();
    f << "смородина яблука груші сливи абрикоси порічки"; // specify data
    f.close();

    std::string t;
    std::vector<std::string>  d;
    std::ofstream g("g.txt");
    g.clear();
    std::ifstream fr("f.txt");
    while(fr >> t){
        d.push_back(t);
    }

    for(int a = d.size(); a >= 0; a--){
        g << d[a] << " ";
    }
    fr.close();
    g.close();

}

void t22(){
    int i = 0;
    double m;
    std::ofstream f("f.txt");
    f.clear();
    f << "-5.5 3.2 12.1 -4.3 7.9 14.03 5.5 34";
    f.close();


    std::ifstream F("f.txt");
    int pos = 1;
    double num;
    std::string n;
    while(F >> n){
        num = std::stod(n);
        printf("n = %f\n",num);
        if(num >= 0.2 && num <= 0.9){
            i++;
        }

        if(num > m && pos % 2 ==0){
            m = num;
        }
        pos++;
    }

    F.close();

    printf("Count [0.2,0.9] -> %i\n",i);
    printf("Maximum         -> %f\n",m);

}

int main() {
    t22();
    return 0;
}
