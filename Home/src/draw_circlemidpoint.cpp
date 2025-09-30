#include <stdio.h> //printf, scanf
#include <stdlib.h> //getch()
#include <conio.h>
#include <math.h> //untuk bisa menggunakan PI radian
#include <graphics.h>

int x_mid, y_mid;
int koor [20] [2];
float cx, cy;
int xc, yc, r;
float theta_s, theta_e;

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

void circlePlotpoint(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);

    // putpixel(xc + y, yc + x, WHITE);
    // putpixel(xc - y, yc + x, WHITE);
    // putpixel(xc + y, yc - x, WHITE);
    // putpixel(xc - y, yc - x, WHITE);
}

void circleMidpoint(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r; 
    putpixel(x + xc, y + yc, WHITE);
    do
    {
        if(p <= 0) 
        {
            x = x + 1;
            p = p + 2*x + 1;
        }
        else 
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * x - 2 * y + 1;
        }
        //Gambar Lingkaran untuk 8 area 
        CirclePlotpoint(xc, yc, x, y);
        // putpixel(x + xc, y + yc, WHITE); 
        //jalankan tanpa circle-plotpoint
    } while(x < y);
    
}

int main ()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();

    // printf("Masukkan Nilai Koordinat Titik Tengah Lingkaran: ");
    // scanf("%d %d", &cx, &cy);
    // printf("Masukkan Nilai Radius Lingkaran: ");
    // scanf("%d", &r);
    // printf("Masukkan Nilai sudut awal Lingkaran: ");
    // scanf("%f", &theta_s);
    // printf("Masukkan Nilai sudut akhir Lingkaran: ");
    // scanf("%f", &theta_e);

    // circleTripoint(xc,yc,r,theta_s,theta_e);

    system("pause");
    getch();
    closegraph();
}
