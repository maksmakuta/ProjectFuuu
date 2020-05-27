#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;


enum Month {
    Jan = 1,Feb = 2,Mar = 3,Apr = 4,
    May = 5,Jun = 6,Jul = 7,Aug = 8,
    Sep = 9,Oct = 10,Nov = 11,Dec = 12
};
string monthName[13] = {"null","January","February","March",
                        "April","May","June","July","August",
                        "September","October","November","December"};

class DateInterval{
private:
    int date[6];
public:
    DateInterval(){}
    DateInterval(DateInterval const &d){
        date[5] = d.getData()[5];
        date[4] = d.getData()[4];
        date[3] = d.getData()[3];
        date[2] = d.getData()[2];
        date[1] = d.getData()[1];
        date[0] = d.getData()[0];
    }
    DateInterval(DateInterval *d){
        date[5] = d->getData()[5];
        date[4] = d->getData()[4];
        date[3] = d->getData()[3];
        date[2] = d->getData()[2];
        date[1] = d->getData()[1];
        date[0] = d->getData()[0];
    }

    DateInterval(int t[6]) {
        date[5] = t[5];
        date[4] = t[4];
        date[3] = t[3];
        date[2] = t[2];
        date[1] = t[1];
        date[0] = t[0];
    }/*
    DateInterval(Date *f, Date *t){
        date[5] = t->getSecond() -      f->getSecond();
        date[4] = t->getMinute() -      f->getMinute();
        date[3] = t->getHour  () -      f->getHour  ();
        date[2] = t->getDay   () -      f->getDay   ();
        date[1] = t->getMonthNum() -    f->getMonthNum();
        date[0] = t->getYear  () -      f->getYear  ();
    }*/

    string interval(){
        stringstream ss;
        ss << date[0]; ss << "/";
        (int)date[1] < 10 && (int)date[1] > 0 ? ss << "0" << date[1] : ss << date[1];ss << "/";
        date[2] < 10 && date[2] > 0 ? ss << "0" << date[2] : ss <<date[2];ss << " ";
        date[3] < 10 && date[3] > 0 ? ss << "0" << date[3] : ss << date[3];ss << ":";
        date[4] < 10 && date[4] > 0 ? ss << "0" << date[4] : ss << date[4];ss << ":";
        date[5] < 10 && date[5] > 0 ? ss << "0" << date[5] : ss << date[5];
        return ss.str();
    }
    string formatDate(string format){
        istringstream iss(format);
        int it = 0;
        string date[6],word;
        while(iss >> word) {
            stringstream ss(word);
            ss >> date[it];
            it++;
        }
        stringstream ss;
        ss << date[0]; ss << "-";
        (int)date[1].length() < 2  ? ss << "0" << date[1] : ss << date[1];ss << "-";
        date[2].length() < 2  ? ss << "0" << date[2] : ss <<date[2];ss << " ";
        date[3].length() < 2  ? ss << "0" << date[3] : ss << date[3];ss << ":";
        date[4].length() < 2  ? ss << "0" << date[4] : ss << date[4];ss << ":";
        date[5].length() < 2  ? ss << "0" << date[5] : ss << date[5];
        return ss.str();
    }

    int* getData()  {return date;}
    const int* getData() const{return date;}
    void setData(int* a)    { for(int z = 0;z < 6;z++)this->date[z] = a[z];}

    DateInterval& operator = (const DateInterval &b){
        for(int a = 0; a < 6;a++) this->date[a] = b.getData()[a];
        return *this;
    }
    ~DateInterval(){}
};

class Date{
private:
    int second;
    int minute;
    int hour;
    int day;
    Month month;
    int year;
    bool high;
    unsigned  int dayTable[13]= {1,31,28,31,30,31,30,31,30,31,30,31,30};
    unsigned  int dayTableH[13]= {1,31,29,31,30,31,30,31,30,31,30,31,30};

