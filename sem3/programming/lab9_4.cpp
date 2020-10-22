#include <GL/glut.h>
#include <cmath>
#include "colorUtils.h"

#define SEGMENTS 50

char* colors[] = {
        (char*)"ff00ff",(char*)"ffffff",
        (char*)"0000aa",(char*)"ff0000",
        (char*)"00ffff",(char*)"ffff00",
        (char*)"00ff00",(char*)"ff00ff"
};

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}


void circle(int x, int y, float r,bool isLine,char* scolor){
    double *c = color(scolor);
    glColor3d(c[0],c[1],c[2]);

    if(isLine)
        glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_POLYGON);

    for(int ii = 0; ii < SEGMENTS; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(SEGMENTS);//get the current angle

        float cx = r * std::cos(theta);//calculate the x component
        float cy = r * std::sin(theta);//calculate the y component

        glVertex2f((float)(x + cx), (float)(y + cy));//output vertex

    }
    glEnd();
}


void draw(){
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);
    char *white =(char*)"ffffff";
    circle(200,200, 35,true  ,white);
    circle(200,200, 60,true  ,white);
    circle(200,200, 90,true  ,white);
    circle(200,200,120,true  ,white);
    circle(200,200,180,true  ,white);
    circle(300, 50, 27,true  ,white);
    circle(300, 50, 50,true  ,white);

    circle(200,200,20,false,colors[0]);
    circle(215,170,10,false,colors[1]);
    circle(140,200,11,false,colors[2]);
    circle(290,200, 8,false,colors[3]);
    circle(120,290, 4,false,colors[4]);
    circle(300, 50,17,false,colors[5]);
    circle(350, 50, 4,false,colors[6]);
    circle(275, 60, 5,false,colors[7]);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Paint");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
