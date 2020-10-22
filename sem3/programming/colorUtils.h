//
// Created by maks on 22.10.20.
//

#ifndef OPENGLAPP_COLORUTILS_H
#define OPENGLAPP_COLORUTILS_H

int i(char a){
    switch (a) {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        case 'a' : return 10;
        case 'b' : return 11;
        case 'c' : return 12;
        case 'd' : return 13;
        case 'e' : return 14;
        case 'f' : return 15;
        default: return -1;
    }
}

double* color(char* text){
    auto *color = new double[3];
    for(int a = 0; a < 3; a++){
        int c1 = i(text[a*2]);
        int c2 = i(text[a*2+1]);
        int c = c1 * c2;
        color[a] = c/255.0;
    }
    return color;
}

#endif //OPENGLAPP_COLORUTILS_H
