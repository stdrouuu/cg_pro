#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>


int main ()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    ianitgraph(&gd, &gm, data);
    cleardevice();
    int delta_x, delta_y, p;
    int x_mid, xa, ya, xb, yb;
    int y_mid, xtemp, ytemp;
    int x, y, i;
    int xmax, ymax;

    // coding graphics
    xmax = getmaxx(); // to get the coordinates i.e. x & y
    ymax = getmaxy();
    x_mid = xmax/2; // ini diganti x 1/4
    y_mid = ymax/2; // ini diganti x 3/4

    printf("Masukkan Nilai koordinat Awal: ");
    scanf("%d %d", &xa, &ya);
    printf("Masukkan Nilai koordinat Akhir: ");
    scanf("%d %d", &xb, &yb);

    delta_x = xb - xa;
    delta_y = yb - ya;

    // if(delta_x >= 0) xtemp = 1;
    // else xtemp = -1;

    // if(delta_y >= 0) ytemp = 1;
    // else ytemp = -1;

    setcolor(RED);
    line(0, y_mid, xmax, y_mid);
    line(x_mid, 0, x_mid, ymax);

    x = xa, y = ya;
    putpixel(x + x_mid, y_mid - y, WHITE);
    i = 0;
    if (abs(delta_y) < abs(delta_x))
    {
        p = (2 * delta_y) - (delta_x);
        do
        {
            if (p < 0)
            {
                x = x + 1;
                p = p + 2 * delta_y * ytemp;
                putpixel(x + x_mid, y_mid - y, WHITE);
            }
            else
            {
                x = x + 1;
                y = y + 1;
                p = p + 2 * delta_y - 2 * delta_x;
                putpixel(x + x_mid, y_mid - y, WHITE);
            }
            i++;
        } while(i<=delta_x);
    }
    else
    {
        p = (2 * delta_x) - (delta_y);
        do
        {
            if (p < 0)
            {
                y = y + 1;
                p = p + 2 * delta_x;
                putpixel(x + x_mid, y_mid - y, WHITE);
            }
            else
            {
                x = x + 1;
                y = y + 1;
                p = p + 2 * delta_x - 2 * delta_y;
                putpixel(x + x_mid, y_mid - y, WHITE);
            }
            i++;
        }while(i<=delta_y);
    }

    getch();
    closegraph();
}

