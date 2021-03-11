#include "../include/console.h"

int main(){
    console("_________________ Task1 _________________\n");

    QFile f("data1.txt");
    f.open(QIODevice::WriteOnly);
    QVector<int> l1;
    for(int a = 0;a < 5;a++) l1 << a*a+1;
    for(int obj : qAsConst(l1)) echo(f,obj);
    f.close();
    cat(f.fileName());

    QVector<int> l2;
    for(int a = 0;a < 3;a++) l2 << 3*a;
    l2 += l1; //TODO(std::copy)
    //print(l2);
    std::sort(l2.begin(),l2.end());
    //print(l2);

    f.open(QIODevice::WriteOnly);
    echo(f,'\n');
    for(int obj : qAsConst(l2)) echo(f,obj);
    f.close();
    cat(f.fileName());

    QVector<int> l3;
    for(int a = 0;a < 3;a++) l3 << 5*a;
    l3 += std::reverse(l2); //TODO(std::copy)
    f.open(QIODevice::WriteOnly);
    echo(f,'\n');
    for(int obj : qAsConst(l2)) echo(f,obj);
    f.close();
    cat(f.fileName());

    print(l1);
    print(l2);
    print(l3);

    //qDeleteAll(l1); // int is not deleted...
    //qDeleteAll(l2);
    //qDeleteAll(l3);

    console("_________________ Task2 _________________\n");
    QFile f2("data2.txt");
    f2.open(QIODevice::WriteOnly);
    QMap<int,char> map;
    for(int a = 0;a < 5;a++)map.insert(a*a,'z' - a*2);
    for(QMap<int,char>::Iterator it = map.begin();
        it != map.end();it++)
        echo(f2,*it);
    f2.close();

    std::fill(map.begin(),map.end(),'-');

    f2.open(QIODevice::Append);
    for(QMap<int,char>::Iterator it = map.begin();
        it != map.end();it++)
        echo(f2,*it);
    f2.close();
    cat(f2.fileName());
    console("\n");
    return 0;
}
