#include <GL/glut.h>

int a = 0;

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void points(){
    glColor3d(1.0,1.0,1.0);

    glBegin(GL_POINTS);
    glVertex2i(200,350);
    glEnd();

    glPointSize(25.0);
    glBegin(GL_POINTS);
    glVertex2i(100,350);
    glEnd();

    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    glVertex2i(300,350);
    glEnd();

}


void lines(){
    glColor3d(1.0,0.0,0.0);

    glBegin(GL_LINES);
    glVertex2i(50,300);
    glVertex2i(350,300);
    glEnd();

    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glVertex2i(50,300);
    glVertex2i(350,300);
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0b11001100);
    glBegin(GL_LINES);
    glVertex2i(50,280);
    glVertex2i(350,280);
    glEnd();

    glLineStipple(4,0b10101010);
    glBegin(GL_LINES);
    glVertex2i(50,260);
    glVertex2i(350,260);
    glEnd();

    glLineStipple(2,0b001110011100);
    glBegin(GL_LINES);
    glVertex2i(50,240);
    glVertex2i(350,240);
    glEnd();


    glLineStipple(0,0b11000011);
    glBegin(GL_LINES);
    glVertex2i(50,220);
    glVertex2i(350,220);
    glEnd();
}

void polygons(){

    glColor3d(0.0,1.0,0.0);

    glDisable(GL_POLYGON_SMOOTH);
    glBegin(GL_POLYGON);
    glVertex2i(10,10);
    glVertex2i(100,10);
    glVertex2i(70,140);
    glEnd();


    glEnable(GL_POLYGON_SMOOTH);
    glBegin(GL_POLYGON);
    glVertex2i(100+10,10);
    glVertex2i(100+100,10);
    glVertex2i(100+70,140);
    glVertex2i(100+20,200);
    glEnd();

    glDisable(GL_POLYGON_SMOOTH);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2i(200+10,10);
    glVertex2i(200+100,10);
    glVertex2i(200+180,140);
    glVertex2i(200+120,10);
    glVertex2i(200+60,140);
    glEnd();


}
void draw(){
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);

    switch (a) {
        case 1: points();break;
        case 2: lines();break;
        case 3: polygons();break;
        case 4: exit(0);
    }
    glutSwapBuffers();
}

void key(u_char k,int q,int w){
    if(k == 'q'){
        a++;
    }

    glutPostRedisplay();
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
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
