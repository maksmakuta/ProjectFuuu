#include "colorUtils.h"
#include <vector>
#include <cmath>
using namespace std;
int P = 15;

char* colorB = (char*)"FF00FF";

int x= 2,y = 3;
int w,h;

struct Point{
    int x,y;
    Point(){
        x = 0;
        y = 0;
    }

    Point(int a, int b){
        x = a;
        y = b;
    }
};

vector<Point> line;

void drawCircle(int xC,int yC ,int r){
    glBegin(GL_POLYGON);
    for(double a = 0.0; a < 2.0*3.14;a+=0.1){
        int i = P*xC +P/2 + (r/2)*sin(a);
        int j = P*yC +P/2 + (r/2)*cos(a);
        glVertex2i(i,j);
    }
    glEnd();
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3d(1.0,1.0,1.0);
    for(int b = 0; b < w; b+=P){
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2i(w,b);
        glVertex2i(0,b);
        glEnd();
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2i(b, 0);
        glVertex2i(b, h);
        glEnd();

    }
    glColor(colorB);
    if(line.size() >= 3) {
        for (int a = 0; a < line.size() - 2; a++) {
            Point ix = line[a];
            Point iy = line[a + 1];
            glLineWidth(5);
            glBegin(GL_LINES);
            glVertex2i(ix.x, ix.y);
            glVertex2i(iy.x, iy.y);
            glEnd();
        }
    }
    drawCircle(x,y,P);

    glutSwapBuffers();
}

void key(unsigned char a, int xT, int yT){
    switch (a) {
        case 'z': P++; if(P > 75)P = 75; break;
        case 'x': P--; if(P < 2)P = 2; break;
        case 'c': line.clear(); break;
        case 'q': exit(0);
        default: break;
    }
    glutPostRedisplay();
}

void keySP(int a, int b, int c){
    switch (a) {
        case GLUT_KEY_UP    : y--;if(y < 0)     y = 0;    break;
        case GLUT_KEY_LEFT  : x--;if(x < 0)     x = 0;    break;
        case GLUT_KEY_DOWN  : y++;if(y > h/P)   y = h/P;  break;
        case GLUT_KEY_RIGHT : x++;if(x > w/P)   x = w/P;  break;
        default: break;
    }

    int i = P*x +P/2;
    int j = P*y +P/2;
    Point p(i,j);
    line.push_back(p);
    glutPostRedisplay();
}

void reshape(int ww, int wh){
    glViewport( 0, 0, ww, wh );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0, GLdouble (ww), GLdouble (wh),0 );
    w = ww;
    h = wh;
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Cube");


    w = glutGet(GLUT_WINDOW_WIDTH);
    h = glutGet(GLUT_WINDOW_HEIGHT);

    glutDisplayFunc(draw);
    glutKeyboardFunc(key);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keySP);
    glutMainLoop();
    return 0;
}
