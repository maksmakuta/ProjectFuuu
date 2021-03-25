#include <QApplication>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow1; }
QT_END_NAMESPACE

class MainWindow1 : public QMainWindow{
    Q_OBJECT

public:
    MainWindow1(QWidget *parent = nullptr): QMainWindow(parent), ui(new Ui::MainWindow){
        ui->setupUi(this);
    }
    ~MainWindow1(){
        delete ui;
    }

private slots:
    void on_add_clicked(){
        float x = ui->a->text().toFloat();
        float y = ui->b->text().toFloat();
        ui->r->setText(QString::number(x+y));
    }

    void on_minus_clicked(){
        float x = ui->a->text().toFloat();
        float y = ui->b->text().toFloat();
        ui->r->setText(QString::number(x-y));
    }

    void on_mul_clicked(){
        float x = ui->a->text().toFloat();
        float y = ui->b->text().toFloat();
        ui->r->setText(QString::number(x*y));
    }

    void on_div_clicked(){
        float x = ui->a->text().toFloat();
        float y = ui->b->text().toFloat();
        ui->r->setText(QString::number(x/y));
    }

    void on_clear_clicked(){
        ui->a->setText("");
        ui->b->setText("");
        ui->r->setText("");
    }

    void on_quit_clicked(){ qApp->exit(); }

private:
    Ui::MainWindow1 *ui;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow2; }
QT_END_NAMESPACE

class MainWindow2 : public QMainWindow{
    Q_OBJECT

public:
     MainWindow2(QWidget *parent = nullptr): QMainWindow(parent), ui(new Ui::MainWindow){
        ui->setupUi(this);
    }
    ~MainWindow2(){
        delete ui;
    }
private slots:
    void on_run_clicked(){
    float a = ui->a_num->text().toFloat();
    float b = ui->b_num->text().toFloat();
    float c = ui->c_num->text().toFloat();

    float D = ( b * b ) - ( 4 * a * c );
        if(D > 0){
            ui->info->setText("Equation has 2 roots : ");
            ui->x1->setText("x1 = " + QString::number((-b - sqrt(D))/2*a));
            ui->x2->setText("x2 = " + QString::number((-b + sqrt(D))/2*a));
        }else if( D == 0){
            ui->info->setText("Equation has 1 root : ");
            ui->x1->setText("x = " + QString::number(-b/2*a));
            // ui->x2->setText(QString::number((-b + sqrt(D))/2*a));
        }else{
            ui->info->setText("Equation has no roots : ");
            ui->x1->setText("");
            ui->x2->setText("");
        }
    }
    void on_clear_clicked(){
        ui->info->setText("");
        ui->x1->setText("");
        ui->x2->setText("");
        ui->a_num->setText("");
        ui->b_num->setText("");
        ui->c_num->setText("");
    }
private:
    Ui::MainWindow2 *ui;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow3; }
QT_END_NAMESPACE

class MainWindow3 : public QMainWindow{
    Q_OBJECT

public:
     MainWindow3(QWidget *parent = nullptr): QMainWindow(parent), ui(new Ui::MainWindow){
        ui->setupUi(this);
    }
    ~MainWindow3(){
        delete ui;
    }
private slots:
    void on_run_clicked(){
    float x = ui->x_num->text().toFloat();
    float y = fun(x);
    ui->res->setText(QString::number(y));

    if(y > 0){
        ui->res->setStyleSheet("background : yellow;");
    }else if(y == 0.0f){
        ui->res->setStyleSheet("background : red;");
    }else{
        ui->res->setStyleSheet("background : #0080ff;");
    }

    if(y > 0){
        ui->centralwidget->setStyleSheet("background : green;");
    }else if(y == 0.0f){
        ui->centralwidget->setStyleSheet("background : red;");
    }else{
        ui->centralwidget->setStyleSheet("background : blue;");
    }

    }
    void on_clear_clicked(){
        ui->x_num->setText("");
        ui->res->setText("");
    }
private:
    Ui::MainWindow2 *ui;
};

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow1 w;
    w.show();
    return a.exec();
}

