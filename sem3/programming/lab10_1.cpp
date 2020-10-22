#include <GL/glut.h>
#include <cmath>
#include "colorUtils.h"

#define SEGMENTS 500

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


void circle(int x, int y, float r,char* scolor){
    double *c = color(scolor);
    glColor3d(c[0],c[1],c[2]);
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
    circle(140,100,20,colors[0]);
    circle(245,140,10,colors[1]);
    circle(140,320,11,colors[2]);
    circle(210,40, 11,colors[3]);
    circle(100,140,14,colors[4]);
    circle(30, 380,17,colors[5]);
    circle(50, 70, 24,colors[6]);
    circle(275,250,25,colors[7]);
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
