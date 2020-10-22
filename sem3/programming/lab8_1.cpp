//#include <windows.h>
#include <GL/glut.h> // підключаємо бібліотеки
void Draw(){
    glColor3d(1,0,0);
    glBegin (GL_TRIANGLES);
    glColor3f (12.0, 0.0, 0.0); //червоний
    glVertex3f (0.0, 0.0, 0.0);
    glColor3f(0,1,0); //зелений
    glVertex3f (1.0, 0.0, 0.0);
    glColor3f(0.0,0.0,1.0); //блакитний
    glVertex3f (1.0, 1.0, 0.0);
    glEnd ();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5,0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glEnd ();
    glFlush ();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,100);
    glutInitDisplayMode(GLUT_DEPTH);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