    ////methods
    void calcHigh(unsigned int y){ y % 4 == 0 ? this->high = true : this->high = false;}
public:
    Date(){
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);
        this->year = 1900 + ltm->tm_year;
        calcHigh(year);
        this->month = static_cast<Month>(1 + ltm->tm_mon);
        this->day = ltm->tm_mday;
        this->hour = 1 + ltm->tm_hour;
        this->minute = 1 + ltm->tm_min ;
        this->second = 1 + ltm->tm_sec ;
        normalize();
    }
    Date(Date const &d){
        this->year =    d.getYear();
        calcHigh(year);
        this->month =   d.getMonth();
        this->day =     d.getDay();
        this->hour =    d.getHour();
        this->minute =  d.getMinute();
        this->second =  d.getSecond();
        normalize();
    }
    Date(Date *d){
        this->year =    d->getYear();
        calcHigh(year);
        this->month =   d->getMonth();
        this->day =     d->getDay();
        this->hour =    d->getHour();
        this->minute =  d->getMinute();
        this->second =  d->getSecond();
        normalize();
    }
    Date(unsigned int y,unsigned int mn,unsigned int d,unsigned int h,unsigned int m,unsigned int s){
        this->year =    y;
        calcHigh(year);
        this->month =   (Month)mn;
        this->day =     d;
        this->hour =    h;
        this->minute =  m;
        this->second =  s;
        normalize();
    }
    Date(unsigned int timeData[6]){
        this->year =    timeData[0];
        calcHigh(year);
        this->month =   (Month)timeData[1];
        this->day =     timeData[2];
        this->hour =    timeData[3];
        this->minute =  timeData[4];
        this->second =  timeData[5];
        normalize();
    }
    Date(int timeData[6]){
        this->year =    timeData[0];
        calcHigh(year);
        this->month =   (Month)timeData[1];
        this->day =     timeData[2];
        this->hour =    timeData[3];
        this->minute =  timeData[4];
        this->second =  timeData[5];
        normalize();
    }
    Date(unsigned int y,Month mn,unsigned int d,unsigned int h,unsigned int m,unsigned int s){
        this->year =    y;
        calcHigh(year);
        this->month =   mn;
        this->day =     d;
        this->hour =    h;
        this->minute =  m;
        this->second =  s;
        normalize();
    }
    Date(unsigned int y,Month mn,unsigned int d){
        this->year =    y;
        calcHigh(year);
        this->month =   mn;
        this->day =     d;
        this->hour =    0;
        this->minute =  0;
        this->second =  0;
        normalize();
    }
    Date(unsigned int h,unsigned int m,unsigned int s){
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);
        this->year = 1900 + ltm->tm_year;
        calcHigh(year);
        this->month = static_cast<Month>(1 + ltm->tm_mon);
        this->day = ltm->tm_mday;
        this->hour =    h;
        this->minute =  m;
        this->second =  s;
        normalize();
    }
    /////////////// other methods /////////////
    DateInterval getInterval (const Date & a, const Date & b) const{
        int itv[6];
        itv[5] = a.getSecond() - b.getSecond();
        itv[4] = a.getMinute() - b.getMinute();
        itv[3] = a.getHour  () - b.getHour  ();
        itv[2] = a.getDay   () - b.getDay   ();
        itv[1] = a.getMonthNum() - b.getMonthNum();
        itv[0] = a.getYear  () - b.getYear  ();
        DateInterval intv(itv);
        return intv;
    }

    Date addInterval (const DateInterval & amp){
        int tmp[6];
        for(int q = 0;q < 6;q++)tmp[q] = amp.getData()[q];

        tmp[5] += this->getSecond() ;
        tmp[4] += this->getMinute() ;
        tmp[3] += this->getHour  () ;
        tmp[2] += this->getDay   () ;
        tmp[1] += this->getMonthNum();
        tmp[0] += this->getYear  ();

        Date tmpDate(tmp);
        return tmpDate;
    }

    //////////////set & get ///////////////////
    int getSecond()    {return second; }
    int getMinute()    {return minute; }
    int getHour()      {return hour;   }
    int getDay()       {return day;    }
    Month getMonth()     {return month;  }
    int getMonthNum()  {return (int)month;}
    int getYear()      {return year;   }

    void setSecond(unsigned int s){this->second = s;}
    void setMinute(unsigned int s){this->minute = s;}
    void setHour  (unsigned int s){this->hour   = s;}
    void setDay   (unsigned int s){this->day    = s;}
    void setMonth (       Month s){this->month  = s;}
    void setYear  (unsigned int s){this->year   = s;}
    // const//
    int getSecond()    const {return second; }
    int getMinute()    const {return minute; }
    int getHour()      const {return hour;   }
    int getDay()       const {return day;    }
    Month getMonth()     const {return month;  }
    int getMonthNum()  const {return (int)month;   }
    int getYear()      const {return year;   }
    ///////////////////////////////////////////
    Date addYears(int y){
        unsigned int yN = this->year + y;
        unsigned int mnN = this->month;
        unsigned int dN = this->day;
        unsigned int hN = this->hour;
        unsigned int mN = this->minute;
        unsigned int sN = this->second;
        Date tmp(yN,mnN,dN,hN,mN,sN);
        return tmp;
    }
    Date addMonths(int m){
        unsigned int yN = this->year;
        unsigned int mnN = this->month + m;
        unsigned int dN = this->day;
        unsigned int hN = this->hour;
        unsigned int mN = this->minute;
        unsigned int sN = this->second;
        Date tmp(yN,mnN,dN,hN,mN,sN);
        return tmp;
    }
    Date addDays(int d){
        unsigned int yN = this->year;
        unsigned int mnN = this->month;
        unsigned int dN = this->day + d;
        unsigned int hN = this->hour;
        unsigned int mN = this->minute;
        unsigned int sN = this->second;
        Date tmp(yN,mnN,dN,hN,mN,sN);
        return tmp;
    }
    Date addHours(int h){
        unsigned int yN = this->year;
        unsigned int mnN = this->month;
        unsigned int dN = this->day;
        unsigned int hN = this->hour + h;
        unsigned int mN = this->minute;
        unsigned int sN = this->second;
        Date tmp(yN,mnN,dN,hN,mN,sN);
        return tmp;
    }
    Date addMinutes(int m){
        unsigned int yN = this->year;
        unsigned int mnN = this->month;
        unsigned int dN = this->day;
        unsigned int hN = this->hour;
        unsigned int mN = this->minute + m;
        unsigned int sN = this->second;
        Date tmp(yN,mnN,dN,hN,mN,sN);
        return tmp;
    }
    Date addSeconds(int s){
        unsigned int yN = this->year;
        unsigned int mnN = this->month;
        unsigned int dN = this->day;
        unsigned int hN = this->hour;
        unsigned int mN = this->minute;
        unsigned int sN = this->second + s;
        Date tmp(yN,mnN,dN,hN,mN,sN);
        return tmp;
    }
    void normalize(){
        if(getSecond() > 59){
            unsigned int x = getSecond() / 60;
            setSecond(getSecond() % 60);
            setMinute(getMinute() + x);
        }

        if(getMinute() > 59){
            unsigned int x = getMinute() / 60;
            setMinute(getMinute() % 60);
            setHour(getHour() + x);
        }

        if(getHour() > 23){
            unsigned int x = getHour() / 24;
            setHour(getHour() % 24);
            setDay(getDay() + x);
        }

        if(high) {
            unsigned int thisD = dayTableH[getMonthNum()];
            if (getDay() > thisD) {
                unsigned int x = getDay() / thisD;
                setDay(getDay() % thisD);
                setMonth(static_cast<Month>(getMonth() + x));
            }
        }else{
            unsigned int thisF = dayTable[getMonthNum()];
            if (getDay() > thisF) {
                unsigned int x = getDay() / thisF;
                setDay(getDay() % thisF);
                setMonth(static_cast<Month>(getMonth() + x));
            }
        }

        if(getMonthNum() > 12){
            unsigned int x = getMonthNum() / 12;
            setMonth(static_cast<Month>(getMonthNum() % 12 == 0 ? 1 : getMonthNum() % 12));
            setYear(getYear() + x);
        }

        if(getYear() > 9999){
            setYear(1);
        }

    }
    Date& operator = (const Date &d){
        this->setSecond(d.getSecond());
        this->setMinute(d.getMinute());
        this->setHour  (d.getHour  ());
        this->setDay   (d.getDay   ());
        this->setMonth (d.getMonth ());
        this->setYear  (d.getYear  ());
        return *this;
    }
    void print(bool monthInText){
        cout << "Year:" << getYear() << endl;
        if(monthInText) {
            cout << "Month: " << monthName[getMonthNum()] << endl;
        }else{
            cout << "Month: " << getMonthNum() << endl;
        }
        cout << "Day: "<<  getDay() << endl;
        cout << "Time: "<< getHour() << ":"<< getMinute() << ":" << getSecond() << endl;
    }
    string toString(){
        stringstream ss;
        ss << year; ss << "-";
        (int)month < 10 && (int)month > 0 ? ss << "0" << month : ss << month;ss << "-";
        day < 10 && day > 0 ? ss << "0" << day : ss << day;ss << " ";
        hour < 10 && hour > 0 ? ss << "0" << hour : ss << hour;ss << ":";
        minute < 10 && minute > 0 ? ss << "0" << minute : ss << minute;ss << ":";
        second < 10 && second > 0 ? ss << "0" << second : ss << second;
        return ss.str();
    }
    ~Date(){}
};

