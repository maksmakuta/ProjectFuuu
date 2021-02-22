#include <QtCore>

void header(int taskNum){
    qDebug() << "###################  " << taskNum << "  ##################" << Qt::endl;
}

void task1(){
    QString str1 = "This is a string data...";
    QString str2("Another string in constructor...");
    QChar chars[25] = {'S','t','r','i','n','g',' ','f','r','o','m',' ','c','h','a','r',' ','a','r','r','a','y','.','.','.'};
    QString str3(chars,25);
    qDebug() << str1 << Qt::endl << str2 << Qt::endl  << str3;
}

void task2(){
    int data[5] = {12,45,15,10,9};
    QString text = QString("In shop we can buy %1 apples, %2 bananas, %3 cherry, %4 blueberris and %5 mandarins...")
            .arg(data[0]).arg(data[1]).arg(data[2]).arg(data[3]).arg(data[4]);
    qDebug() << text;
}

void task3(){
    QString text = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr sit";
    for(int a = 0;a < text.size();a++){
        if(text.at(a) == 's'){
            text.replace(a,1,"@");
        }
    }
    qDebug() << text;
    for(int a = 0;a < text.size();a++){
        if(text.at(a) == 'o'){
            text.replace(a,1,"SS");
        }
    }
    qDebug() << text;
}

void stat(QString text){
    int digits = 0,punct = 0,spaces = 0;
    for(int a = 0;a < text.size();a++){
        if(text[a].isDigit()) digits++;
        if(text[a].isPunct()) punct++;
        if(text[a].isSpace()) spaces++;
    }

    qDebug() << "   All : " << text.size();
    qDebug() << " Punct : " << punct;
    qDebug() << "Spaces : " << spaces;
    qDebug() << "Digits : " << digits;
}

void task4(){
    QStringList list = {"One","two","three","Four","Five","Six","seven","Eight","Nine","Ten","Eleven","Twelve","Tween","ZeRo","Zen","Teen"};
    list.sort(Qt::CaseInsensitive);
    qDebug() << list << Qt::endl;
    list.sort();
    qDebug() << list << Qt::endl;
}

void task5(){
        QString text = "Hello World, - said Prog96, is my first app...";
        stat(text);
        text.insert(0,"Nothings???");
        text.prepend("Intro.");
        text.append("END...");
        stat(text);
}

void task6(){
    QString text = "Hello _ World!!!";
    int a = 1513550,b = 461261;
    text.append(QString::number(a));
    text.prepend(QString::number(b));
    qDebug() << text;

    QString text2 = "15846151 Cube word";
    int p = 0;
    while(true){
        if(text2[p] == ' '){
            break;
        }else{
            p++;
        }
    }
    QString strNum = text2.left(p);
    int num = strNum.toInt();
    qDebug() << num;
}

int main(){
    header(1);
    task1();
    header(2);
    task2();
    header(3);
    task3();
    header(4);
    task4();
    header(5);
    task5();
    header(6);
    task6();
}
