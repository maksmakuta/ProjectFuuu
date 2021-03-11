#include <QApplication>
#include <QIcon>
#include <QWidget>

#define t 3


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if t == 1
       QWidget window;
       window.resize(250, 150);
       window.setWindowTitle("Simple example");
       window.show();
#elif t == 2
    QWidget window;
      window.resize(250, 150);
      window.move(300, 300);
      window.setWindowTitle("ToolTip");
      window.setToolTip("QWidget");
      window.show();
#elif t == 3
    QWidget window;
      window.resize(250, 150);
      window.setWindowTitle("Icon");
      window.setWindowIcon(QIcon("shit.png"));
      window.show();
#endif
     return a.exec();
}
