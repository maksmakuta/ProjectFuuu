#ifndef CONSOLE_H
#define CONSOLE_H

#include <QVector>
#include <QList>
#include <QTextStream>
#include <QString>
#include <QDebug>

using namespace Qt;

QTextStream cout(stdout);
QTextStream cin(stdin);

template <typename T> T in(QString m){
    T s;
    if(m.size() > 0){
        cout << m;  cout.flush();
    }
    cin >> s;
    return s;
}

void console(QString m){
    if(m.size() > 0){
        cout << m;  cout.flush();
    }
}



#endif // CONSOLE_H
