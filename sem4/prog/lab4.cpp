#include "console.h"

QVector<int> integers;
QVector<QString> words;

void task21(){
    int s = in<int>("Enter size of vector : ");
    integers.reserve(s);

    for(int a = 0;a < s;a++){
        int tmp = in<int>("");
        integers << tmp;
    }

    qDebug() << integers;

    int i = in<int>("Enter element to find : ");
    bool isFind = false;
    for(int q = 0;q < integers.size();q++){
        if(integers[q] == i){
            qDebug() << "Find!! Pos :" << q;
            if(!isFind) isFind = true;
        }
    }
    if(!isFind) qDebug() << "Elements not found...";
}

void task22(){
    int app = in<int>("Count to append to vector : ");
    for(int a = 0;a < app;a++){
        int tmp = in<int>("");
        integers.append(tmp);
    }
    int prep = in<int>("Count to prepend to vector : ");
    for(int a = 0;a < prep;a++){
        int tmp = in<int>("");
        integers.prepend(tmp);
    }

    qDebug() << integers;
    qDebug() << "Size : " << integers.size();
}

void task23(){
    int s = in<int>("Enter size of vector : ");
    words.reserve(s);

    for(int a = 0;a < s;a++){
        QString tmp = in<QString>("");
        words << tmp;
    }

    qDebug() << words;

    QString i = in<QString>("Enter element to find : ");
    bool isFind = false;
    for(int q = 0;q < words.size();q++){
        if(words[q] == i){
            qDebug() << "Find!! Pos :" << q;
            if(!isFind) isFind = true;
            QString repl = in<QString>("Enter new word : ");
            words[q] = repl;
        }
    }
    if(!isFind) qDebug() << "Elements not found...";
}

void task24(){
    for(int q = 0;q < words.size();q++){
        if(q % 2 == 0){
            QString repl = in<QString>("Enter new word : ");
            words[q] = repl;
        }
    }

    qDebug() << words;
    qDebug() << "Size : " << words.size();
}

QList<float> floats;
QList<QString> wordList;


void task31(){
    int s = in<int>("Enter size of vector : ");
    floats.reserve(s);

    for(int a = 0;a < s;a++){
        float tmp = in<float>("");
        floats << tmp;
    }

    qDebug() << floats;

    float i = in<float>("Enter element to find : ");
    bool isFind = false;
    for(int q = 0;q < floats.size();q++){
        if(floats[q] == i){
            qDebug() << "Find!! Pos :" << q;
            if(!isFind) isFind = true;
        }
    }
    if(!isFind) qDebug() << "Elements not found...";
}

void task32(){
    int app = in<int>("Count to append to vector : ");
    for(int a = 0;a < app;a++){
        float tmp = in<float>("");
        floats.append(tmp);
    }
    int prep = in<int>("Count to prepend to vector : ");
    for(int a = 0;a < prep;a++){
        float tmp = in<float>("");
        floats.prepend(tmp);
    }

    qDebug() << floats;
    qDebug() << "Size : " << floats.size();
}

void task33(){
    int s = in<int>("Enter size of vector : ");
    wordList.reserve(s);

    for(int a = 0;a < s;a++){
        QString tmp = in<QString>("");
        wordList << tmp;
    }

    qDebug() << wordList;

    QString i = in<QString>("Enter element to find : ");
    bool isFind = false;
    for(int q = 0;q < wordList.size();q++){
        if(wordList[q] == i){
            qDebug() << "Find!! Pos :" << q;
            if(!isFind) isFind = true;
            wordList.removeAt(q);
        }
    }
    if(!isFind) qDebug() << "Elements not found...";
    qDebug() << wordList;
}

void task34(){
    wordList.clear();
    qDebug() << wordList;
    qDebug() << "Size : " << wordList.size();
}


int main(){
    task33();
    task34();
    return 0;
}