int main() {

    unsigned int d[6] = {2020,12,59,48,56,156}; // year , month , day , hour , minute , second ///
    int i[6] = {1,2,0,0,0,0};
    Date a(d);
    cout << "###################################################################" << endl;
    cout << "                       Normalizer Date" << endl;
    cout << "###################################################################" << endl<<endl;

    cout << "Original : " << endl;
    cout << d[0] << "-" << d[1] << "-" <<d[2] << " "<< d[3] << ":" << d[4] << ":" << d[5] << endl;
    cout << "Normalized : " << endl;
    cout << a.toString() << endl << endl;

    cout << "###################################################################" << endl;
    cout << "                           Interval " << endl;
    cout << "###################################################################" << endl<<endl;

    Date x(2020, Dec,11,56,48,54);
    cout <<"Date x = "<< x.toString() << endl;
    Date y(1956,Jun,8,65,15,48);
    cout <<"Date y = "<< y.toString() << endl;

    Date n;
    cout <<"Interval between x and y = "<< n.getInterval(x,y).interval() << endl;
    cout << "###################################################################" << endl;
    cout << "                       addInterval method " << endl;
    cout << "###################################################################" << endl<<endl;

    cout << "Add 1 year and 2 months to Date x : " << endl;
    cout <<"Date x = "<< x.toString() << endl;
    DateInterval interval(i);
    cout << x.addInterval(interval).toString() << endl;

    cout << "###################################################################" << endl;
    cout << "                         String formatter " << endl;
    cout << "###################################################################" << endl<<endl;
    DateInterval strInt;
    string strDate = "2020 Mar 1 12 15 20";
    cout << "Original : " << strDate << endl;
    cout << strInt.formatDate(strDate) <<endl;

   return 0;
}
