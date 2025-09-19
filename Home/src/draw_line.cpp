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


int main ()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();
    int xmax = getmaxx(), ymax = getmaxy();

    // coding graphics
    x_mid = xmax/2;
    y_mid = ymax/2;

    int xa = 0, ya= 60, xb = -30, yb = 0;
    int delta_x, delta_y, dda;
    float x_inc, y_inc, x, y, i;

    setcolor(RED);
    line(0, y_mid, xmax, y_mid);
    line(x_mid, 0,  x_mid, ymax);

    printf("Enter start coordinate: "); scanf("%d %d", &coor_st.x, &coor_st.y);
    printf("Enter end coordinate: "); scanf("%d %d", &coor_to.x, &coor_to.y);

    // Panggil prosedur dda
    draw_dda(coor_st.x, coor_st.y, coor_to.x, coor_to.y);

    getch();
    closegraph();
}