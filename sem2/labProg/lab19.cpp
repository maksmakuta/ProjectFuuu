#include <iostream>
#include <fstream>
#include <string>

#define a 0
#define b 0

#define N 100

using namespace std;

void gen(string gen){

int m[N][N];
ofstream file(gen + ".txt");

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            m[i-1][j-1] = (i + a) * (j + b);
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j] < 100000 && m[i][j] >= 10000)
                file << " " << m[i][j] << " ";
            else if(m[i][j] < 10000 && m[i][j] >= 1000)
                file << "  " << m[i][j] << " ";
            else if(m[i][j] < 1000 && m[i][j] >= 100)
                file << "   " << m[i][j] << " ";
            else if(m[i][j] < 100 && m[i][j] >= 10)
                file << "    " << m[i][j] << " ";
            else if(m[i][j] < 10 && m[i][j] >= 0)
                file << "     " << m[i][j] << " ";
            else
                file << m[i][j] << " ";
        }
        file << endl ;
    }

}

int subMatrix(string in, int M, string out){
    if(M > N){
        cerr << "Error" << endl;
        return 0;
    }
    int tmp[N][N];

    ofstream outF(out + ".txt");
    ifstream  inF(in + ".txt");

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
                inF >> tmp[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(tmp[i][j] < 100000 && tmp[i][j] >= 10000)
                outF << " " << tmp[i][j] << " ";
            else if(tmp[i][j] < 10000 && tmp[i][j] >= 1000)
                outF << "  " << tmp[i][j] << " ";
            else if(tmp[i][j] < 1000 && tmp[i][j] >= 100)
                outF << "   " << tmp[i][j] << " ";
            else if(tmp[i][j] < 100 && tmp[i][j] >= 10)
                outF << "    " << tmp[i][j] << " ";
            else if(tmp[i][j] < 10 && tmp[i][j] >= 0)
                outF << "     " << tmp[i][j] << " ";
            else
                outF << tmp[i][j] << " ";
        }
        outF << endl ;
    }
    return 1;
}

int main()
{
    gen("g1");
    subMatrix("g1",30,"g2");
}
