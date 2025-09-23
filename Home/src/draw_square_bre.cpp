#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>

int x_mid, y_mid;

//diambil dari soal_3.cpp
void bre_line(int xa, int ya, int xb, int yb) // titik awal (xa, ya), titik akhir (xb, yb)
{
    int delta_x, delta_y, p;
    int x, y, i;
    int xtemp, ytemp;

    delta_x = xb - xa;
    delta_y = yb - ya;

    if(delta_x >= 0) xtemp = 1;
    else xtemp: -1;

    if (delta_y >= 0) ytemp = 1;
    else ytemp = -1;

    x = xa;
    y = ya;
    putpixel(x + x_mid, y_mid - y, WHITE);
    i = 0;

    if (abs(delta_y) < abs(delta_x))
    {
        p = (2 * abs(delta_y)) - abs(delta_x);
        do
        {
            if (p < 0)
            {
                x = x + xtemp;
                p = p + 2 * abs(delta_y);
            }
            else
            {
                x = x + xtemp;
                y = y + ytemp;
                p = p + 2 * abs(delta_y) - 2 * abs(delta_x);
            }
            putpixel(x + x_mid, y_mid - y, WHITE);
            i++;
        } while (i <= abs(delta_x));
    }
    else
    {
        p = (2 * abs(delta_x)) - abs(delta_y);
        do
        {
            if (p < 0)
            {
                y = y + ytemp;
                p = p + 2 * abs(delta_x);
            }
            else
            {
                x = x + xtemp;
                y = y + ytemp;
                p = p + 2 * abs(delta_x) - 2 * abs(delta_y);
            }
            putpixel(x + x_mid, y_mid - y, YELLOW);
            i++;
        } while (i <= abs(delta_y));
    }
}

void square_font(int xa, int ya, int xb, int yb) 
{
    bre_line(xa, ya, xb, ya);
    bre_line(xa, ya, xa, yb);
    bre_line(xb, ya, xb, yb);
    bre_line(xa, yb, xb, yb);
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
