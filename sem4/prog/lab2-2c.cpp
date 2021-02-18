#include <QtCore>
#include <QDebug>

float f1(float x){
    return cos(x);
}

float f2(float x){
    return (x*x)+(x/2);
}

int main(/*int argc, char *argv[]*/){
    for(float a = 0.0f; a < 1.0f;a+= 0.1f){
        qDebug() << f1(a);
    }
        qDebug() << "\n\n";
    for(float b = 2.0f; b < 10.0f;b+= 0.1f){
        qDebug() << f2(b);
    }
}
