#include <stdio.h> //printf, scanf
#include <stdlib.h> //getch()
#include <conio.h>
#include <math.h> //untuk bisa menggunakan PI radian
#include <graphics.h>

int x_mid, y_mid;
int koor [20] [2];
float cx, cy;
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

void polygon (int n, int color)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("Masukkan Nilai Koordinat Titik ke-%d;", i+1);
        scanf("%d %d", &koor[i][0], &koor[i][1]);

    }

    for (j=0; j < n; j++)
    {
        if(j < n-1)
            bre_line(koor[j][0], koor[j][1], koor[j+1][0], koor[j+1][1], color);
        else
            bre_line(koor[0][0], koor[0][1], koor[j][0], koor[j][1], color);
    }

}

int main ()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();
    int xmax = getmaxx(), ymax = getmaxy();

    x_mid = xmax * 1 / 2;   
    y_mid = ymax * 1 / 2;   

    setcolor(RED);
    line(0, y_mid, xmax, y_mid);
    line(x_mid, 0,  x_mid, ymax);
    polygon(5, YELLOW);

    getch();
    closegraph();
}

// Masukkan Nilai Koordinat Titik ke-1;0 50
// Masukkan Nilai Koordinat Titik ke-2;25 25
// Masukkan Nilai Koordinat Titik ke-3;25 -25
// Masukkan Nilai Koordinat Titik ke-4;10 -15
// Masukkan Nilai Koordinat Titik ke-5;-10 -15   
