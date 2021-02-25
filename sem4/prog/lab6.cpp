#include "../lab4/console.h"

void task1(){
    QMap<QString,float> list;
    int a = 0;
    qDebug() << "Menu:";
    qDebug() << "   1.print";
    qDebug() << "   2.add";
    qDebug() << "   3.remove";
    qDebug() << "   4.min_max";
    qDebug() << "   5.exit";

    while(true){
        a = in<int>(" -> ");
        switch(a){
        case 1:
            qDebug() << list;
            break;
        case 2 :{
            int s = in<int>("Amount to add : ");
            for(int a = 0;a < s;a++){
                QString n = in<QString>("");
                float m = in<float>("");
                list.insert(n,m);
            }
        }
            break;
        case 3:{
            QString r = in<QString>("Element to remove : ");
            list.remove(r);
        }
            break;
        case 4: {
            if(list.empty())qDebug() << "List is empty";
            else{
            QMap<QString,float>::Iterator minPos = 0, maxPos = 0;
            float min = 5.0f,max = 0.0f;
            QMap<QString, float>::Iterator i = list.begin();
            while (i != list.end()) {

                if(i.value() > max){
                    maxPos = i;
                    max = i.value();
                }

                if(i.value() < min){
                    minPos = i;
                    min = i.value();
                }
                i++;
            }

            qDebug() << minPos.key() << " : " << minPos.value() ;
            qDebug() << maxPos.key() << " : " << maxPos.value() ;
            }
        } break;
        }

        if(a == 5)
            break;
    }
}

void task2(){
    QMultiMap<QString,QString> list;
    int a = 0;
    qDebug() << "Menu:";
    qDebug() << "   1.print";
    qDebug() << "   2.add";
    qDebug() << "   3.remove";
    qDebug() << "   4.find";
    qDebug() << "   5.exit";

    while(true){
        a = in<int>(" -> ");
        switch(a){
        case 1:
            qDebug() << list;
            break;
        case 2 :{
            int s = in<int>("Amount to add : ");
            for(int a = 0;a < s;a++){
                QString n = in<QString>("");
                QString m = in<QString>("");
                list.insert(n,m);
            }
        }
            break;
        case 3:{
            QString r = in<QString>("Element to remove : ");
            list.remove(r);
        }
            break;
        case 4: {
            QString k = in<QString>("Enter surname to find : ");
            QMap<QString,QString>::Iterator i = list.begin();
            bool isFind = false;
            while (i != list.end()) {
                if(i.key() == k){
                    qDebug() << i.key() << " : " << i.value();
                    if(!isFind) isFind = true;
                }
                i++;
            }
            if(!isFind)qDebug() << "Incorrect school number";

        } break;
        }

        if(a == 5)
            break;
    }
}


void task3(){
    QHash<QString,QString> list;
    int a = 0;
    qDebug() << "Menu:";
    qDebug() << "   1.print";
    qDebug() << "   2.add";
    qDebug() << "   3.remove";
    qDebug() << "   4.find";
    qDebug() << "   5.exit";

    while(true){
        a = in<int>(" -> ");
        switch(a){
        case 1:
            qDebug() << list;
            break;
        case 2 :{
            int s = in<int>("Amount to add : ");
            for(int a = 0;a < s;a++){
                QString n = in<QString>("");
                QString m = in<QString>("");
                list.insert(n,m);
            }
        }
            break;
        case 3:{
            QString r = in<QString>("Element to remove : ");
            list.remove(r);
        }
            break;
        case 4: {
            QString k = in<QString>("Enter word to find : ");
            QHash<QString,QString>::Iterator i = list.begin();
            bool isFind = false;
            while (i != list.end()) {
                if(i.key() == k){
                    qDebug() << i.key() << " : " << i.value();
                    if(!isFind) isFind = true;
                }
                i++;
            }
            if(!isFind)qDebug() << "Incorrect school number";

        } break;
        }

        if(a == 5)
            break;
    }
}

void task4(){
    QMultiHash<int,QString> list;
    int a = 0;
    qDebug() << "Menu:";
    qDebug() << "   1.print";
    qDebug() << "   2.add";
    qDebug() << "   3.remove";
    qDebug() << "   4.find";
    qDebug() << "   5.exit";

    while(true){
        a = in<int>(" -> ");
        switch(a){
        case 1:
            qDebug() << list;
            break;
        case 2 :{
            int s = in<int>("Amount to add : ");
            for(int a = 0;a < s;a++){
                int n = in<int>("");
                QString m = in<QString>("");
                list.insert(n,m);
            }
        }
            break;
        case 3:{
            int r = in<int>("Element to remove : ");
            list.remove(r);
        }
            break;
        case 4: {
            int k = in<int>("Enter school num to find : ");
            QMultiHash<int,QString>::Iterator i = list.begin();
            bool isFind = false;
            while (i != list.end()) {
                if(i.key() == k){
                    qDebug() << i.key() << " : " << i.value();
                    if(!isFind) isFind = true;
                }
                i++;
            }
            if(!isFind)qDebug() << "Incorrect school number";

        } break;
        }

        if(a == 5)
            break;
    }
}

int main(){
    task4();
}
