#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>


int main ()
{
    int gm, gd = DETECT;
    char data[] = "C:\\BMinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();
    int xmax = getmaxx(), ymax = getmaxy();

    // coding graphics
    int xa = 0, ya= 60, xb = -30, yb = 0;
    int delta_x, delta_y, dda;
    int x_mid = xmax/2;
    int y_mid = ymax/2;
    float x_inc, y_inc, x, y, i;

    setcolor(RED);
    line(0, y_mid, xmax, y_mid);
    line(x_mid, 0,  x_mid, ymax);

    delta_x = xb - xa;
    delta_y = yb - ya;

    if(abs(delta_y) < abs(delta_x)) dda = abs(delta_x);
    else dda = abs(delta_y);
    x_inc = delta_x / (float)dda;
    y_inc = delta_y / (float)dda;

    x = xa, y = ya;
    putpixel(x + x_mid, y_mid - y, WHITE);
    i = 0;
    do  
    {
        x = x + x_inc;
        y = y + y_inc;
        printf("X: &f; Y: %f\n", x + x_mid, y_mid - y);
        putpixel(x + x_mid, y_mid- y, WHITE);
        i++;
    } 
    while (i<=dda);
    getch();
    closegraph();
}
