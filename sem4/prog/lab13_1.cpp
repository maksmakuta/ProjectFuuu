#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QValidator>
#include <QLabel>
#include <QAction>
#include <QKeyEvent>
#include <QMenuBar>
#include <QMenu>

typedef QString str;

long ConvertTo10(const str& input, int base){
    if(base < 2 || base > 36) return 0;
    bool isNegative = (input[0] == '-');
    int startIndex = input.length()-1;
    int endIndex   = isNegative ? 1 : 0;
    long value = 0;
    int digitValue = 1;
    for(int i = startIndex; i >= endIndex; --i){
        char c = input.at(i).cell();
        if(c >= 'a' && c <= 'z') c -= ('a' - 'A');
        if(c >= '0' && c <= '9') c -= '0';
        else c = c - 'A' + 10;
        if(c >= base) return 0;
        value += c * digitValue;
        digitValue *= base;
    }
    if(isNegative)
        value *= -1;
    return value;
}

str ConvertFrom10(long value, int base){
    if(base < 2 || base > 36)
        return "0";
    bool isNegative = (value < 0);
    if(isNegative)
        value *= -1;
    str output;
    do
    {
        char digit = value % base;
        if(digit < 10)
            digit += '0';
        else
            digit = digit + 'A' - 10;
        output += digit;
        value /= base;
    } while (value > 0);
    if(isNegative)
        output += '-';
    int len = output.size() - 1;
    for(int i = 0; i < len; ++i)
    {
        QChar temp = output.at(i);
        output[i] = output[len-i];
        output[len-i] = temp;
    }

    return output;
}

str ConvertBase(const str& input, int baseFrom, int baseTo){
    return ConvertFrom10(ConvertTo10(input, baseFrom), baseTo);
}

class Window : public QMainWindow{
private:

    QLineEdit* data;
    QLineEdit* fromBase;
    QLineEdit* toBase;
    QLCDNumber* num;

    QAction  *quitAction ,*clearAction;
    QAction *oStyle,*flStyle,*fStyle;

public:
    Window(QWidget* parent = 0) : QMainWindow(parent){
        num = new QLCDNumber(this);
        QPushButton* convertBtn = new QPushButton("Convert",this);
        data = new QLineEdit(this);
        fromBase = new QLineEdit(this);
        toBase = new QLineEdit(this);

        QVBoxLayout* m = new QVBoxLayout(this);
        m->addWidget(num);
        m->addWidget(data);
        QHBoxLayout* m1 = new QHBoxLayout(this);
        m1->addWidget(fromBase);
        m1->addWidget(new QLabel(" -> ", this));
        m1->addWidget(toBase);
        m->addLayout(m1);
        m->addWidget(convertBtn);
        QWidget *main = new QWidget(this);
        main->setLayout(m);
        setCentralWidget(main);


        quitAction  = new QAction("&Quit", this);
        clearAction = new QAction("&Clear", this);

        oStyle  = new QAction("OutlineStyle", this);
        flStyle = new QAction("FiledStyle", this);
        fStyle  = new QAction("FlatStyle", this);

        QMenu *app = menuBar()->addMenu("App");
        app->addAction(clearAction);
        app->addAction(quitAction);

        QMenu *info = menuBar()->addMenu("Styles");
        info->addAction(oStyle);
        info->addAction(flStyle);
        info->addAction(fStyle);


        connect(convertBtn, &QPushButton::clicked, this, &Window::convert);
        connect(oStyle, &QAction::triggered, this, &Window::setOStyle);
        connect(flStyle, &QAction::triggered, this, &Window::setFlStyle);
        connect(fStyle, &QAction::triggered, this, &Window::setFStyle);

        connect(clearAction, &QAction::triggered, this, &Window::clean);
        connect(quitAction, &QAction::triggered, &QApplication::quit);
        setWindowTitle("Number Converter @ MaksMakuta");

    }
protected:
      void keyPressEvent(QKeyEvent * e){
          switch (e->key()) {
              case Qt::Key_Q:
              case Qt::Key_Escape:
                   qApp->quit();
                  break;

              case Qt::Key_C:
                  clean();
                  break;

              default:
                  break;
          }
      }

private slots:
    void convert(){
    num->display(ConvertBase(data->text(),fromBase->text().toInt(),toBase->text().toInt()));
    }
    void clean(){
        data->setText(nullptr);
        fromBase->setText(nullptr);
        toBase->setText(nullptr);
    }
    void setOStyle(){
        num->setSegmentStyle(QLCDNumber::Outline);
    }
    void setFlStyle(){
        num->setSegmentStyle(QLCDNumber::Filled);
    }
    void setFStyle(){
        num->setSegmentStyle(QLCDNumber::Flat);
    }
};

int main(int aefefnkwrgwg, char**jefnaeujfbao){
    QApplication app(aefefnkwrgwg,jefnaeujfbao);
    Window w;
    w.resize(450,350);
    w.show();
    return app.exec();
}
