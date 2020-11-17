#ifndef OPENGLAPP_OBJECTS_H
#define OPENGLAPP_OBJECTS_H

#include "colorUtils.h"
#include <cmath>

#define PI 3.1415926
#define hPI PI/2
#define qPI PI/4
#define dPI 2*PI


void circle(int xC,int yC ,float r){
    glBegin(GL_LINE_LOOP);
    for(double a = 0.0; a < dPI;a+=0.1){
        int i = xC + (r/2)*sin(a);
        int j = yC + (r/2)*cos(a);
        glVertex2i(i,j);
    }
    glEnd();
}

void fillCircle(int xC, int yC, float r){
    glBegin(GL_POLYGON);
    for(double a = 0.0; a < dPI;a+=0.1){
        int i = xC + (r/2)*sin(a);
        int j = yC + (r/2)*cos(a);
        glVertex2i(i,j);
    }
    glEnd();
}

void halfCircle(int xC,int yC ,int r,float deg){
    glBegin(GL_LINE_STRIP);
    float d = deg*(PI/180.00);
    for(double a = 0.0+d; a < 3.14+d;a+=0.1){
        int i = xC + (r/2)*sin(a);
        int j = yC + (r/2)*cos(a);
        glVertex2i(i,j);
    }
    glEnd();
}

void halfFillCircle(int xC,int yC ,int r,float deg){
    glBegin(GL_POLYGON);
    float d = deg*(PI/180.00);
    for(double a = 0.0+d; a < 3.14+d;a+=0.1){
        int i = xC + (r/2)*sin(a);
        int j = yC + (r/2)*cos(a);
        glVertex2i(i,j);
    }
    glEnd();
}

void line(int x,int y, int X, int Y,bool dt = false){
    glBegin(GL_LINES);
    if(!dt) {
        glVertex2i(x, y);
        glVertex2i(X, Y);
    }else{
        glVertex2i(x,y);
        glVertex2i(x+X,y+Y);
    }
    glEnd();
}

void rect(int x, int y, int w, int h){
    glBegin(GL_LINE_LOOP);
    glVertex2i(x,y);
    glVertex2i(x,y+h);
    glVertex2i(x+w,y+h);
    glVertex2i(x+w,y);
    glEnd();
}

void fillRect(int x, int y, int w, int h){
    glBegin(GL_POLYGON);
    glVertex2i(x,y);
    glVertex2i(x,y+h);
    glVertex2i(x+w,y+h);
    glVertex2i(x+w,y);
    glEnd();
}

void fillParal(int x,int y, int mW, int bW,int h){
    int z = (bW - mW)/2;
    glBegin(GL_POLYGON);
    glVertex2i(x,y+h);
    glVertex2i(x+bW,y+h);
    glVertex2i(x+z+mW,y);
    glVertex2i(x+z,y);
    glEnd();
}

void fillParalH(int x,int y, int mW, int bW,int h){
    int z = (bW - mW)/2;
    glBegin(GL_POLYGON);
    glVertex2i(x,y);
    glVertex2i(x+h,y+z);
    glVertex2i(x+h,y+z+mW);
    glVertex2i(x,y+bW);
    glEnd();
}

void paral(int x,int y, int mW, int bW,int h){
    int z = (bW - mW)/2;
    glBegin(GL_LINE_LOOP);
    glVertex2i(x,y+h);
    glVertex2i(x+bW,y+h);
    glVertex2i(x+z+mW,y);
    glVertex2i(x+z,y);
    glEnd();
}

void paralD(int x,int y, int mW, int bW,int h,bool t = false){
    glBegin(GL_LINE_LOOP);
    if(!t) {
        glVertex2i(x, y);
        glVertex2i(x + mW, y);
        glVertex2i(x + bW, y+h);
        glVertex2i(x, y+h);
    }else{
        glVertex2i(x + (bW -mW), y);
        glVertex2i(x + bW, y);
        glVertex2i(x + bW, y+h);
        glVertex2i(x, y+h);
    }
    glEnd();
}

void paralH(int x,int y, int mW, int bW,int h){
    int z = (bW - mW)/2;
    glBegin(GL_LINE_LOOP);
    glVertex2i(x,y);
    glVertex2i(x+h,y+z);
    glVertex2i(x+h,y+z+mW);
    glVertex2i(x,y+bW);
    glEnd();
}

void triangle(int x,int y,int w, int h,bool rev){
    glBegin(GL_LINE_LOOP);
    if(!rev) {
        glVertex2i(x, y);
        glVertex2i(x + w, y + h);
        glVertex2i(x, y + h);
    }else{
        glVertex2i(x, y);
        glVertex2i(x + w, y);
        glVertex2i(x+w, y + h);
    }
    glEnd();
}

void triangleR(int x,int y,int n,bool rev = false){
    glBegin(GL_LINE_LOOP);
    if(!rev) {
        glVertex2i(x, y + n);
        glVertex2i(x + n / 2, y);
        glVertex2i(x + n, y + n);
    }else{
        glVertex2i(x, y);
        glVertex2i(x + n, y);
        glVertex2i(x + n/2, y + n);
    }
    glEnd();
}

void triangleB(int x,int y,int w,int h,bool rev = false){
    glBegin(GL_LINE_LOOP);
    if(!rev) {
        glVertex2i(x, y + h);
        glVertex2i(x + w / 2, y);
        glVertex2i(x + w, y + h);
    }else{
        glVertex2i(x, y);
        glVertex2i(x + w, y);
        glVertex2i(x + w/2, y + h);
    }
    glEnd();
}

void fillTriangleB(int x,int y,int w,int h,bool rev = false){
    glBegin(GL_POLYGON);
    if(!rev) {
        glVertex2i(x, y + h);
        glVertex2i(x + w / 2, y);
        glVertex2i(x + w, y + h);
    }else{
        glVertex2i(x, y);
        glVertex2i(x + w, y);
        glVertex2i(x + w/2, y + h);
    }
    glEnd();
}


void fillTriangle(int x,int y,int w, int h,bool rev){
    glBegin(GL_POLYGON);
    if(!rev) {
        glVertex2i(x, y);
        glVertex2i(x + w, y + h);
        glVertex2i(x, y + h);
    }else{
        glVertex2i(x, y);
        glVertex2i(x + w, y);
        glVertex2i(x+w, y + h);
    }
    glEnd();
}

void fillTriangleR(int x,int y,int n,bool rev = false){
    glBegin(GL_POLYGON);
    if(!rev) {
        glVertex2i(x, y + n);
        glVertex2i(x + n / 2, y);
        glVertex2i(x + n, y + n);
    }else{
        glVertex2i(x, y);
        glVertex2i(x + n, y);
        glVertex2i(x + n/2, y + n);
    }
    glEnd();
}

void fillRectR(int x,int y,int w,int h){
    glBegin(GL_POLYGON);
        glVertex2i(x, y + h/2);
        glVertex2i(x + w / 2, y );
        glVertex2i(x + w, y + h/2);
        glVertex2i(x + w/2, y + h);
    glEnd();
}

void rectR(int x,int y,int w,int h){
    glBegin(GL_LINE_LOOP);
    glVertex2i(x, y + h/2);
    glVertex2i(x + w / 2, y );
    glVertex2i(x + w, y + h/2);
    glVertex2i(x + w/2, y + h);
    glEnd();
}
#endif //OPENGLAPP_OBJECTS_H
