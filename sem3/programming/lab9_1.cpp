//#include <windows.h>
#include <GL/glut.h> // підключаємо бібліотеки
#include "colorUtils.h"

int types[] = {GL_POINTS,GL_LINES,GL_LINE_STRIP,
               GL_LINE_LOOP,GL_POLYGON,GL_QUADS,
               GL_QUAD_STRIP,GL_TRIANGLES,
               GL_TRIANGLE_FAN,GL_TRIANGLE_STRIP};

int type = 0;
double X = 0.00,Y = 0.00;
bool isColored = false;

char* colors[] = {
        (char*)"d50000",(char*)"6200ea",
        (char*)"2962ff",(char*)"aeea00",
        (char*)"ffd600",(char*)"ff3d00",
        (char*)"3d5afe",(char*)"64dd17"
};

void setColor(char *t){
    glColor3d(color(t)[0],color(t)[1],color(t)[2]);
}

void Draw(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_DEPTH_BUFFER_BIT); glClear(GL_COLOR_BUFFER_BIT);

    glColor3d(1.0,1.0,1.0);
    glBegin(types[type]);
    if(isColored){setColor(colors[0]);} glVertex3d( 0.1+X, 0.5+Y,0.0);
    if(isColored){setColor(colors[1]);} glVertex3d( 0.5+X, 0.1+Y,0.0);
    if(isColored){setColor(colors[2]);} glVertex3d( 0.5+X,-0.1+Y,0.0);
    if(isColored){setColor(colors[3]);} glVertex3d( 0.1+X,-0.5+Y,0.0);
    if(isColored){setColor(colors[4]);} glVertex3d(-0.1+X,-0.5+Y,0.0);
    if(isColored){setColor(colors[5]);} glVertex3d(-0.5+X,-0.1+Y,0.0);
    if(isColored){setColor(colors[6]);} glVertex3d(-0.5+X, 0.1+Y,0.0);
    if(isColored){setColor(colors[7]);} glVertex3d(-0.1+X, 0.5+Y,0.0);
    glEnd ();
    glFlush();
    glClearColor(0.0,0.0,0.0,1.0);
}
void onClick(unsigned char key, int x,int y){
    switch (key) {
        case 'z': type++;if (type >10) type = 10;break;
        case 'x': type--; if (type <0) type = 0;break;
        case 'q': isColored? isColored = false : isColored = true;break;

        case 'd': X+=0.01;if (X >1.0)  X =  1.0;break;
        case 'a': X-=0.01;if (X <-1.0) X = -1.0;break;
        case 'w': Y+=0.01;if (Y >1.0)  Y =  1.0;break;
        case 's': Y-=0.01;if (Y <-1.0) Y = -1.0;break;

        default: type = type;
    }
    glutPostRedisplay();
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
