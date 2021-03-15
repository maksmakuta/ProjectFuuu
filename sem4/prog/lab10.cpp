#include <QApplication>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

class Win2_1 : public QMainWindow{
public:
    Win2_1(QWidget* parent = nullptr){
        m = new QVBoxLayout(this);
        QHBoxLayout *l = new QHBoxLayout(this);
        btn1 = new QPushButton("Button 1",this);
        btn2 = new QPushButton("Button 2",this);
        ed1 = new QTextEdit("TextEdit",this);
        l->addWidget(btn1);
        l->addWidget(btn2);
        m->addLayout(l);
        m->addWidget(ed1);
        setLayout(m);
    }
private:

    void resizeEvent(QResizeEvent *event) override{
        QMainWindow::resizeEvent(event);
        m->setGeometry(this->geometry());
    }

    QVBoxLayout *m;
    QPushButton *btn1, *btn2;
    QTextEdit *ed1;
};

class Win2_2 : public QMainWindow{
public:
    Win2_2(QWidget* parent = nullptr){
        m = new QHBoxLayout(this);
        QVBoxLayout *m1 = new QVBoxLayout(this);
        l1 = new QLabel("Label 2",this); m1->addWidget(l1);
        l2 = new QLabel("Label 1",this); m1->addWidget(l2);
        l3 = new QLabel("Label 3",this); m1->addWidget(l3);
        btn = new QPushButton("Button",this);
        m->addLayout(m1);
        m->addWidget(btn);
        setLayout(m);
    }
private:
    void resizeEvent(QResizeEvent *event) override{
        QMainWindow::resizeEvent(event);
        m->setGeometry(this->geometry());
    }
    QHBoxLayout *m;
    QPushButton *btn;
    QLabel *l1,*l2,*l3;
};

class Win2_3 : public QMainWindow{
public:
    Win2_3(QWidget* parent = nullptr){
        m = new QVBoxLayout(this);
        QHBoxLayout *m1 = new QHBoxLayout(this);
        l1 = new QLabel("Label 1",this); m1->addWidget(l1);
        l2 = new QLabel("Label 2",this); m1->addWidget(l2);
        ed = new QTextEdit("TextEdit",this);
        btn = new QPushButton("Button",this);
        m->addWidget(ed);
        m->addLayout(m1);
        m->addWidget(btn);
        setLayout(m);
    }
private:
    void resizeEvent(QResizeEvent *event) override{
        QMainWindow::resizeEvent(event);
        m->setGeometry(this->geometry());
    }
    QVBoxLayout *m;
    QPushButton *btn;
    QLabel *l1,*l2;
    QTextEdit *ed;
};

class Win2_4 : public QMainWindow{
public:
    Win2_4(QWidget* parent = nullptr){
        m = new QHBoxLayout(this);
        QVBoxLayout *m1 = new QVBoxLayout(this);
        QVBoxLayout *m2 = new QVBoxLayout(this);

        l1 = new QLabel("label",this);          m1->addWidget(l1);
        btn = new QPushButton("Button",this);   m1->addWidget(btn);

        ed1 = new QTextEdit("TextEdit 1",this); m2->addWidget(ed1);
        ed2 = new QTextEdit("TextEdit 2",this); m2->addWidget(ed2);
        ed3 = new QTextEdit("TextEdit 3",this); m2->addWidget(ed3);

        m->addLayout(m1);
        m->addLayout(m2);
        setLayout(m);
    }
private:
    void resizeEvent(QResizeEvent *event) override{
        QMainWindow::resizeEvent(event);
        m->setGeometry(this->geometry());
    }
    QHBoxLayout *m;
    QPushButton *btn;
    QLabel *l1;
    QTextEdit *ed1,*ed2,*ed3;
};

class Win3_1 : public QMainWindow{
public:
    Win3_1(QWidget* parent = nullptr){
        main = new QGridLayout(this);
        main->addWidget(button("Button 1"),0,0);
        main->addWidget(button("Button 2"),0,1);
        main->addWidget(button("Button 3"),1,0);
        main->addWidget(button("Button 5"),1,1);
        main->addWidget(button("Button 4"),2,0);
        main->addWidget(button("Button 6"),2,1);
        setLayout(main);
    }
private:
    void resizeEvent(QResizeEvent *event) override{
        QMainWindow::resizeEvent(event);
        main->setGeometry(this->geometry());
    }
    QPushButton* button(QString text){return new QPushButton(text,this); }
    QGridLayout *main;
};

