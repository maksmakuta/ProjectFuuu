#include <QtCore>

QTextStream cout(stdout);
int main(){
    srand(time(nullptr));
    int q = 0;
    int s = 7;
    for(int x = 0;x < 7;x++){
        for(int y = 0;y < 7;y++){
            if(x < 4){
                if(y >= q && y < s )
                    cout << rand()%10 << " ";
                else
                    cout << 0 << " ";
            }else{
                cout << 0 << " ";
            }
        }
        cout << '\n';
        q++;
        s--;
    }


    cout << "\n\n\n";
    q = 1;
    s = 7;
    for(int x = 0;x < 7;x++){
        for(int y = 0;y < 7;y++){
          if(y < q){
              cout << rand()%10 << " ";
          }else{
              cout << 0 << " ";
            }
        }
        cout << '\n';

        if(q == 4){
            s = 0;
        }
        if(s == 0)
            q--;
        else
            q++;
    }



}
