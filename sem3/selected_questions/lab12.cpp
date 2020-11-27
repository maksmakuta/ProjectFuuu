#include "cube.h"

#define T true
#define F false

int Task = 2;
int fig = 0;

using namespace std;

float degX = 0.0f,degY = 0.0f;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glRotatef(degX, 1, 0, 0);
    glRotatef(degY, 0, 1, 0);

    if(Task == 1) {
        cube(-1, -1, 0, F);
        cube(0, -1, 0, T);
        cube(1, -1, 0, T);
        cube(-1, 0, 0, T);
        cube(0, 0, 0, F);
        cube(1, 0, 0, T);
        cube(-1, 1, 0, T);
        cube(0, 1, 0, T);
        cube(1, 1, 0, F);
    }else if(Task == 2){
        prisma();
    }else {
        //glutInit(nullptr, nullptr);
        if (fig == 1) gluCylinder(gluNewQuadric(), 0.5, 0.5, 0.7, 10, 12);
        else if (fig == 2) gluDisk(gluNewQuadric(), 0.1, 0.8, 10, 12);
        else if(fig == 3) gluSphere(gluNewQuadric(), 0.7, 10, 12);
        else if(fig == 4) glutSolidCone(0.7,0.7,15,9);
        else if(fig == 5) glutSolidDodecahedron();
        else if(fig == 6) glutSolidOctahedron();
        else if(fig == 7) glutSolidTeapot(0.5);
        else if(fig == 8) glutSolidTetrahedron();
        else glutSolidTorus(0.1,0.8,20,25);
    }

    glFlush();
/*
    glutSwapBuffers();
    glutPostRedisplay();*/
}

void init(){
    if(Task == 1)
        glOrtho(-5,5,-5,5,-5,5);
    else
        glOrtho(-1,1,-1,1,-1,1);

}

void key_callback(u_char key, int action, int mods)
{
        switch (key) {
            case 27 : exit(0);
            case 'r':case 'R':degX = degY = 0.0f;break;
            case '1' : if(Task == 3) fig = 1; break;
            case '2' : if(Task == 3) fig = 2; break;
            case '3' : if(Task == 3) fig = 3; break;
            case '4' : if(Task == 3) fig = 4; break;
            case '5' : if(Task == 3) fig = 5; break;
            case '6' : if(Task == 3) fig = 6; break;
            case '7' : if(Task == 3) fig = 7; break;
            case '8' : if(Task == 3) fig = 8; break;
            case '9' : if(Task == 3) fig = 9; break;
        }
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

void sp_callback(int key, int, int){
    switch (key) {
        case GLUT_KEY_UP:degY += 0.1f;break;
        case GLUT_KEY_DOWN:degY -= 0.1f;break;
        case GLUT_KEY_RIGHT:degX += 0.1f;break;
        case GLUT_KEY_LEFT:degX -= 0.1f;break;

        case GLUT_KEY_F1: Task = 1; init();break;
        case GLUT_KEY_F2: Task = 2; init();break;
        case GLUT_KEY_F3: Task = 3; init();break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,100);
    glutInitDisplayMode(GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    glDepthFunc(GL_LESS);

    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("GLUT Primitives");
    glutKeyboardFunc(key_callback);
    glutSpecialFunc(sp_callback);
    glutDisplayFunc(display);
    init();
    timer(0);
    glutMainLoop();

    return 0;
}