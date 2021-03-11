//settings.cpp 
#ifndef SETTINGS_H
#define SETTINGS_H

//#define Task
#define t3
#define pos 2

#endif // SETTINGS_H


//mainwindow.cpp
#include "mainwindow.h"
#include "settings.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    QLabel* lLabel = new QLabel(this);
#ifdef t3
    lLabel->setText("I label red!!!");
    #if pos == 3
    lLabel->setAlignment(Qt::AlignRight | Qt::AlignTop );
    #elif pos == 2
    lLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter );
    #elif pos == 1
    lLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop );
    #else
    lLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter );
    #endif
    QFont f("Times New Roman",30);
    lLabel->setFont(f);
    lLabel->setStyleSheet("QLabel{color:red;}");

#else
    lLabel->setGeometry(50,0,100,30);
    lLabel->setText("Text Label");
#endif

    QPushButton* lpb = new QPushButton(this);

#ifdef t3
    lpb->setText("Click MEEEEEEEEEEEEE!!!");

    QFont f2("Times New Roman",30);
    lpb->setFont(f2);
    lpb->setGeometry(50,50,100,30);
    lpb->setStyleSheet("QPushButton{color:yellow;}");

#else
    lpb->setGeometry(50,50,100,30);
    lpb->setText("PushButton");
#endif
    QLineEdit* lle = new QLineEdit(this);
    lle->setGeometry(50,100,100,30);
    lle->setText("LineEdit");
    lle->selectAll();

    setGeometry(x(),y(),300,150);
    setWindowTitle("Parent Widget Example");
}

MainWindow::~MainWindow()
{

}


// mainwindow.h
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

// main.cpp
#include <QApplication>
#include "mainwindow.h"
#include "settings.h"

int main( int lArgc , char* lArgv[] ){
    QApplication lApplication(lArgc , lArgv );
    #ifdef Task
        QLabel lLabel;
        lLabel.setText("IamWidget!");
        lLabel.setGeometry(200,200,300,150);
        lLabel.setAlignment(Qt::AlignHCenter | Qt::AlignTop );
        QFont lBlackFont ("ArialBlack",12);
        lLabel.setFont(lBlackFont);
        lLabel.show();
    #else
        MainWindow m;
        m.move(100,200);
        m.show();
    #endif
    return lApplication.exec();
}
