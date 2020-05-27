#include <iostream>
#include <vector>
using namespace std;

template <class class1, class class2> class mipmap
{
private:
    class1 a;
    class2 b;
public:
    mipmap(class1 o1, class2 o2){
        a = o1;
        b = o2;
    }

    class1 getKey(){return a;}

    void info(){
        cout << "key= " << a << "; b= " << b << endl;
    }

};

int main()
{
    vector<mipmap<int,double> > z;
    mipmap<int,double> q(1,5.3); z.push_back(q);
    mipmap<int,double> w(2,4.3); z.push_back(w);
    mipmap<int,double> e(3,9.3); z.push_back(e);
    mipmap<int,double> r(2,86.5); z.push_back(r);
    mipmap<int,double> t(5,4563.41); z.push_back(t);
    mipmap<int,double> y(2,1.63); z.push_back(y);
    mipmap<int,double> u(7,0.001); z.push_back(u);

    int key;
    cout << "Enter key "; cin >> key;

    for(int i = 0; i < z.size();i++){
            if(z[i].getKey() == key)
                z[i].info();
    }

    return 0;
}
