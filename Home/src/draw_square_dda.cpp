#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>

int x_mid, y_mid;

//diambil dari soal_3.cpp
void dda_line(int xa, int ya, int xb, int yb) // titik awal (xa, ya), titik akhir (xb, yb)
{
    int delta_x, delta_y, dda;
    float x_inc, y_inc, x, y, i;

    delta_x = xb - xa;
    delta_y = yb - ya;

    if(abs(delta_y) < abs(delta_x)) 
        dda = abs(delta_x);
    else 
        dda = abs(delta_y);

    x_inc = delta_x / (float)dda;
    y_inc = delta_y / (float)dda;

    x = xa;
    y = ya;

    putpixel(x + x_mid, y_mid - y, WHITE);
    i = 0;
    do {
        x = x + x_inc;
        y = y + y_inc;
        printf("X: %f, Y: %f\n", x, y);  
        putpixel(x + x_mid, y_mid - y, WHITE);
        i++;
    } while (i <= dda);
}

void square_font(int xa, int ya, int xb, int yb) 
{
    dda_line(xa, ya, xb, ya);
    dda_line(xa, ya, xa, yb);
    dda_line(xb, ya, xb, yb);
    dda_line(xa, yb, xb, yb);
}

int main ()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();

    int xmax = getmaxx(), ymax = getmaxy();
    x_mid = xmax / 2;
    y_mid = ymax / 2;

    setcolor(RED);
    line(0, y_mid, xmax, y_mid);  
    line(x_mid, 0, x_mid, ymax);   
    square_font(10,10,50,50);


    getch();
    closegraph();
}
