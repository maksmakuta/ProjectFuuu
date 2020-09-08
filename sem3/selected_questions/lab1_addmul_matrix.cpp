#include <iostream>
#include <string>

#define N 4

using namespace std;

void add(int **a1, int **a2);
void print(string name,int **arr);
void mlt(int **pInt, int **pInt1);
void initMatrix(),reallocMatrix();


int** m1 = new int*[N];
int** m2 = new int*[N];

auto sum = new int*[N];
auto mul = new int*[N];

int main(){
    initMatrix();
    print("m1",m1);
    print("m2",m2);
    add(m1, m2);
    print("m1 + m2",sum);
    mlt(m1, m2);
    print("m1 * m2",mul);
    reallocMatrix();
    return 0;
}

void init2DMatrix(int** a,int r){
    for(int w = 0; w < N;w++){
        a[w] = new int[N];
    }

    for(int q = 0; q < N;q++){
        for(int w = 0; w < N;w++){
            a[q][w] = r + q - w;
        }
    }
}

void delete2DMatrix(int** a){
    for(int w = 0; w < N;w++){
        delete a[w];
    }
    delete[] a;
}

void initMatrix() {
    init2DMatrix(m1,5);
    init2DMatrix(m2,9);
    init2DMatrix(sum,0);
    init2DMatrix(mul,0);
}
void reallocMatrix(){
    delete2DMatrix(m1);
    delete2DMatrix(m2);
    delete2DMatrix(sum);
    delete2DMatrix(mul);
}

void mlt(int **pInt, int **pInt1) {

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < N; k++)
                mul[i][j] += pInt[i][k] * pInt1[k][j];
        }
    }

}

void print(string name,int **arr) {
    cout << endl << name << " : " << endl;
    for(int a = 0; a < N;a++){
        for(int b = 0; b < N;b++){
            if(arr[a][b] > -1 && arr[a][b] < 10)cout << "  " << arr[a][b] << " ";
            if(arr[a][b] > 9 && arr[a][b] < 100)cout << " " << arr[a][b] << " ";
            if(arr[a][b] > 99 && arr[a][b] < 1000)cout << " " << arr[a][b] << " ";
            if(arr[a][b] > -100 && arr[a][b] < -9)cout << " " << arr[a][b] << " ";
        }
        cout << endl;
    }
}

void add(int **a1, int **a2) {
    for(int a = 0; a < N;a++){
        for(int b = 0; b < N;b++){
            sum[a][b] = a1[a][b] + a2[a][b];
        }
    }
}
