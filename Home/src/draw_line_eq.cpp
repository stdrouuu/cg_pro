#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>

int main()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    // Declaration of variables
    int x_st, y_st, x_en, y_en;
    float m, c, x, y;

    initgraph(&gd, &gm, data);
    cleardevice();

    printf("Input start coordinate: "); scanf("%d %d", &x_st, &y_st);
    printf("Input end coordinate: "); scanf("%d %d", &x_en, &y_en);
    // (15,20)-(620,420) kiat - kaba, kaat - kiba (620,20)-(15,420)
    m = (float(y_en) - float(y_st)) / (float(x_en) - float(x_st));
    c = float(y_st) - m * float(x_st);

    x =  x_st; y = y_st;
    printf("m value: %f\n", m);
    printf("c value: %f\n", c);
    putpixel(x, y, WHITE);
    // (15,20)-(620,420) kiat - kaba
    // do 
    // {
    //     x = x + 1;
    //     y = m * x + c;
    //     printf("X : %d; Y : %d\n", int(x), int(y));
    //     putpixel(x, y, WHITE);
    // } while (x <= x_en);


    // kaat - kiba (620,20)-(15,420) 
    do 
    {
        x = (y - c) / m;
        y = y + 1;
        printf("X : %d; Y : %d\n", int(x), int(y));
        putpixel(x, y, WHITE);
    } while (y <= y_en); // loop until y <= y1 (y_en)

    getch();
    closegraph();

    return 0;
}