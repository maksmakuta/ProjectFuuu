#include <QApplication>
#include <QBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QTextEdit>

using namespace Qt;

class Window2 : public QMainWindow{
public:
    Window2(QWidget *parent = nullptr){
        init();
    }

private:

    void init(){
        boxinit(QBoxLayout::BottomToTop,300,800,400,200,1,2,3);
        boxinit(QBoxLayout::TopToBottom,300,100,400,200,1,3,2);
        boxinit(QBoxLayout::LeftToRight,  0,300,500,400,1,5,1);
        boxinit(QBoxLayout::RightToLeft,600,300,500,400,2,4,1);
        setFixedSize(1000,1000);
    }

    QBoxLayout* boxinit(QBoxLayout::Direction t,int x,int y,int w,int h,int s1, int s2, int s3){

        QBoxLayout *box = new QBoxLayout(t);
        QLabel *l1 = new QLabel(this);
        QPushButton *b1 = new QPushButton(this);
        QTextEdit *e1 = new QTextEdit(this);
        l1->setText("Label");
        b1->setText("Button");
        e1->setText("EditText");
        box->addWidget(l1,s1);
        box->addWidget(b1,s2);
        box->addWidget(e1,s3);
        box->setGeometry(QRect(x,y,w,h));

        return box;
    }
};
class Window3 : public QWidget{
public:
    Window3(bool b = false,QWidget *parent = nullptr) : QWidget(parent){
        this->bg = b;
        init();
    }

private:
    bool bg;
    QGridLayout *grid;

    void init(){
        grid = new QGridLayout(this);
        grid->addWidget(genFrame( 0,QFrame::NoFrame     ,"#ff00ff",CrossCursor       ,"pic2.jpg"),0,0);
        grid->addWidget(genFrame( 3,QFrame::Box         ,"#ff0000",WaitCursor        ,"tex1.jpg"),0,1);
        grid->addWidget(genFrame( 7,QFrame::Panel       ,"#0000ff",SizeAllCursor     ,"col2.jpg"),1,0);
        grid->addWidget(genFrame(10,QFrame::StyledPanel ,"#ffff00",ForbiddenCursor   ,"pic1.jpeg"),1,1);
        grid->addWidget(genFrame(50,QFrame::HLine       ,"#00ff00",BusyCursor        ,"tex2.jpg"),2,0);
        grid->addWidget(genFrame(20,QFrame::VLine       ,"#00ffff",PointingHandCursor,"col1.jpg"),2,1);

        //grid->setGeometry(QRect(0,0,1920,1080));
        setLayout(grid);
    }

    QFrame* genFrame(int l,QFrame::Shape s,QString color,QCursor cur,QString background){
        QFrame *f = new QFrame(this);
        f->setLineWidth(l);
        f->setFrameStyle(s);
        f->setStyleSheet("QToolTip { color: #ffffff; background-color: #000000; border: 0px; } QFrame {background-color: " + color +"; }");
        f->setCursor(cur);
        QString tt = getInfo(l,s,color,cur);
        f->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Preferred );
        f->setToolTip(tt);

        if(bg){
            QWidget *ch = new QWidget(f);
            QPalette pal;
            pal.setBrush(ch->backgroundRole(), QBrush(QPixmap(background)));
            ch->setPalette(pal);
            ch->setAutoFillBackground(true);
            ch->setGeometry(20,20,640,300);
        }

        return f;
    }

    QString getInfo(int a1,QFrame::Shape s,QString color,QCursor cur){
        QString data;
        data += "lineWidth -> " + QString::number(a1) + "\n";
        data += "style -> " +styleString(s) + "\n";
        data += "color ->" + color + "\n";
        data += "cursorStyle -> " + curString(cur) + "\n";
        return data;
    }

    QString styleString(QFrame::Shape s){
        switch (s) {
            case QFrame::NoFrame     : return "QFrame::NoFrame";
            case QFrame::Box         : return "QFrame::Box";
            case QFrame::Panel       : return "QFrame::Panel";
            case QFrame::StyledPanel : return "QFrame::StyledPanel";
            case QFrame::HLine       : return "QFrame::HLine";
            case QFrame::VLine       : return "QFrame::VLine";
        }
        return "UnknownShape";
    }

    QString curString(QCursor s){
        switch (s.shape()) {
            case CrossCursor        : return "CrossCursor       ";
            case WaitCursor         : return "WaitCursor        ";
            case SizeAllCursor      : return "SizeAllCursor     ";
            case ForbiddenCursor    : return "ForbiddenCursor   ";
            case BusyCursor         : return "BusyCursor        ";
            case PointingHandCursor : return "PointingHandCursor";
        }
        return "UnknownCursor";
    }
};

class Window4 : public QWidget{ //ravesli example
public:
    Window4(QWidget *parent = nullptr) : QWidget(parent){
        init();

        setWindowTitle("Lab9 Task4");
        setWindowIcon(QIcon(QPixmap("icon.png")));
    }

private:

    QPushButton *okBtn;
    QPushButton *applyBtn;

    void init(){
        QVBoxLayout *vbox = new QVBoxLayout(this);
          QHBoxLayout *hbox = new QHBoxLayout();

          okBtn = new QPushButton("OK", this);
          applyBtn = new QPushButton("Apply", this);

          hbox->addWidget(okBtn, 1, Qt::AlignRight);
          hbox->addWidget(applyBtn, 0);

          vbox->addStretch(1);
          vbox->addLayout(hbox);

          setWindowTitle("Buttons");

    }
};


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Window4 w;
    w.resize(500,400);
    w.show();

    /*
    QScrollArea sa; //example 5.1 shleeeeeee
    QWidget* pwgt = new QWidget();
    QPixmap pix("img.jpg");
    QPalette pal;
    pal.setBrush(pwgt->backgroundRole(), QBrush(pix));
    pwgt->setPalette(pal);
    pwgt->setAutoFillBackground(true);
    pwgt->setFixedSize(pix.width(), pix.height());
    sa.setWidget(pwgt);
    sa.resize(350, 150);
    sa.show();
*/
    return a.exec();
}
