#include <iostream>
#include <string>
#include <utility>

#define tmp template<class T>
typedef std::string str;

tmp class iterator{
private:
    T* cacheArr;
    int curPos;
    int size;
public:
    iterator(){
        this->size = 0;
        this->cacheArr = new T[1];
        this->cacheArr[0] = T();
        this->curPos = 0;
    }

    void update(T* arr,int s){
        this->cacheArr = arr;
        this->size = s;
    }

    T getNext(){
        return cacheArr[curPos];
    }

    bool hasNext(){
        if(curPos < size){
            return true;
        }
        return false;
    }

    int pos(){
        return curPos;
    }
    void pos(int i){
        this->curPos = i;
    }

    void operator++(){
        curPos++;
    }
};

tmp class array{
private:
    T *arr;
    int size;
    iterator<T> itr;
public:
    array() {
        this->arr = new T();
        this->size = 0;
        this->itr = iterator<T>();
        itr.update(arr,size);
    }

    T at(int i){
        itr.pos(i);
        return itr.getNext();
    }
    iterator<T> getIterator(){
        return itr;
    }

    void push(T elem){
        T *nArr;
        int s = size + 1;
        if(size == 0){
            nArr = new T[1];
            nArr[0] = elem;
        }else {
            nArr = new T[s];
            for (int a = 0; a < s-1; a++) {
                nArr[a] = arr[a];
            }
            nArr[s-1] = elem;
        }
        this->arr = nArr;
        this->size = s;
        itr.update(arr,size);
        //printf("s -> %i\n",size);
    }

    void remove(int i){
        T* nArr = new T[size - 1];
        for(int a = 0;a < size;a++){
            if(a < i){
                nArr[a] = arr[a];
            }
            if(a > i){
                nArr[a-1] = arr[a];
            }
        }
        this->arr = nArr;
        this->size--;
        itr.update(arr,size);
    }

    void print(){
        for(int a = 0;a < size;a++){
            if(a + 1 >= size)
                std::cout << arr[a];
            else
                std::cout << arr[a] << ",";
        }
        std::cout << "\n";
    }
};

class Subscriber{
private:
    str name;
    int id;
public:
    Subscriber(){
        this->name = "NAME";
        this->id = -1;
    }
    Subscriber(str n, int i){
        this->name = std::move(n);
        this->id = i;
    }

    void info(){
        printf("Name -> %s\nId -> %i\n",this->name.c_str(),this->id);
    }

    void update(const str& msg){
        info();
        printf("new message -> %s\n",msg.c_str());
    }

};

class Publisher{
private:
    array<Subscriber> subscribers;
public:
    Publisher(){
        subscribers = array<Subscriber>();
    }

    void add(Subscriber s){
        subscribers.push(std::move(s));
    }
    void remove(int i){
        subscribers.remove(i);
    }

    void notifyAll(const str& msg){
        iterator<Subscriber> itr = subscribers.getIterator();
        while(itr.hasNext()){
            itr.getNext().update(msg);
            itr.operator++();
        }
    }
};

#define Task 1
int main() {
#if Task == 1
    array<int> arr;
    arr.push(5);
    arr.push(2);
    arr.push(3);
    arr.push(8);
    arr.print();
    arr.remove(2);
    arr.remove(0);
    arr.print();
    arr.push(55);
    arr.print();

    printf("at(2) -> %i\n", arr.at(2));
    printf("at(0) -> %i\n", arr.at(0));

#else
    Subscriber s1("Maks",45662);
    Subscriber s2("Andy",94948);
    Subscriber s3("Nick",78416);
    Publisher a;
    a.add(s1);
    a.add(s2);
    a.add(s3);
    a.notifyAll("Hello World");
    a.remove(1);
    a.notifyAll("new calculator");


#endif
    return 0;
}
