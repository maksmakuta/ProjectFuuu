#include "objects.h"

using namespace std;

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);

    rect(250,250,250,75);

    paralH(185,205,75,170,65);
    rect(165,205,20,170);

    paral(250,200,300,250,50);
    halfCircle(275,170,45,270);
    halfCircle(475,170,45,270);

    circle(275,170,35);
    circle(475,170,35);

    line(295,170,160,0,true);
    line(225,200,0,-30,true);
    line(225,170,30,0,true);
    line(495,170,60,0,true);
    line(555,170,-30,30,true);

    paral(225,325,250,300,50);
    halfCircle(275,405,45,90);
    halfCircle(475,405,45,90);

    circle(275,405,35);
    circle(475,405,35);

    line(295,405,160,0,true);
    line(225,375,0,30,true);
    line(225,405,30,0,true);
    line(495,405,60,0,true);
    line(555,405,-30,-30,true);

    paralD(400,335,50,65,30);
    rect(320,335,65,30);
    paralD(240,335,50,65,30 ,true);

    paralD(400,210,65,50,30);
    rect(320,210,65,30);
    paralD(255,210,65,50,30 ,true);

    paralH(500,250,125,75,25);
    rect(525,225,15,125);

    paralH(190,215,70,150,55);
    paralH(505,255,100,60,15);

    glutSwapBuffers();
}

void reshape(int ww, int wh){
    glViewport( 0, 0, ww, wh );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0, GLdouble (ww), GLdouble (wh),0 );
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Cube");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
