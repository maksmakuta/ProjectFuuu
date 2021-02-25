#include <QtCore>
#include <QDebug>
#define W 20
#define H W*2

QTextStream cout(stdout);

void task4b(){
    srand(time(nullptr));
    int q = 0;
    int s = 7;
    for(int x = 0;x < 7;x++){
        for(int y = 0;y < 7;y++){
            if(x < 4){
                if(y >= q && y < s )
                    cout << rand()%10 << " ";
                else
                    cout << 0 << " ";
            }else{
                cout << 0 << " ";
            }
        }
        cout << '\n';
        q++;
        s--;
    }


    cout << "\n\n\n";
    q = 1;
    s = 7;
    for(int x = 0;x < 7;x++){
        for(int y = 0;y < 7;y++){
          if(y < q){
              cout << rand()%10 << " ";
          }else{
              cout << 0 << " ";
            }
        }
        cout << '\n';

        if(q == 4){
            s = 0;
        }
        if(s == 0)
            q--;
        else
            q++;
    }
}


void task4a(){

    for(int x = 0;x < W;x++){
        for(int y = 0;y < H;y++){

        if(x == 0 /*|| x == W-1*/){
            if(y < (H/2)-4)
                cout << '[';
            else if(y > (H/2)+4)
                cout << ']';
            else
                cout << " ";
        }


        if(x > 0 && x < 4){
            if(y == 0 || (x == 3 && (y > (H/2)-11 && y < (H/2)-5)))
                cout << '[';
            else if(y == H-1 || (x == 3 && (y > (H/2)+5 && y < (H/2)+11)))
                cout << ']';
            else if(y < (H/2)-4)
                cout << ':';
            else if(y > (H/2)+4)
                cout << ':';
            else
                cout << " ";
        }

        if(x > 3 && x < W- 4){
            if(y == 0 ||  y == (H/2)-11)
                cout << '[';
            else if(y == H-1 ||  y == (H/2)+11)
                cout << ']';
            else if(y < (H/2)-10)
                cout << ':';
            else if(y > (H/2)+10)
                cout << ':';
            else
                cout << " ";
        }


        if(x > W - 5 && x < W-1){

            if(y == 0 || (x == W-4 && (y > (H/2)-11 && y < (H/2)-5)))
                cout << '[';
            else if(y == H-1 || (x == W-4 && (y > (H/2)+5 && y < (H/2)+11)))
                cout << ']';
            else if(y < (H/2)-4)
                cout << ':';
            else if(y > (H/2)+4)
                cout << ':';
            else
                cout << " ";
        }

        if(x == W-1 /*|| x == W-1*/){
            if(y < (H/2)-4)
                cout << '[';
            else if(y > (H/2)+4)
                cout << ']';
            else
                cout << " ";
        }




        }
        cout << '\n';
    }

}


class Point{
private:    int x; int y;
public:
Point(){this->x = 0;this->y = 0;}
Point(int a, int b){this->x = a;this->y = b;}
Point(const Point& obj){this->x = obj.getX();this->y = obj.getY();}
void operator = (Point p){setX(p.getX());setY(p.getY());}
void setX(int nX){this->x = nX;}
int getX(){return x;}
int getX() const{return x;}
void setY(int nY){this->y = nY;}
int getY(){return y;}
int getY() const{return y;}};

Point a,b,c,d;

/*      b       c
 *      *-------*
 *      |       \
 *      |       \
 *      *-------*
 *      a       d
 *
 */

Point load(){
    Point p;
    QTextStream cin(stdin);
    int x(0),y(0);
    cin >> x >> y;
    p.setX(x); p.setY(y);
    return p;
}

bool check(Point a,Point b,Point c){
    bool q = true;
    if(a.getX() != b.getX()){
        q = false;
    }
    if(b.getY() != c.getY()){
        q = false;
    }
    if(c.getX() - a.getX() != c.getX() - b.getX()){
        q = false;
    }
    return q;
}

