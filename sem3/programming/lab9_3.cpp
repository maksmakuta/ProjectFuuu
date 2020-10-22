//#include <windows.h>
#include <GL/glut.h> // підключаємо бібліотеки
#include <cstdio>
#include "colorUtils.h"

bool isColored = false;
int rotate = 1; // X, Y, Z
double angle = 0.0; // 0.0 .. 360.0
char* colors[] = {
        (char*)"ff0000",(char*)"00ff00",(char*)"0000ff"
};

void setColor(char *t){
    glColor3d(color(t)[0],color(t)[1],color(t)[2]);
}

void Draw(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_DEPTH_BUFFER_BIT); glClear(GL_COLOR_BUFFER_BIT);

    glColor3d(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);

    if(isColored)setColor(colors[0]); glVertex3d(   0.15, 0.15,0.0);
    if(isColored)setColor(colors[1]); glVertex3d(   -0.15,0.15,0.0);
    if(isColored)setColor(colors[2]); glVertex3d(   0.0,  -0.15,0.0);
    glEnd ();
    glFlush();

    double x=0.0,y=0.0,z=0.0;

    switch (rotate) {
        case 1 : x=1.0;y=0.0;z=0.0; break;
        case 2 : x=0.0;y=1.0;z=0.0; break;
        case 3 : x=0.0;y=0.0;z=1.0; break;
        default: break;
    }
    glRotated(angle,x,y,z);

}
void onClick(unsigned char key, int x,int y){
    switch (key) {
        case 'c': isColored? isColored = false: isColored = true;break;
        case 'z': rotate++;if (rotate >3) rotate = 3;break;
        case 'x': rotate--;if (rotate <1) rotate = 1;break;

        case 'w': angle+=0.5;if (angle > 360.0) angle = 360.0;break;
        case 's': angle-=0.5;if (angle < 0.0) angle = 0.0;break;
    }
    glutPostRedisplay();
    printf("%f\n",angle);

}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,100);
    glutInitDisplayMode(GLUT_DEPTH);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("GLUT Primitives");
    glutKeyboardFunc(onClick);
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
