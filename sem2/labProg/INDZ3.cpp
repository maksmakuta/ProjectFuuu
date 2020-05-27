#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class GetInfo{
    public:
    virtual void get(){
        cout << "GetInfo.get();"<< endl;
        cout << "UDK = null" << endl;
    };
};

class Book : public GetInfo{

protected:
    long UDK;
    string author, name, org;
    int year;
public:
    Book(){}
    Book(Book &a){
        this->UDK = a.getUDK();
        this->author = a.getAuthor();
        this->name = a.getName();
        this->org = a.getOrg();
        this->year = a.getYear();
    }
    Book(Book *a){
        this->UDK = a->getUDK();
        this->author = a->getAuthor();
        this->name = a->getName();
        this->org = a->getOrg();
        this->year = a->getYear();
    }
    Book(long u, string a, string n, string o, int y){
        this->UDK = u;
        this->author = a;
        this->name = n;
        this->org = o;
        this->year = y;
    }

    virtual void get(){
        cout << "Book.get();"<< endl;
        cout << "UDK = " << getUDK() << endl;
    };

    long getUDK(){return UDK;}
    string getAuthor(){return author;}
    string getName(){return name;}
    string getOrg(){return org;}
    int getYear(){return year;}

    long getUDK() const{return UDK;}
    string getAuthor()const{return author;}
    string getName()const{return name;}
    string getOrg()const{return org;}
    int getYear()const{return year;}

    void setUDK(long u){this->UDK = u;}
    void setAuthor(string a){this->author = a;}
    void setName(string n){this->name = n;}
    void setOrg(string o){this->org = o;}
    void setYear(int y){this->year = y;}

    void operator ()(){
       cout << "Enter data:" << endl;
        cout << "Name : ";string n; cin >> n; this->setName(n);
        cout << "Author : ";string a; cin >> a; this->setAuthor(a);
        cout << "Org : ";string o; cin >> o; this->setOrg(o);
        cout << "Year : ";int y; cin >> y; this->setYear(y);
        cout << "UDk : ";long u; cin >> u; this->setUDK(u);
    }

    Book operator =(Book &b){
            Book tmp(b);
        return tmp;
    }

    friend ostream& operator <<(ostream &o,Book &b){
        o << "Name : " << b.getName() << '\n'
        << "Author : " << b.getAuthor() << '\n'
        << "Org : " << b.getOrg() << '\n'
        << "Year : " << b.getYear() << '\n'
        << "UDK : " << b.getUDK() << '\n';
        return o;
    }

    friend istream& operator >>(istream &i,Book &b){
        b();
        return i;
    }

    ~Book(){}
};

class MarkBook: public Book{
private:
    int stage;
    map<string,int> marks;

public:
    MarkBook(){
        this->UDK =         -1;
        this->author =      " ";
        this->name =        " ";
        this->org =         " ";
        this->year =        -1;
    }
    MarkBook(const MarkBook &m){
        this->stage =       m.getStage();
        this->marks =       m.getMarks();
        this->UDK =         m.getUDK();
        this->author =      m.getAuthor();
        this->name =        m.getName();
        this->org =         m.getOrg();
        this->year =        m.getYear();
    }
    MarkBook(MarkBook *m){
        this->stage =       m->getStage();
        this->marks =       m->getMarks();
        this->UDK =         m->getUDK();
        this->author =      m->getAuthor();
        this->name =        m->getName();
        this->org =         m->getOrg();
        this->year =        m->getYear();
    }
    MarkBook(int s, map<string,int> m, Book d):Book(d){
        this->stage = s;
        this->marks = m;
    }
    MarkBook(int s, map<string,int> m, Book* d):Book(d){
        this->stage = s;
        this->marks = m;
    }
    MarkBook(int s, map<string,int> m,long u, string a, string n, string o, int y):Book(u,a,n,o,y){
        this->stage = s;
        this->marks = m;
    }

    virtual void get(){
        cout << "MarkBook.get();"<< endl;
        cout << "UDK = " << getUDK() << endl;
    };

    int getStage(){ return stage;}
    map<string,int> getMarks(){return marks;}

    int getStage() const{ return stage;}
    map<string,int> getMarks()const{return marks;}

    void setStage(int s){this->stage = s;}
    void setMarks(map<string,int> m){this->marks = m;}

    void getMark(){
        string sub;
        cout << "Enter subject to find : "; cin >> sub;
        map<string,int>::iterator it;
        it = marks.find(sub);
        if (it != marks.end())
            cout << " \t" << it->first << " - " << it->second << endl;
        else
            cout << "This subject is not exist" << endl;
    }

    double getRate(){
        int am = 0;
        int div = 0;
        map<string,int>::iterator it;
        for(it = marks.begin();it != marks.end();it++){
            am += it->second ;
            div++;
        }
        double rate = am/div;
        return rate;
    }
    MarkBook operator =(MarkBook& m){
        MarkBook tmp(m.getStage(), m.getMarks(),m.getUDK(),m.getAuthor(),m.getName(),m.getOrg(),m.getYear());
        return tmp;
    }

