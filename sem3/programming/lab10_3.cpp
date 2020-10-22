#include <GL/glut.h>
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}
void draw(){
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);

   glBegin(GL_LINES);
    glVertex2i(10,20);
    glVertex2i(250,20);
   glEnd();
   
    glBegin(GL_LINES);
    glVertex2i(10,20);
    glVertex2i(100,200);
    glEnd();


    glBegin(GL_LINES);
    glVertex2i(100,200);
    glVertex2i(250,200);
    glEnd();


    glBegin(GL_LINES);
    glVertex2i(250,200);
    glVertex2i(250,20);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(350,300);
    glVertex2i(250,20);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(350,300);
    glVertex2i(10,300);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(100,20);
    glVertex2i(10,300);
    glEnd();


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
