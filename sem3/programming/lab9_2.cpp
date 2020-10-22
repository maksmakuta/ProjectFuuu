#include <GL/glut.h>
void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}
void d()
{
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(125, 350);
    glVertex2f(245, 350);
    glVertex2f(290, 300);
    glVertex2f(182, 200);
    glVertex2f(75, 300);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glVertex2f(109, 333);
    glVertex2f(138, 350);
    glVertex2f(159, 337);
    glVertex2f(123, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(109, 333);
    glVertex2f(123, 300);
    glVertex2f(154, 225);
    glVertex2f(92, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(290, 300);
    glVertex2f(75, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(123, 300);
    glVertex2f(159, 337);
    glVertex2f(154, 300);
    glVertex2f(171, 225);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(181, 300);
    glVertex2f(159, 337);
    glVertex2f(181, 350);
    glVertex2f(209, 337);
    glVertex2f(181, 300);
    glVertex2f(171, 225);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(181, 300);
    glVertex2f(209, 337);
    glVertex2f(219, 300);
    glVertex2f(195, 225);
    glVertex2f(181, 300);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(209, 337);
    glVertex2f(243, 300);
    glVertex2f(195, 225);
    glVertex2f(219, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(209, 337);
    glVertex2f(229, 350);
    glVertex2f(260, 333);
    glVertex2f(243, 300);
    glVertex2f(209, 337);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(260, 333);
    glVertex2f(278, 300);
    glVertex2f(210, 225);
    glVertex2f(243, 300);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(195, 225);
    glVertex2f(182, 200);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(171, 225);
    glVertex2f(182, 200);
    glEnd();
    glutSwapBuffers();
}

void draw(){
    float bottomY = 200.0f;
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    d();

    glTranslatef( 0.0f, bottomY , 0.0f );
    glScalef( 1.0f, -1.0f, 1.0f );
    glTranslatef( 0.0f, -bottomY , 0.0f );

    d();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Drawer");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
