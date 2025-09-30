#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <math.h> // pamggil M_PI
#include <graphics.h>

int x_mid, y_mid;

//diambil dari soal_3.cpp
void bre_line(int x_st, int y_st, int x_to, int y_to, int colors)
{
    int delta_x, delta_y, p;
    int x, y, i;
    int xtemp, ytemp;

    delta_x = x_to - x_st;
    delta_y = y_to - y_st;

    if (delta_x >= 0) xtemp = 1;
    else xtemp = -1;

    if (delta_y >= 0) ytemp = 1;
    else ytemp = -1;

    x = x_st;
    y = y_st;
    putpixel(x + x_mid, y_mid - y, colors);
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
            putpixel(x + x_mid, y_mid - y, colors);
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
            putpixel(x + x_mid, y_mid - y, colors);
            i++;
        } while (i <= abs(delta_y));
    }
}

float degressToRadians(float angle)
{
    return angle * M_PI / 180;
}

void triangle(int xa, int ya, int angle, int sideLen) 
{
    int xb = sideLen * cos(degressToRadians(angle - 30)) + xa;
    int yb = sideLen * sin(degressToRadians(angle - 30)) + ya;

    int xc = sideLen * cos(degressToRadians(angle + 30)) + xa;
    int yc = sideLen * sin(degressToRadians(angle + 30)) + ya;

    printf("xa: %d, ya: %d\n", xa, ya);
    printf("xb: %d, yb: %d\n", xb, yb);
    printf("xc: %d, yc: %d\n", xc, yc);
    
    // 2:green;  11:cyan;  14:kuning
    bre_line(xa, ya, xb, yb, 2);
    bre_line(xb, yb, xc, yc, 11);
    bre_line(xa, ya, xc, yc, 14);
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
    triangle(10,10,30,30); //Segitiga ke arah atas
    // triangle(10,10,-30,30); //Segitiga ke arah bawah


    getch();
    closegraph();
}
