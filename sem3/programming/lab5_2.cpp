#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void circle(int x, int y, int r, int c, int t){
    setcolor(c);
    setfillstyle(t,c);
    circle(x,y,r);
    floodfill(x,y,c);
}

void rect(int x, int y, int w,int h, int c, int t){
    setcolor(c);
    setfillstyle(t,c);
    rectangle(x,y,x+w,y+h);
    for(int a = 0; a < h;a++)
    for(int b = 0; b < w;b++)
    floodfill(x+b,y+a,c);
}

int main (){ 
    int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk) {  /* an error occurred */
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
    
    
   circle(300,300,150,WHITE,5);
   rect(150,270,300,60,WHITE,1);
   rect(280,150,40,40,WHITE,1);
   
   setcolor(WHITE);
   line(280,190,300,230);
   line(320,190,300,230);
   for(int a = 0; a < 26; a++)
       floodfill(280+a,190+a,WHITE);
   
   setcolor(RED);
   line(280,190,320,190);
    setlinestyle(USERBIT_LINE,0x3FF3, 3);
    line(300,150,300,450);
    line(150,300,450,300);
    
    getch();
    closegraph();
    return 0;
}
