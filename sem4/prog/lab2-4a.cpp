#include <QtCore>
#define W 20
#define H W*2

QTextStream cout(stdout);
int main(){

    for(int x = 0;x < W;x++){
        for(int y = 0;y < H;y++){

        if(x == 0 /*|| x == W-1*/){
            if(y < (H/2)-4)
                cout << '[';
            else if(y > (H/2)+4)
                cout << ']';
            else
                cout << " ";
        }


        if(x > 0 && x < 4){
            if(y == 0 || (x == 3 && (y > (H/2)-11 && y < (H/2)-5)))
                cout << '[';
            else if(y == H-1 || (x == 3 && (y > (H/2)+5 && y < (H/2)+11)))
                cout << ']';
            else if(y < (H/2)-4)
                cout << ':';
            else if(y > (H/2)+4)
                cout << ':';
            else
                cout << " ";
        }

        if(x > 3 && x < W- 4){
            if(y == 0 ||  y == (H/2)-11)
                cout << '[';
            else if(y == H-1 ||  y == (H/2)+11)
                cout << ']';
            else if(y < (H/2)-10)
                cout << ':';
            else if(y > (H/2)+10)
                cout << ':';
            else
                cout << " ";
        }


        if(x > W - 5 && x < W-1){

            if(y == 0 || (x == W-4 && (y > (H/2)-11 && y < (H/2)-5)))
                cout << '[';
            else if(y == H-1 || (x == W-4 && (y > (H/2)+5 && y < (H/2)+11)))
                cout << ']';
            else if(y < (H/2)-4)
                cout << ':';
            else if(y > (H/2)+4)
                cout << ':';
            else
                cout << " ";
        }

        if(x == W-1 /*|| x == W-1*/){
            if(y < (H/2)-4)
                cout << '[';
            else if(y > (H/2)+4)
                cout << ']';
            else
                cout << " ";
        }




        }
        cout << '\n';
    }

}
