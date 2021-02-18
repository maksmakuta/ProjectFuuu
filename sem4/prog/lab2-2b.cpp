#include <QtCore>
#include <QDebug>

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

int main(/*int argc, char *argv[]*/){
   Person person("Maks","+38067186482","Lutsk, Peremohy str., build 24a, 2");
   qDebug() << person;
}
