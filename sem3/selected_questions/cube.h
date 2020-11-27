#ifndef GLFW_TEMPLATE_LINUX_CUBE_H
#define GLFW_TEMPLATE_LINUX_CUBE_H
#include <GL/glut.h>

#define S 0.5
const int size = 24,sizeP = 20;
struct V{
public:
    float x,y,z;
    V(){
        x = 0;y = 0;z = 0;
    }

    V(float a, float b, float c){
        x = a;y = b;z = c;
    }
};
V v[size] = {
        {S,S,S},
        {S,-S,S},
        {-S,-S,S},
        {-S,S,S},

        {S,S,-S},
        {S,-S,-S},
        {-S,-S,-S},
        {-S,S,-S},

        {-S,S,S},
        {-S,-S,S},
        { -S,-S,-S},
        { -S,S,-S},

        {S,S,S},
        {S,-S,S},
        { S,-S,-S},
        { S,S,-S},

        {S,-S,-S},
        {S,-S,S},
        {-S,-S,S},
        {-S,-S,-S},

        {S,S,-S},
        {S,S,S},
        {-S,S,S},
        {-S,S,-S}
};

V color[size/4] = {
        {1,0,0},
        {0,1,0},
        {0,0,1},
        {1,0,1},
        {1,1,0},
        {1,1,1}
};

V vP[sizeP] = {
        {0,S,S},
        {S,-S,S},
        {-S,-S,S},
        {0,S,S},

        {0,S,-S},
        {S,-S,-S},
        {-S,-S,-S},
        {0,S,-S},

        {S,-S,S},
        {S,-S,-S},
        {-S,-S,-S},
        {-S,-S,S},

        {0,S,S},
        {0,S,-S},
        {S,-S,-S},
        {S,-S,S},

        {0,S,S},
        {0,S,-S},
        {-S,-S,-S},
        {-S,-S,S}
};

void cube(float x ,float y,float z,bool i){
    for(int a = 0; a < size;a+=4){
        if(i) glColor3d(color[a/4].x,color[a/4].y,color[a/4].z);
        else glColor3d(color[a/4].y,color[a/4].z,color[a/4].x);
        glBegin(GL_POLYGON);
        glVertex3f(x+v[a+0].x,y+v[a+0].y,z+v[a+0].z);
        glVertex3f(x+v[a+1].x,y+v[a+1].y,z+v[a+1].z);
        glVertex3f(x+v[a+2].x,y+v[a+2].y,z+v[a+2].z);
        glVertex3f(x+v[a+3].x,y+v[a+3].y,z+v[a+3].z);
        glEnd();
    }
}

void prisma(){
    for(int a = 0; a < sizeP;a+=4){
        glColor3d(color[a/4].y,color[a/4].z,color[a/4].x);
        glBegin(GL_POLYGON);
        glVertex3f(vP[a+0].x,vP[a+0].y,vP[a+0].z);
        glVertex3f(vP[a+1].x,vP[a+1].y,vP[a+1].z);
        glVertex3f(vP[a+2].x,vP[a+2].y,vP[a+2].z);
        glVertex3f(vP[a+3].x,vP[a+3].y,vP[a+3].z);
        glEnd();
    }
}

#endif //GLFW_TEMPLATE_LINUX_CUBE_H