class Win3_2 : public QMainWindow{
public:
    Win3_2(QWidget* parent = nullptr){
        main = new QGridLayout(this);
        main->addWidget(button("Button 2"),0,0);
        main->addWidget(button("Button 3"),0,1);
        main->addWidget(button("Button 1"),0,2);
        main->addWidget(button("Button 4"),1,0);
        main->addWidget(button("Button 5"),1,1);
        main->addWidget(button("Button 6"),1,2);
        setLayout(main);
    }
private:
    void resizeEvent(QResizeEvent *event) override{
        QMainWindow::resizeEvent(event);
        main->setGeometry(this->geometry());
    }
    QPushButton* button(QString text){return new QPushButton(text,this); }
    QGridLayout *main;
};

class Win4_1 : public QWidget{
public:
    Win4_1(QWidget* parent = nullptr){

        QVBoxLayout *vbox = new QVBoxLayout();
        QHBoxLayout *hbox = new QHBoxLayout(this);

        QListWidget *lw = new QListWidget(this);
        lw->addItem("The Omen");
        lw->addItem("The Exorcist");
        lw->addItem("Notes on a scandal");
        lw->addItem("Fargo");
        lw->addItem("Capote");

        QPushButton *add = new QPushButton("Add", this);
        QPushButton *rename = new QPushButton("Rename", this);
        QPushButton *remove = new QPushButton("Remove", this);
        QPushButton *removeall = new QPushButton("Remove All", this);

        vbox->setSpacing(3);
        vbox->addStretch(1);
        vbox->addWidget(add);
        vbox->addWidget(rename);
        vbox->addWidget(remove);
        vbox->addWidget(removeall);
        vbox->addStretch(1);

        hbox->addWidget(lw);
        hbox->addSpacing(15);
        hbox->addLayout(vbox);

        setLayout(hbox);
        setWindowTitle("Layouts");
    }
};

class Win4_2 : public QWidget{
public:
    Win4_2(QWidget* parent = nullptr){

        QLineEdit *nameEdit = new QLineEdit(this);
          QLineEdit *addrEdit = new QLineEdit(this);
          QLineEdit *occpEdit = new QLineEdit(this);

          QFormLayout *formLayout = new QFormLayout;
          formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
          formLayout->addRow("Name:", nameEdit);
          formLayout->addRow("Email:", addrEdit);
          formLayout->addRow("Age:", occpEdit);

          setLayout(formLayout);
        setWindowTitle("Form Example");
    }
};

class Win4_3 : public QWidget{
public:
    Win4_3(QWidget* parent = nullptr){

        QGridLayout *grid = new QGridLayout(this);
          grid->setSpacing(2);

          QList<QString> values({ "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+"
          });

          int pos = 0;

          for (int i=0; i<4; i++) {
           for (int j=0; j<4; j++) {

             QPushButton *btn = new QPushButton(values[pos], this);
             btn->setFixedSize(40, 40);
             grid->addWidget(btn, i, j);
             pos++;
           }
          }
          setLayout(grid);
        setWindowTitle("Calculator");
    }
};

class Win4_4 : public QWidget{
public:
    Win4_4(QWidget* parent = nullptr){

        QGridLayout *grid = new QGridLayout(this);
          grid->setVerticalSpacing(15);
          grid->setHorizontalSpacing(10);

          QLabel *title = new QLabel("Title:", this);
          grid->addWidget(title, 0, 0, 1, 1);
          title->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

          QLineEdit *edt1 = new QLineEdit(this);
          grid->addWidget(edt1, 0, 1, 1, 1);

          QLabel *author = new QLabel("Author:", this);
          grid->addWidget(author, 1, 0, 1, 1);
          author->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

          QLineEdit *edt2 = new QLineEdit(this);
          grid->addWidget(edt2, 1, 1, 1, 1);

          QLabel *review = new QLabel("Review:", this);
          grid->addWidget(review, 2, 0, 1, 1);
          review->setAlignment(Qt::AlignRight | Qt::AlignTop);

          QTextEdit *te = new QTextEdit(this);
          grid->addWidget(te, 2, 1, 3, 1);

          setLayout(grid);
        setWindowTitle("Review");
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win4_4 app;
    //app.resize(700,500);
    app.setWindowIcon(QIcon(QPixmap("icon.png")));
    app.show();
    return a.exec();
}
