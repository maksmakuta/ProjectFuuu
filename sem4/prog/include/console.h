#ifndef CONSOLE_H
#define CONSOLE_H

#include <QVector>
#include <QList>
#include <QStringList>
#include <QSet>

#include <QMap>
#include <QMultiMap>

#include <QHash>
#include <QMultiHash>

#include <QTextStream>
#include <QString>
#include <QDebug>

#include <iostream>

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

QString inLine(QString m){
    std::string str;
    if(m.size() > 0){
        cout << m;  cout.flush();
    }
    std::getline(std::cin, str);
    return QString::fromStdString(str);
}

void console(QString m){
    if(m.size() > 0){
        cout << m;  cout.flush();
    }
}



#endif // CONSOLE_H
