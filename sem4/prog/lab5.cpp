#include "../lab4/console.h"

void task21(){
    // Then, they heard a loud noise coming from a cupboard in the corner of the room.
    QString data = inLine("Enter text : ");
    QStringList words = data.split(' ');
    qDebug() << words;

    //Amy and Tara were dancing when Grant arrived, looking worried. “Hi, someone stole my phone. Have you seen Kamal? He said he was coming here at eight o’clock. Can you phone him?” “Go away, idiot!” Tara didn’t stop dancing. Grant looked upset. “Tell him I’m looking for him,” he called as he left the disco. Tara really didn’t like Grant.

    QString data1 = inLine("Enter text : ");
    QStringList words1 = data1.split('.');
    qDebug() << words1;
}

void task22(){
    int s = in<int>("Enter size of list : ");
    QStringList arr;

    for(int a = 0;a < s;a++){
        QString n = inLine("");
        arr << n;
    }

    auto ss = in<QString>("Enter surname for finding : ");
    qDebug() << arr.filter(ss);

}

void task23(){
    // Then, they heard a loud noise coming from a cupboard in the corner of the room.
    QString data = inLine("Enter text : ");
    QStringList words = data.split(' ');
    qDebug() << words;
    auto before = in<QString>("Enter data to replace : ");
    auto after = in<QString>("Enter data : ");
    words.replaceInStrings(before,after);
    qDebug() << words;
}

QSet<QString> s1;
QSet<QString> s2;

void task31(){
    s1.reserve(4);
    s2.reserve(5);

    for(int a = 0;a < 4;a++){
        QString n = in<QString>("");
        s1 << n;
    }

    for(int a = 0;a < 5;a++){
        QString n = in<QString>("");
        s2 << n;
    }

    qDebug() << s1;
    qDebug() << s2;
}

void task32(){
    qDebug() << "unite :" << s1.unite(s2);
    qDebug() << "intersect :" << s1.intersect(s2);
    qDebug() << "minus 2 :" << s1.subtract(s2);
    qDebug() << "minus 1 :" << s2.subtract(s1);
}

void task33(){

    QSet<int> i1;
    QSet<int> i2;

    i1.reserve(4);
    i2.reserve(5);

     for(int a = 0;a < 4;a++){
         int n = in<int>("");
         i1 << n;
     }

     for(int a = 0;a < 5;a++){
         int n = in<int>("");
         i2 << n;
     }

     qDebug() << i1;
     qDebug() << i2;
     qDebug() << "unite :" << i1.unite(i2);
     qDebug() << "intersect :" << i1.intersect(i2);
     qDebug() << "minus 2 :" << i1.subtract(i2);
     qDebug() << "minus 1 :" << i2.subtract(i1);
}

void task40(){
    QStringList list;
    int s = in<int>("Enter size :");
    for(int a = 0;a < s;a++){
        auto str = in<QString>("");
        list << str;
    }
    int pos = 0; int size = 0;

    for(int a = 0;a < list.size();a++){
        if(list[a].size() > size){
            size = list[a].size();
            pos = a;
        }
    }

    qDebug() << "Longest word : " << list[pos];
    qDebug() << "Longest word size : " << list[pos].size();

}

int main(){
    task21();
    task22();
    task23();
    task31();
    task32();
    task33();
    task40();
    return 0;
}
