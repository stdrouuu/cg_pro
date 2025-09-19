#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>

int x_mid, y_mid; // global declaration variable

struct coordinate{
    int x;
    int y;
}coor_st, coor_to;

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

    x = x_st, y = y_st;
    putpixel(x + x_mid, y_mid - y, WHITE);
    i = 0;
    do  
    {
        x = x + x_inc;
        y = y + y_inc;
        printf("X: &f; Y: %f\n", x, y);
        putpixel(x + x_mid, y_mid - y, WHITE);
        i++;
    } 
    while (i<=dda);
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
            putpixel(x + x_mid, y_mid - y, YELLOW);
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

    // coding graphics

    // tengah
    x_mid = xmax * 1 / 2;   
    y_mid = ymax * 1 / 2;   

    setcolor(GREEN);
    line(0, y_mid, xmax, y_mid);
    line(x_mid, 0,  x_mid, ymax);

    // untuk memunculkan kuadran 1
    int x_mid_Q1 = xmax * 3 / 4;   
    int y_mid_Q1 = ymax * 1 / 4;   

    setcolor(RED);
    line (x_mid, y_mid/2, xmax, y_mid/2 );
    line (x_mid + x_mid/2, 0, x_mid + x_mid/2,y_mid);
    line (0, y_mid + y_mid/2, x_mid, y_mid + y_mid/2);
    line (x_mid-x_mid/2,y_mid, x_mid-x_mid/2, ymax) ;

   // untuk memunculkan kuadran 3
    int x_mid_Q3 = xmax * 1 / 4;   
    int y_mid_Q3 = ymax * 3 / 4;   


    int xa = 0, ya= 60, xb = -30, yb = 0;
    int delta_x, delta_y, dda;
    float x_inc, y_inc, x, y, i;


    printf("Enter start coordinate: "); scanf("%d %d", &coor_st.x, &coor_st.y);
    printf("Enter end coordinate: "); scanf("%d %d", &coor_to.x, &coor_to.y);

     // Kuadran I menggunakan metode DDA
    x_mid = x_mid_Q1;
    y_mid = y_mid_Q1;
    draw_dda(coor_st.x, coor_st.y, coor_to.x, coor_to.y);

    // Kuadran II menggunakan metode Bresenham
    x_mid = x_mid_Q3;
    y_mid = y_mid_Q3;
    draw_bresenham(coor_st.x, coor_st.y, coor_to.x, coor_to.y);

    getch();
    closegraph();
}