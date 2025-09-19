#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>

int x_mid, y_mid;

void draw_dda(int x_st, int y_st, int x_to, int y_to) // x awal, y awal, x akhir, y akhir
{
    int delta_x, delta_y, dda;
    float x_inc, y_inc, x, y, i;

    delta_x = x_to - x_st;
    delta_y = y_to - y_st;

    if(abs(delta_y) < abs(delta_x)) 
        dda = abs(delta_x);
    else 
        dda = abs(delta_y);

    x_inc = delta_x / (float)dda;
    y_inc = delta_y / (float)dda;

    x = x_st;
    y = y_st;

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

void draw_equation(int x_st, int y_st, int x_to, int y_to)
{
    float m, c, x, y;

    m = (float)(y_to - y_st) / (float)(x_to - x_st);
    c = (float)y_st - m * (float)x_st;

    x = x_st; 
    y = y_st;

    printf("m value: %f\n", m);
    printf("c value: %f\n", c);

    putpixel(x + x_mid, y_mid - y, WHITE);

    if (x_st < x_to) {
        do {
            x = x + 1;
            y = m * x + c;
            printf("X : %d; Y : %d\n", (int)x, (int)y);
            putpixel(x + x_mid, y_mid - y, WHITE);
        } while (x <= x_to);
    } 
    else {
        do {
            y = y + 1;
            x = (y - c) / m;
            printf("X : %d; Y : %d\n", (int)x, (int)y);
            putpixel(x + x_mid, y_mid - y, WHITE);
        } while (y <= y_to);
    }
}

void draw_bresenham(int x_st, int y_st, int x_to, int y_to)
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
            putpixel(x + x_mid, y_mid - y, WHITE);
            i++;
        } while (i <= abs(delta_y));
    }
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

    int x_st, y_st, x_to, y_to, choice;
    printf("Masukkan koordinat awal: "); // (x_st, y_st)
    scanf("%d %d", &x_st, &y_st);
    printf("Masukkan koordinat akhir: "); // (x_to, y_to)
    scanf("%d %d", &x_to, &y_to);

    printf("Pilih metode yang ingin digunakan:\n");
    printf("1. DDA\n2. Equation\n3. Bresenham\n");
    printf("Input pilihan: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            draw_dda(x_st, y_st, x_to, y_to);
            break;
        case 2:
            draw_equation(x_st, y_st, x_to, y_to);
            break;
        case 3:
            draw_bresenham(x_st, y_st, x_to, y_to);
            break;
        default:
            printf("Pilihan tidak valid\n");
    }

    getch();
    closegraph();
}


