//#include <windows.h>
#include <GL/glut.h> // підключаємо бібліотеки

int types[] = {GL_POINTS,GL_LINES,GL_LINE_STRIP,
               GL_LINE_LOOP,GL_POLYGON,GL_QUADS,
               GL_QUAD_STRIP,GL_TRIANGLES,
               GL_TRIANGLE_FAN,GL_TRIANGLE_STRIP};

int type = 0;
bool color = false;

char* colors[] = {
        "d50000","6200ea",
        "2962ff","aeea00",
        "ffd600","ff3d00",
        "3d5afe","64dd17"
};

int i(char a){
    switch (a) {
        case '0' : return 0;
        case '1' : return 1;
        case '2' : return 2;
        case '3' : return 3;
        case '4' : return 4;
        case '5' : return 5;
        case '6' : return 6;
        case '7' : return 7;
        case '8' : return 8;
        case '9' : return 9;
        case 'a' : return 10;
        case 'b' : return 11;
        case 'c' : return 12;
        case 'd' : return 13;
        case 'e' : return 14;
        case 'f' : return 15;
    }
    return -1;
}

void setColor(char* text){
    double color[3];
    for(int a = 0; a < 3; a++){
        int c1 = i(text[a*2]);
        int c2 = i(text[a*2+1]);
        int c = c1 * c2;
        color[a] = c/255.0;
    }
    glColor3d(color[0],color[1],color[2]);
}

void Draw(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_DEPTH_BUFFER_BIT); glClear(GL_COLOR_BUFFER_BIT);

    glColor3d(1.0,1.0,1.0);
    glBegin(types[type]);
    if(color){setColor(colors[0]);} glVertex3d(0.1,0.5,0.0);
    if(color){setColor(colors[1]);} glVertex3d(0.5,0.1,0.0);
    if(color){setColor(colors[2]);} glVertex3d(0.5,-0.1,0.0);
    if(color){setColor(colors[3]);} glVertex3d(0.1,-0.5,0.0);
    if(color){setColor(colors[4]);} glVertex3d(-0.1,-0.5,0.0);
    if(color){setColor(colors[5]);} glVertex3d(-0.5,-0.1,0.0);
    if(color){setColor(colors[6]);} glVertex3d(-0.5,0.1,0.0);
    if(color){setColor(colors[7]);} glVertex3d(-0.1,0.5,0.0);
    glEnd ();
    glFlush();
    glClearColor(0.0,0.0,0.0,1.0);
}
void onClick(unsigned char key, int x,int y){
    switch (key) {
        case 'w': type++;if (type >10) type = 10;break;
        case 's': type--; if (type <0) type = 0;break;
        case 'q': color? color = false : color = true;break;
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
