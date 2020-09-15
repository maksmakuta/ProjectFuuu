#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class D> class Hash{

private:
    D item;

public:
    explicit Hash(D data){
        this->item = data;
    }

    Hash(){}

    string toString(D data){
        stringstream  ss;
        ss << data;
        return ss.str();
    }

    void setData(D data){
        this->item = data;
    }

    string hash(){
        string data;
        data = toString(item);
        string hash;
        for(int a : data){
            hash.push_back( a - 1);
        }
        return hash;
    }
};

template <class A , class B> class HashMap{
private :
    A *hash;
    B *data;
    int m;
    int s;
public:
    HashMap(int max){
        this->m = max;
        this->s = -1;
        this->data = new B[m];
        this->hash = new A[m];
    }

    void add(B item) {
        if (s < m + 1) {
            s++;
            hash[s] = Hash<B>(item);
            data[s] = item;
        }else{
            cout << "Map is overflow!!!" << endl;
        }
    }

    void get(int pos){
        if (pos < m + 1) {
            cout << data[pos]  << "\t" << hash[pos].hash()<< endl;
        }else{
            cout << "ArrayLengthException" << endl;
        }
    }

    void printAll(){
        for(int a = 0; a < s+1; a++){
            get(a);
        }
    }

    int size(){return s;}

    void remove(int pos){
        if (pos < m + 1) {
            hash[s] = NULL;
            data[s] = NULL;
        }else{
            cout << "ArrayLengthException" << endl;
        }
    }

    ~HashMap(){
        delete [](hash);
        delete [](data);
    }

};

int main(){

    Hash<string> d("Hello world");
    cout << d.hash() << endl;

    HashMap<Hash<string>,string> hash(5);
    hash.add("Hello");hash.add("World");hash.add("and you...");

    hash.printAll();



    return 0;
} 
