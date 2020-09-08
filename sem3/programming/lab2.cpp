#include <iostream>
#include <bits/stl_algo.h>
#include <vector>

#define ARR_SIZE 8

using namespace std;

/*
 *  lab2
 *  Tasks : 1b,2a,3b
 */


template <class T>
T avg(vector<T> arr){
    T data = static_cast<T>(0);
    int d = 0;

    for(int a = 0; a < arr.size(); a++){
     data += arr[a]; d++;
    }

    return static_cast<T>(data/d);
}

template <class T>
void minmax(vector<T> arr){
    T min = avg(arr);
    T max = avg(arr);
    for(int a = 0; a < arr.size();a++){
            if(arr[a] > max){max = arr[a];}
            if(arr[a] < min){min = arr[a];}
    }
    cout << "min -> " << min << endl;
    cout << "max -> " << max << endl;
}

template <class a>
vector<a> createVector(a avg){
        vector<a> arr;
        for (int j = 0; j < ARR_SIZE; j++) {
            a item = random() % static_cast<int>(avg);
            arr.push_back(item);
        }
        return arr;
}

template <class Q> Q** gen2DArray(int m){
    Q **array = new Q*[ARR_SIZE];

    for(auto d = 0;d < ARR_SIZE;d++){
        array[d] = new Q[ARR_SIZE];
    }

    for(auto a = 0; a < ARR_SIZE; a++) {
        for (auto b = 0; b < ARR_SIZE; b++) {
            array[a][b] = static_cast<Q>(random() % m);
        }
    }
    return array;
}

template <class E>
void printVector(vector<E> arr){
        for (int j = 0; j < arr.size(); j++) {
            if(arr[j] > -1 && arr[j]<10)
                cout <<"  " << static_cast<E>(arr[j]) << " ";
            if(arr[j] > 9 && arr[j]<100)
                cout <<" " << static_cast<E>(arr[j]) << " ";
            if((j+1)%ARR_SIZE == 0){
                cout<< endl;
            }
        }
}

template <class q> void print2D(q **arr){
    for(auto a = 0; a < ARR_SIZE; a++) {
        for (auto b = 0; b < ARR_SIZE; b++) {
            cout << arr[a][b] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

template <class R> void swap(R *a,R *b){
    R tmp = *a;
    *a = *b;
    *b = tmp;
}

template <class E> void bubleSort(E *data, int s){
    for (auto i = 0; i < s-1; i++) {
        for (auto j = 0; j < s - i - 1; j++) {
            if (data[j] > data[j + 1])swap<E>(&data[j], &data[j + 1]);
        }
    }
}

template <class W> W** bubleSort2D(W** data){

    W *newArray = new W[ARR_SIZE*ARR_SIZE];
    for (auto i = 0; i < ARR_SIZE; i++) {
        for (auto j = 0; j < ARR_SIZE; j++) {
            newArray[j*ARR_SIZE+i] = data[i][j];
        }
    }

    bubleSort(newArray,ARR_SIZE*ARR_SIZE);

    W **array = new W*[ARR_SIZE];

    for(auto d = 0;d < ARR_SIZE;d++){
        array[d] = new W[ARR_SIZE];
    }

    for(auto a = 0; a < ARR_SIZE; a++) {
        for (auto b = 0; b < ARR_SIZE; b++) {
            array[a][b] = newArray[a*ARR_SIZE+b];
        }
    }
    return array;
}

template <class A> class ArrayList{

private:
    A *list;
    int s,maxS;
public:
    ArrayList(int maxSize){
        this->list = new A[maxSize];
        this->maxS = maxSize;
        this->s = -1;
    }
    void add(A item){
        if(s < (maxS - 1) ){
            s++;
            this->list[s] = item;
        }else{
            cout << "List are overflow!!!" << endl;
        }
    }
    void remove(int p){
        while(true){
            this->list[p] = list[p+1];
            p++;
            if(p == this->s){
                this->list[p]=static_cast<A>(0);
                this->s--;
                break;
            }
        }
    }
    A get(int p){return list[p];}
    A getLast(){return list[s];}
    int getSize(){return s;}
    void print(){
        for(auto a = 0 ;a < this->s+1;a++){
            cout << list[a] << " ";
        }
        cout << endl;
    }
    ~ArrayList(){delete list;}
};

int main(){

   cout << "================  Task 1  ================" << endl;

    vector<int> data_i = createVector<int>(100);
    cout << "Raw array : " << endl;
    printVector(data_i);
    cout << endl;
    minmax(data_i);
    cout << endl;



    cout << "================  Task 2  ================" << endl;
    int **data_i2 = gen2DArray<int>(200);
    cout << "Raw 2D array :" << endl;
    print2D<int>(data_i2);
    int **sorted = bubleSort2D<int>(data_i2);
    cout << "Buble sort : " << endl;
    print2D<int>(sorted);

    cout << "================  Task 3  ================" << endl;

    ArrayList<int> data(5);
    cout << "Size = " << data.getSize() << endl;

    cout << "Add items" << endl;
    data.add(15);
    data.add(10);
    data.add(5);

    cout << "Array : " ; data.print();
    cout << "Delete data[1]" << endl;
    data.remove(1);
    cout << "Array : "; data.print();
    cout << "data[0] = " << data.get(0) << endl;
    cout << "data[" << data.getSize() << "] = " << data.getLast() << endl;
    int d = 21;
    cout << "Add new elements to overflow" << endl;
    while(d >= 3){
        d -= 3;
        data.add(d);
    }
    cout << "Array : ";data.print();
    cout << "data[" << data.getSize() << "] = " << data.getLast() << endl;

    return 0;
}