    MarkBook operator =(const MarkBook& m){
        MarkBook tmp(m.getStage(), m.getMarks(),m.getUDK(),m.getAuthor(),m.getName(),m.getOrg(),m.getYear());
        return tmp;
    }

    friend ostream& operator <<(ostream &o,MarkBook &b){
        map<string,int> tmp = b.getMarks();
        map<string,int>::iterator it;

        o << "Name : " << b.getName() << '\n'
        << "Author : " << b.getAuthor() << '\n'
        << "Org : " << b.getOrg() << '\n'
        << "Year : " << b.getYear() << '\n'
        << "UDK : " << b.getUDK() << '\n'
        << "Stage : " << b.getStage() << '\n'
        << "Marks : " << '\n';

        for(it = tmp.begin();it != tmp.end();it++){
            o << " \t" << it->first << " - " << it->second << endl;
        }

        return o;
    }

    friend istream& operator >>(istream &i,MarkBook &b){
       cout << "Enter data:" << endl;
        cout << "Name : ";string n; cin >> n; b.setName(n);
        cout << "Author : ";string a; cin >> a; b.setAuthor(a);
        cout << "Org : ";string o; cin >> o; b.setOrg(o);
        cout << "Year : ";int y; cin >> y; b.setYear(y);
        cout << "UDk : ";long u; cin >> u; b.setUDK(u);
        cout << "Enter amount of marks"; int am; cin >> am;
        map<string,int> data;
        for(int i = 0; i < am;i++){
            string tmpS;    int tmpM;
            cout << "Enter subject name : ";cin >> tmpS;
            cout << "Enter subject mark : ";cin >> tmpM;
            data.insert(pair<string,int>(tmpS,tmpM));
        }
        b.setMarks(data);
        return i;
    }
    ~MarkBook(){}
};

class SemestrBook {
private:
    vector<MarkBook> book;
public:
    SemestrBook(vector<MarkBook> b){
        this->book=b;
    }

    void printRate(){
        vector<MarkBook>::iterator it;
        for(it = book.begin(); it != book.end();it++){
            double minRate = 3.0, r = it->getRate();
            if(r < minRate)
                cout << it->getName() << " : " << (double)r <<" //- Restudy "<< endl;
            else
                cout << it->getName() << " : " << (double)r <<" //- Go to next semestr "<< endl;
        }
    }
        ~SemestrBook(){}
};

Book* getBookWithName(string name){
    return new Book(440,"University",name,"MOS",2020);
}

int main()
{
    string subL[5] = {"math","programming","algebra","physics","discrete"};

    map<string,int> s1;
    s1.insert(pair<string,int>(subL[0],1));
    s1.insert(pair<string,int>(subL[1],3));
    s1.insert(pair<string,int>(subL[2],4));
    s1.insert(pair<string,int>(subL[3],2));
    s1.insert(pair<string,int>(subL[4],5));
    MarkBook m1(1,s1,getBookWithName("Mark"));

    map<string,int> s2;
    s2.insert(pair<string,int>(subL[0],3));
    s2.insert(pair<string,int>(subL[1],3));
    s2.insert(pair<string,int>(subL[2],5));
    s2.insert(pair<string,int>(subL[3],4));
    s2.insert(pair<string,int>(subL[4],3));
    MarkBook m2(1,s2,getBookWithName("Nick"));

    map<string,int> s3;
    s3.insert(pair<string,int>(subL[0],3));
    s3.insert(pair<string,int>(subL[1],1));
    s3.insert(pair<string,int>(subL[2],2));
    s3.insert(pair<string,int>(subL[3],3));
    s3.insert(pair<string,int>(subL[4],2));
    MarkBook m3(1,s3,getBookWithName("Bob"));

    map<string,int> s4;
    s4.insert(pair<string,int>(subL[0],5));
    s4.insert(pair<string,int>(subL[1],5));
    s4.insert(pair<string,int>(subL[2],4));
    s4.insert(pair<string,int>(subL[3],5));
    s4.insert(pair<string,int>(subL[4],4));
    MarkBook m4(1,s4,getBookWithName("Joey"));

    map<string,int> s5;
    s5.insert(pair<string,int>(subL[0],1));
    s5.insert(pair<string,int>(subL[1],2));
    s5.insert(pair<string,int>(subL[2],1));
    s5.insert(pair<string,int>(subL[3],1));
    s5.insert(pair<string,int>(subL[4],2));
    MarkBook m5(1,s5,getBookWithName("Jack"));

    vector<MarkBook> semV;
    semV.push_back(m1);
    semV.push_back(m2);
    semV.push_back(m3);
    semV.push_back(m4);
    semV.push_back(m5);

    SemestrBook sem(semV);
    sem.printRate();
    cout << endl;

    cout << "Use virtual method " << endl<<endl;

    GetInfo *x = new GetInfo();
        x->get();
        delete []x;
        cout << endl;
    x = new Book(156,"Author","name","Org",2020);
        x->get();
        delete []x;
        cout << endl;
        map<string,int> xM;
        xM.insert(pair<string,int>(subL[4],3));
        xM.insert(pair<string,int>(subL[2],4));
    x = new MarkBook(2,xM,new Book(448,"a","n","O",2020));
        x->get();
        delete []x;

    return 0;
}
