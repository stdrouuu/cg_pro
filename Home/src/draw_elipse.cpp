//Elipse

#include <stdio.h> //printf, scanf
#include <stdlib.h> //getch()
#include <conio.h>
// #include <math.h> //untuk bisa menggunakan PI radian
#include <graphics.h>

int x_mid, y_mid;
int xc, yc, rx, ry;

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

void elipsPlotpoint(int xc, int yc, int x, int y)
{
    putpixel(xc + x,yc + y, WHITE);
    putpixel(xc - x,yc + y, WHITE);
    putpixel(xc + x,yc - y, WHITE);
    putpixel(xc - x,yc - y, WHITE);
}

void elipsMidpoint (int xc, int yc, int rx, int ry)
{
    int rx2 = rx * rx;
    int ry2 = ry * ry;

    //region 1
    int x1 = 0;
    int y1 = ry;
    int p1 = ry2 - ry * rx2;

    //Gambar Elips utk area
    elipsPlotpoint(xc, yc,x1, y1);
    do
    {
        if(p1 <= 0)
        {
            x1 = x1 + 1;
            p1 = p1 + (2 * x1 + 3) * ry2;
        } else 
        {
            x1 = x1 + 1;
            y1 = y1 -1 ;
            p1 = p1 + (2 * x1 + 3) * ry2 + (-2 * y1 + 2) * rx2;
        }
        //Gambar Elips utk 4 area
        elipsPlotpoint(xc,yc,x1,y1);
    } while(ry2 * x1 <= rx2 * y1);

    //reguon 2
    int x2 = rx;
    int y2 = 0;
    int p2 = rx2 - rx * ry2;
    //Gambar elips utk 4 area
    do
    {
        if (p2 <= 0)
        {
            y2 = y2 + 1;
            p2 = p2 + (2 * y2 + 3) * rx2;
        }
        else 
        {
            x2 = x2 - 1;
            y2 = y2 + 1;
            p2 = p2 + (2 * y2 + 3) * rx2 + (-2 * x2 + 2) * ry2;
        }
        //Gambar elips untuk 4 area
        elipsPlotpoint(xc, yc, x2, y2);
    } while (rx2 * y2 <= ry2 * x2);
}

int main()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();

    printf("Masukkan koordinat pusat elips: "); //(xc yc)
    scanf("%d %d", &xc, &yc);

    printf("Masukkan jari-jari elips: "); //(rx ry)
    scanf("%d %d", &rx, &ry);

    elipsMidpoint(xc, yc, rx, ry);

    system("pause");
    getch();
    closegraph();
}

// Masukkan koordinat pusat elips: 320 240
// Masukkan jari-jari elips: 150 100
