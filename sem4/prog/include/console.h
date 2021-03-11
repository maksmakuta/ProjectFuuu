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
#include <QFile>
#include <iostream>

using namespace Qt;

QTextStream cout(stdout);
QTextStream cin(stdin);

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

void cat(QString name){
    QFile f(name);
    if(!f.open(QIODevice::ReadOnly)) {
        console("error" + f.errorString());
    }

    QTextStream in(&f);

    while(!in.atEnd()) {
        console(in.readLine());
    }
    console("\n");
    f.close();
}

template <typename T> T in(QString m){
    T s;
    if(m.size() > 0){
        cout << m;  cout.flush();
    }
    cin >> s;
    return s;
}

template <typename T> void print(T m){
    qDebug() << m;
}

template <typename T> void echo(QFile &f, T data, char e = ' '){
    assert(f.isOpen());
    QTextStream stream(&f);
    stream << data << e;
}



#endif // CONSOLE_H