/* ui MainWindow1
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>305</width>
    <height>128</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <widget class="QWidget" name="centralwidget">
   <property name="minimumSize">
    <size>
     <width>0</width>
     <height>0</height>
    </size>
   </property>
   <property name="maximumSize">
    <size>
     <width>1000</width>
     <height>1000</height>
    </size>
   </property>
   <property name="baseSize">
    <size>
     <width>0</width>
     <height>0</height>
    </size>
   </property>
   <widget class="QWidget" name="horizontalLayoutWidget">
    <property name="geometry">
     <rect>
      <x>0</x>
      <y>10</y>
      <width>301</width>
      <height>111</height>
     </rect>
    </property>
    <layout class="QHBoxLayout" name="horizontalLayout">
     <item>
      <layout class="QVBoxLayout" name="verticalLayout">
       <item>
        <widget class="QLabel" name="label">
         <property name="text">
          <string>A :</string>
         </property>
         <property name="alignment">
          <set>Qt::AlignCenter</set>
         </property>
        </widget>
       </item>
       <item>
        <spacer name="verticalSpacer">
         <property name="orientation">
          <enum>Qt::Vertical</enum>
         </property>
         <property name="sizeHint" stdset="0">
          <size>
           <width>20</width>
           <height>40</height>
          </size>
         </property>
        </spacer>
       </item>
       <item>
        <widget class="QLabel" name="label_2">
         <property name="text">
          <string>B :</string>
         </property>
         <property name="alignment">
          <set>Qt::AlignCenter</set>
         </property>
        </widget>
       </item>
       <item>
        <spacer name="verticalSpacer_2">
         <property name="orientation">
          <enum>Qt::Vertical</enum>
         </property>
         <property name="sizeHint" stdset="0">
          <size>
           <width>20</width>
           <height>40</height>
          </size>
         </property>
        </spacer>
       </item>
       <item>
        <widget class="QLabel" name="label_3">
         <property name="text">
          <string>Результат : </string>
         </property>
         <property name="alignment">
          <set>Qt::AlignCenter</set>
         </property>
        </widget>
       </item>
      </layout>
     </item>
     <item>
      <layout class="QVBoxLayout" name="verticalLayout_2">
       <item>
        <widget class="QLineEdit" name="a"/>
       </item>
       <item>
        <spacer name="verticalSpacer_3">
         <property name="orientation">
          <enum>Qt::Vertical</enum>
         </property>
         <property name="sizeHint" stdset="0">
          <size>
           <width>20</width>
           <height>40</height>
          </size>
         </property>
        </spacer>
       </item>
       <item>
        <widget class="QLineEdit" name="b"/>
       </item>
       <item>
        <spacer name="verticalSpacer_4">
         <property name="orientation">
          <enum>Qt::Vertical</enum>
         </property>
         <property name="sizeHint" stdset="0">
          <size>
           <width>20</width>
           <height>40</height>
          </size>
         </property>
        </spacer>
       </item>
       <item>
        <widget class="QLineEdit" name="r"/>
       </item>
      </layout>
     </item>
     <item>
      <layout class="QVBoxLayout" name="verticalLayout_3">
       <item>
        <widget class="QPushButton" name="add">
         <property name="text">
          <string>+</string>
         </property>
        </widget>
       </item>
       <item>
        <widget class="QPushButton" name="minus">
         <property name="text">
          <string>-</string>
         </property>
        </widget>
       </item>
       <item>
        <widget class="QPushButton" name="mul">
         <property name="text">
          <string>*</string>
         </property>
        </widget>
       </item>
       <item>
        <widget class="QPushButton" name="div">
         <property name="text">
          <string>/</string>
         </property>
        </widget>
       </item>
      </layout>
     </item>
     <item>
      <layout class="QVBoxLayout" name="verticalLayout_4">
       <item>
        <widget class="QPushButton" name="clear">
         <property name="text">
          <string>Очистити</string>
         </property>
        </widget>
       </item>
       <item>
        <widget class="QPushButton" name="quit">
         <property name="text">
          <string>Вийти</string>
         </property>
        </widget>
       </item>
      </layout>
     </item>
    </layout>
   </widget>
  </widget>
 </widget>
 <resources/>
 <connections/>
</ui>
*/

