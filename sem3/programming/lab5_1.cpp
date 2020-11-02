/*
 * To compile:
 * gcc -o app main.cpp /usr/lib/libXbgi.a -lX11 -lm
 *
 *
 */
#include <graphics.h>

char *data[23]  = {
        (char *)"Бонюк Тимофій",
        (char *)"Гандзюк Катерина",
        (char *)"Гейко Богдан",
        (char *)"Джигалюк Євген",
        (char *)"Карабін Назарій",
        (char *)"Кланцатий Богдан",
        (char *)"Клівчук Дмитро",
        (char *)"Книш Віталій",
        (char *)"Крищук Софія",
        (char *)"Левченко Дмитро",
        (char *)"Литвинчук Ярослав",
        (char *)"Висоцький Сергій",
        (char *)"Ляшук Владислав",
        (char *)"Макута Максим",
        (char *)"Олексюк Максим",
        (char *)"Пастушок Станіслав",
        (char *)"Пелех Герман",
        (char *)"Романюк Олександр",
        (char *)"Скорук Денис",
        (char *)"Слободюк Андрій",
        (char *)"Федчун Кирило",
        (char *)"Черенюк Андрій",
        (char *)"Ярмольський Вадим"
};

int type[10] = {
        DEFAULT_FONT,
        TRIPLEX_FONT,
        SMALL_FONT,
        GOTHIC_FONT,
        SANSSERIF_FONT
};
int colors[15] = {
        BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
        DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN,
        LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE,
};

void message (int x, int y,int col, int font, char str[])
{
    settextstyle (font, HORIZ_DIR, 15);
    setcolor (col);
    outtextxy (x, y, str);
    setusercharsize(1,1,1,1);
}


int main (/*int argc, char *argv[]*/)
{

    int gd = DETECT, gm;

    initgraph (&gd, &gm, data[0]);
    setbkcolor (WHITE);
    cleardevice();

    for(int z = 0; z < 10;z+=2){
        cleardevice();
        for(int b = 0; b < 23;b++){
            message(10,b*50,colors[b%23],type[z],data[b]);
            int p = textwidth(data[b]);
            message(10 + 15 + p,b*50,colors[(b-1)%23],type[z+1],data[b]);
        }
        getch ();
    }

    message(getmaxx()/4,getmaxy()-100,BLACK,DEFAULT_FONT,(char*)"Type any key to exit...");
    getch();
    closegraph ();

}
