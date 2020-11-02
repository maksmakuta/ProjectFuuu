#include <graphics.h>

float S  = 5.0f;
#define S 10

class P{
public:
    float x, y;
    P(){
        this->x = 0.0f;
        this->y = 0.0f;
    }
    
    P(float a, float b){
        this->x = a;
        this->y = b;
    }
    
};

class Cube{
public:
    P data[S];
    int i = 0;
    int x ,y ,r;
    
    Cube(int a, int b, int d){
        this->x = a;
        this->y = b;
        this->r = d; 
        
   
        for(float t = 0.0f; t < 3.14f*2; t+=3.14f/3){
            int tx =  x + r * cos(t);
            int ty =  y + r * sin(t);
            data[i] = P(tx,ty);
            i++;
        }
        
    }
    
    void draw(){
        
        for(int a = 1; a <= S; a+=2){
            line(data[a].x,data[a].y,x,y);
            line(data[a].x,data[a].y,data[a-1].x,data[a-1].y);
            
            if(a == S-1){
                line(data[a].x,data[a].y,data[0].x,data[0].y);
            }else{
                line(data[a].x,data[a].y,data[a+1].x,data[a+1].y);
            }
            
        }
        
    }
    
    void move(float dx, float dy){
        for(int a = 0; a < S; a++){
            data[a].x += dx;
            data[a].y += dy;
        }
        
        this->x += dx;
            this->y += dy;
    }
    
    void clear(){
        cleardevice();
    }
    
};

int main (){ 
    int gdriver = X11_1024x768, gmode, errorcode;
   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk) {  /* an error occurred */
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   
   Cube a(100,100,50);
   int p = 0;
   
   while(true){
       setcolor(WHITE);
        a.draw();
        p++;
                a.move(S,0);
            cleardevice();
                if(p > 120)break;
                usleep(20*1000);
}
   
    getch();
    a.clear();
    closegraph();
    return 0;
}