/* UI MainWindow2
 <?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>398</width>
    <height>208</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <widget class="QWidget" name="centralwidget">
   <widget class="QWidget" name="horizontalLayoutWidget">
    <property name="geometry">
     <rect>
      <x>9</x>
      <y>9</y>
      <width>381</width>
      <height>191</height>
     </rect>
    </property>
    <layout class="QHBoxLayout" name="horizontalLayout">
     <item>
      <layout class="QVBoxLayout" name="verticalLayout_2">
       <item>
        <layout class="QHBoxLayout" name="horizontalLayout_4">
         <item>
          <widget class="QLabel" name="label">
           <property name="sizePolicy">
            <sizepolicy hsizetype="Fixed" vsizetype="Preferred">
             <horstretch>0</horstretch>
             <verstretch>0</verstretch>
            </sizepolicy>
           </property>
           <property name="text">
            <string>A</string>
           </property>
           <property name="alignment">
            <set>Qt::AlignCenter</set>
           </property>
          </widget>
         </item>
         <item>
          <widget class="QLineEdit" name="a_num">
           <property name="sizePolicy">
            <sizepolicy hsizetype="Minimum" vsizetype="Fixed">
             <horstretch>0</horstretch>
             <verstretch>0</verstretch>
            </sizepolicy>
           </property>
          </widget>
         </item>
         <item>
          <widget class="QLabel" name="info">
           <property name="text">
            <string/>
           </property>
          </widget>
         </item>
        </layout>
       </item>
       <item>
        <layout class="QHBoxLayout" name="horizontalLayout_2">
         <item>
          <widget class="QLabel" name="label_2">
           <property name="sizePolicy">
            <sizepolicy hsizetype="Fixed" vsizetype="Preferred">
             <horstretch>0</horstretch>
             <verstretch>0</verstretch>
            </sizepolicy>
           </property>
           <property name="text">
            <string>B</string>
           </property>
           <property name="alignment">
            <set>Qt::AlignCenter</set>
           </property>
          </widget>
         </item>
         <item>
          <widget class="QLineEdit" name="b_num">
           <property name="sizePolicy">
            <sizepolicy hsizetype="Minimum" vsizetype="Fixed">
             <horstretch>0</horstretch>
             <verstretch>0</verstretch>
            </sizepolicy>
           </property>
           <property name="maxLength">
            <number>10</number>
           </property>
          </widget>
         </item>
         <item>
          <widget class="QLabel" name="x1">
           <property name="text">
            <string/>
           </property>
          </widget>
         </item>
        </layout>
       </item>
       <item>
        <layout class="QHBoxLayout" name="horizontalLayout_3">
         <item>
          <widget class="QLabel" name="label_3">
           <property name="sizePolicy">
            <sizepolicy hsizetype="Fixed" vsizetype="Preferred">
             <horstretch>0</horstretch>
             <verstretch>0</verstretch>
            </sizepolicy>
           </property>
           <property name="text">
            <string>C</string>
           </property>
           <property name="alignment">
            <set>Qt::AlignCenter</set>
           </property>
          </widget>
         </item>
         <item>
          <widget class="QLineEdit" name="c_num">
           <property name="sizePolicy">
            <sizepolicy hsizetype="Minimum" vsizetype="Fixed">
             <horstretch>0</horstretch>
             <verstretch>0</verstretch>
            </sizepolicy>
           </property>
          </widget>
         </item>
         <item>
          <widget class="QLabel" name="x2">
           <property name="text">
            <string/>
           </property>
          </widget>
         </item>
        </layout>
       </item>
       <item>
        <layout class="QHBoxLayout" name="horizontalLayout_5">
         <item>
          <widget class="QPushButton" name="run">
           <property name="text">
            <string>Solve</string>
           </property>
          </widget>
         </item>
         <item>
          <widget class="QPushButton" name="clear">
           <property name="text">
            <string>Clear</string>
           </property>
          </widget>
         </item>
        </layout>
       </item>
      </layout>
     </item>
    </layout>
   </widget>
  </widget>
 </widget>
 <resources/>
 <connections/>
</ui>

 */

/* ui MainWindow3
 <?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>300</width>
    <height>150</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <widget class="QWidget" name="centralwidget">
   <widget class="QWidget" name="verticalLayoutWidget">
    <property name="geometry">
     <rect>
      <x>9</x>
      <y>9</y>
      <width>281</width>
      <height>131</height>
     </rect>
    </property>
    <layout class="QVBoxLayout" name="verticalLayout">
     <item>
      <widget class="QLabel" name="label">
       <property name="text">
        <string>&lt;img src=&quot;image.png&quot;/&gt;</string>
       </property>
       <property name="alignment">
        <set>Qt::AlignCenter</set>
       </property>
      </widget>
     </item>
     <item>
      <layout class="QHBoxLayout" name="horizontalLayout">
       <item>
        <layout class="QVBoxLayout" name="verticalLayout_3">
         <item>
          <widget class="QLabel" name="label_2">
           <property name="text">
            <string>X</string>
           </property>
          </widget>
         </item>
         <item>
          <widget class="QLineEdit" name="x_num"/>
         </item>
        </layout>
       </item>
       <item>
        <layout class="QVBoxLayout" name="verticalLayout_2">
         <item>
          <widget class="QLabel" name="label_3">
           <property name="text">
            <string>Result</string>
           </property>
          </widget>
         </item>
         <item>
          <widget class="QLineEdit" name="res"/>
         </item>
        </layout>
       </item>
      </layout>
     </item>
     <item>
      <layout class="QHBoxLayout" name="horizontalLayout_2">
       <item>
        <widget class="QPushButton" name="run">
         <property name="text">
          <string>Solve</string>
         </property>
        </widget>
       </item>
       <item>
        <widget class="QPushButton" name="clear">
         <property name="text">
          <string>Clear</string>
         </property>
        </widget>
       </item>
      </layout>
     </item>
    </layout>
   </widget>
  </widget>
 </widget>
 <resources/>
 <connections/>
</ui>
 
 */
