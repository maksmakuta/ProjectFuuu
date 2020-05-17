#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*

Абстрактний клас ДАНІ містить віртуальний метод для отримання інформації про набори
даних. Визначити похідні класи ФАЙЛ та КАТАЛОГ. У класі ФАЙЛ задати дані про файл (назва,
розширення, дата і час створення) та методи (перейменування, копіювання, витирання, читання).
У класі ФАЙЛ перевизначити віртуальний метод для отримання інформації про файл. Визначити
похідний клас КАТАЛОГ, який містить масив файлів та методи роботи з ними (отримання
списку файлів каталогу, сортування за назвою, за датою). У класі КАТАЛОГ перевизначити
метод для отримання інформації про каталог (назва, кількість файлів, дата створення).
Пpодемонструвати механізм пізнього зв’язування на прикладі викликів віртуальних функцій.

*/

class Data
{
    public:
    virtual void info() {}
};
class Date
{
private:
    int year,month,day,hour,minute,second;
public:
    Date() {}
    Date(int y,int md,int d,int h,int m,int s)
    {
        this->year = y;
        this->month = md;
        this->day = d;
        this->hour = h;
        this->minute = m;
        this->second = s;
    }

    string toString()
    {
        stringstream ss;
        ss << year;
        ss << ".";
        if(month > -1 && month < 10)
            ss << "0" <<month;
        else
            ss << month;
        ss << ".";
        if(day > -1 && day < 10)
            ss << "0" <<day;
        else
            ss << day;
        ss << " - ";
        if(hour > -1 && hour < 10)
            ss << "0" <<hour;
        else
            ss << hour;
        ss << ":";
        if(minute > -1 && minute < 10)
            ss << "0" <<minute;
        else
            ss << minute;
        ss << ":";
        if(second > -1 && second < 10)
            ss << "0" <<second;
        else
            ss << second;

        return ss.str();
    }

    int getYear()
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
    int getHour()
    {
        return hour;
    }
    int getMinute()
    {
        return minute;
    }
    int getSecond()
    {
        return second;
    }

    void setYear(int y)
    {
        this->year = y;
    }
    void setMonth(int md)
    {
        this->month = md;
    }
    void setDay(int d)
    {
        this->day = d;
    }
    void setHour(int h)
    {
        this->hour = h;
    }
    void setMinute(int m)
    {
        this->minute = m;
    }
    void setSecond(int s)
    {
        this->second = s;
    }

    friend bool operator > (Date d,Date f)
    {
        if(d.getYear() > f.getYear())
        {
            return false;
        }
        else
        {
            if(d.getMonth() > f.getMonth())
            {
                return false;
            }
            else
            {
                if(d.getDay() > f.getDay())
                {
                    return false;
                }
                else
                {
                    if(d.getHour() > f.getHour())
                    {
                        return false;
                    }
                    else
                    {
                        if(d.getMinute() > f.getMinute())
                        {
                            return false;
                        }
                        else
                        {
                            if(d.getSecond() > f.getSecond())
                            {
                                return false;
                            }
                            else
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    Date* operator = (Date &a)
    {
        this->year = a.getYear();
        this->month = a.getMonth();
        this->day = a.getDay();
        this->hour = a.getHour();
        this->minute = a.getMinute();
        this->second = a.getSecond();
        return this;
    }

};
class File : public Data
{
private:
    string name,exp;
    Date createTime;
public:
    File() {}
    File(string n, string e,Date c)
    {
        this->name = n;
        this->exp = e;
        this->createTime = c;
    }
    File(string n, string e,Date* c)
    {
        this->name = n;
        this->exp = e;
        this->createTime = *c;
    }

    string getName()
    {
        return name;
    }
    string getExp()
    {
        return exp;
    }
    Date getCdate() const
    {
        return createTime;
    }

    void rename(string newName)
    {
        this->name = newName;
    }

    File copyTo(File f)
    {
        File file(f.getName(),f.getExp(),f.getCdate());
        return file;
    }
    void deleteFile()
    {
        delete &name;
        delete &exp;
        delete &createTime;
    }

    bool operator < (File &a)
    {
        bool x;
        if(getName() < a.getName())
            x = 1;
        else
            x = 0;
        return x;
    }

    friend bool operator > (File &a,File &b)
    {
        bool x;
        if(a.getCdate() > b.getCdate())
            x = 1;
        else
            x = 0;
        return x;
    }

    friend bool operator > (File const &a,File const &b)
    {
        bool x;
        if(a.getCdate() > b.getCdate())
            x = 1;
        else
            x = 0;
        return x;
    }
    File operator = (File &a)
    {
        File tmp(a.getName(),a.getExp(),a.getCdate());
        return tmp;
    }
    void info()
    {
        cout << "           === INFO ===" << endl;
        cout << "File name : " << name << "." << exp << endl;
        cout << "File created in : " << createTime.toString() << endl;
    }
    void read()
    {
        cout << name << "." << exp << endl;
    }

    ~File() {}

};
class Catalog : public Data
{
private:
    string name;
    vector<File> files;
    Date createDate;
public:
    Catalog() {}
    Catalog(string n,vector<File> f, Date c)
    {
        this->name = n;
        this->createDate = c;
        files.clear();
        files.insert(files.end(),f.begin(),f.end());
    }
    Catalog(string n,vector<File> f, Date *c)
    {
        this->name = n;
        this->createDate = *c;
        files.clear();
        files.insert(files.end(),f.begin(),f.end());
    }

    void info()
    {
        cout << "           === INFO ===" << endl;
        cout << "Name : " << name << endl;
        cout << "Files : " << files.size() << endl;
        cout << "File created in : " << createDate.toString() << endl;
    }

    void sort(int b)
    {

        if(b == 1)
        {
            std::sort(files.begin(),files.end());
        }
        else if(b == 2)
        {
            std::sort(files.begin(),files.end(),greater<File>());
        }
        else
        {
            std::cerr << "Enter correct value!!!" << endl;
        }

    }

    void getList()
    {
        int s = files.size();
        for(int q = 0; q < s; q++)
        {
            files[q].read();
        }
    }

};

int main()
{
    vector<File> dataC;
    File a("File","txt",new Date(2001,10,15,17,15,48)); dataC.push_back(a);
    File b("Fife","fft",new Date(2001,06,15,13,17,48)); dataC.push_back(b);
    File v("Ffle","tft",new Date(2005,11,14,13,15,56)); dataC.push_back(v);
    File c("fdfe","tft",new Date(2020,7,5,10,15,48)); dataC.push_back(c);
    File x("gkue","txt",new Date(2021,5,2,13,8,15)); dataC.push_back(x);
    File z("fhge","txt",new Date(2020,8,1,19,12,7)); dataC.push_back(z);
    File d("zcce","zip",new Date(2019,3,5,2,15,45)); dataC.push_back(d);
    File f("qree","class",new Date(2050,1,1,7,15,41)); dataC.push_back(f);

cout<<endl;
cout << "                           late binding mechanism" << endl;
cout<<endl;
Data *data;

data = new File("bindFile","bf",new Date(2020,5,5,12,0,0));
data->info();
delete data;

data = new Catalog("Catalog",dataC,new Date(2020,5,6,0,12,16));

Catalog cat("Catalogue",dataC,new Date(2053,2,6,18,56,17));
    cat.getList();
    cout<<endl;
    cat.sort(1);
    cat.getList();
    cout<<endl;
    cat.info();
    cout << endl;
    data->info();

delete data;

    return 0;
}