void task3b(){
    a = load();
    b = load();
    c = load();

    if(check(a,b,c)){
        d.setX(c.getX());
        d.setY(a.getY());

        QTextStream(stdout) << d.getX() << " " << d.getY() << "\n";
    }else{
        QTextStream(stdout) << "Error!!!\n";
    }
}

void task3a(){
     QTextStream cout (stdout);
    QTextStream cin  (stdin );
    QString num;
    cin >> num;
    QChar c;

    c = num[0];
    num[0] = num[2];
    num[2] = c;
    cout << num << "\n";
}

float f1(float x){
    return cos(x);
}

float f2(float x){
    return (x*x)+(x/2);
}

void task2c(){
    for(float a = 0.0f; a < 1.0f;a+= 0.1f){
        qDebug() << f1(a);
    }
        qDebug() << "\n\n";
    for(float b = 2.0f; b < 10.0f;b+= 0.1f){
        qDebug() << f2(b);
    }
}

class Person{
private:
        QString phone;
        QString name;
        QString addr;

public:
Person(){
        this->phone = "null";
        this->name = "null";
        this->addr = "null";
}

Person(QString a, QString b, QString c){
        this->name= a;
        this->phone = b;
        this->addr = c;
}

Person(const Person& obj){
        this->phone = obj.getPhone();
        this->name = obj.getName();
        this->addr = obj.getAddr();
}

void setPhone(QString nPhone){
        this->phone = nPhone;
}

QString getPhone() {
        return phone;
}

QString getPhone() const{
        return phone;
}

void setName(QString nName){
        this->name = nName;
}

QString getName() {
        return name;
}

QString getName() const{
        return name;
}

void setAddr(QString nAddr){
        this->addr = nAddr;
}

QString getAddr() {
        return addr;
}

QString getAddr() const{
        return addr;
}
friend QDebug operator<<(QDebug debug,Person p){
    QDebugStateSaver saver(debug);
    debug.nospace() << "Name    : " << p.getName() << "\n";
    debug.nospace() << "Phone   : " << p.getPhone() << "\n";
    debug.nospace() << "Address : " << p.getAddr() << "\n";
    return debug;
}

};

void task2b(){
   Person person("Maks","+38067186482","Lutsk, Peremohy str., build 24a, 2");
   qDebug() << person;
}

void task2a(){
    
qDebug() << "Build date:"       << QLibraryInfo::buildDate().toString("yyyy-MM-dd");
qDebug() << "Build key:"        << QLibraryInfo::build();
qDebug() << "License Products:" << QLibraryInfo::licensedProducts();
qDebug() << "Licensee:"         << QLibraryInfo::licensee();
qDebug() << "Locations";
qDebug() << " Headers:"         << QLibraryInfo::location(QLibraryInfo::HeadersPath);
qDebug() << " Libraries:"       << QLibraryInfo::location(QLibraryInfo::LibrariesPath);
qDebug() << " Binaries:"        << QLibraryInfo::location(QLibraryInfo::BinariesPath);
qDebug() << " Prefix"           << QLibraryInfo::location(QLibraryInfo::PrefixPath);
qDebug() << " Documentation: "  << QLibraryInfo::location(QLibraryInfo::DocumentationPath);
qDebug() << " Plugins:"         << QLibraryInfo::location(QLibraryInfo::PluginsPath);
qDebug() << " Data:"            << QLibraryInfo::location(QLibraryInfo::DataPath);
qDebug() << " Settings:"        << QLibraryInfo::location(QLibraryInfo::SettingsPath);
//qDebug() << " Demos:"         << QLibraryInfo::location(QLibraryInfo::De);
qDebug() << " Examples:"        << QLibraryInfo::location(QLibraryInfo::ExamplesPath);

}

int main(){
    task2a();
    task2b();
    task2c();
    task3a();
    task3b();
    task4a();
    task4b();
}
