#include <graphics.h>

int main ()
{
    int gdriver = VGA, gmode, errorcode;
    initgraph(&gdriver, &gmode,"C://BGI//BGI");
    errorcode = graphresult();

    if (errorcode !=grOk){
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        getch();
        exit(1);
    }
    rectangle(100,105,150,150);
    for(int a = 110; a  <= 140; a+=10){
        rectangle(90,a,100,a + 5);
        rectangle(150,a,160,a + 5);
    }
    circle(105,110,3);
    getch();
    closegraph();
    return 0;
}