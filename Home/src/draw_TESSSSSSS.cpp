#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int x_mid, y_mid;

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

void boundaryFill(int x, int y, int fore, int back)
{
    if (getpixel(x, y) != back && getpixel(x, y) != fore)
    {
        putpixel(x, y, fore);
        boundaryFill(x + 1, y, fore, back);
        boundaryFill(x - 1, y, fore, back);
        boundaryFill(x, y + 1, fore, back);
        boundaryFill(x, y - 1, fore, back);
    }
}

void draw_square(int s)
{
    int left = -s/2, right = s/2, top = s/2, bottom = -s/2;
    bre_line(left, top, right, top, WHITE);
    bre_line(right, top, right, bottom, WHITE);
    bre_line(right, bottom, left, bottom, WHITE);
    bre_line(left, bottom, left, top, WHITE);
    boundaryFill(x_mid, y_mid, MAGENTA, WHITE); // 💗 kotak pink
}

void draw_triangle(int h_half, int w_half, int fill_y_offset)
{
    int tri[3][2] = {
        {0, h_half}, {-w_half, -h_half}, {w_half, -h_half}
    };
    bre_line(tri[0][0], tri[0][1], tri[1][0], tri[1][1], WHITE);
    bre_line(tri[1][0], tri[1][1], tri[2][0], tri[2][1], WHITE);
    bre_line(tri[2][0], tri[2][1], tri[0][0], tri[0][1], WHITE);
    boundaryFill(x_mid, y_mid + fill_y_offset, LIGHTBLUE, WHITE); // 💙 segitiga biru muda
}

void draw_circle(int radius, int color, int y_offset)
{
    int x, y, p;
    x = 0; y = radius; p = 1 - radius;
    while (x <= y)
    {
        putpixel(x_mid + x, y_mid - y + y_offset, WHITE);
        putpixel(x_mid + y, y_mid - x + y_offset, WHITE);
        putpixel(x_mid + y, y_mid + x + y_offset, WHITE);
        putpixel(x_mid + x, y_mid + y + y_offset, WHITE);
        putpixel(x_mid - x, y_mid + y + y_offset, WHITE);
        putpixel(x_mid - y, y_mid + x + y_offset, WHITE);
        putpixel(x_mid - y, y_mid - x + y_offset, WHITE);
        putpixel(x_mid - x, y_mid - y + y_offset, WHITE);
        if (p < 0) p += 2 * x + 3;
        else { p += 2 * (x - y) + 5; y--; }
        x++;
    }
    boundaryFill(x_mid, y_mid + y_offset, color, WHITE); // 🔴 lingkaran merah
}

void drawMidpointElipseWarnaPink(int a, int b, int color, int y_offset)
{
    int x = 0; int y = b;
    float d1 = (b*b) - (a*a*b) + (0.25*a*a);
    int dx = 2*b*b*x; int dy = 2*a*a*y;
    while (dx < dy)
    {
        putpixel(x_mid + x, y_mid - y + y_offset, WHITE);
        putpixel(x_mid - x, y_mid - y + y_offset, WHITE);
        putpixel(x_mid + x, y_mid + y + y_offset, WHITE);
        putpixel(x_mid - x, y_mid + y + y_offset, WHITE);
        if (d1 < 0) { x++; dx += (2*b*b); d1 += dx + (b*b); }
        else { x++; y--; dx += (2*b*b); dy -= (2*a*a); d1 += dx - dy + (b*b); }
    }
    float d2 = ((b*b)*((x+0.5)*(x+0.5))) + ((a*a)*((y-1)*(y-1))) - (a*a*b*b);
    while (y >= 0)
    {
        putpixel(x_mid + x, y_mid - y + y_offset, WHITE);
        putpixel(x_mid - x, y_mid - y + y_offset, WHITE);
        putpixel(x_mid + x, y_mid + y + y_offset, WHITE);
        putpixel(x_mid - x, y_mid + y + y_offset, WHITE);
        if (d2 > 0) { y--; dy -= (2*a*a); d2 += (a*a) - dy; }
        else { y--; x++; dx += (2*b*b); dy -= (2*a*a); d2 += dx - dy + (a*a); }
    }
    boundaryFill(x_mid, y_mid + y_offset, LIGHTMAGENTA, WHITE); // 💜 elips ungu muda
}

void draw_line_vertical(int color, int y_offset, int b)
{
    setcolor(color);
    line(x_mid, y_mid + y_offset - b, x_mid, y_mid + y_offset + b);
}

// -------------------------------------------------------------------
// 4. Main
// -------------------------------------------------------------------
int main()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();

    x_mid = getmaxx() / 2;
    y_mid = getmaxy() / 2;

    // Ukuran
    int TRI_HALF_HEIGHT = 112, TRI_HALF_WIDTH = 130;
    int CIRCLE_RADIUS = 75;
    int ELLIPSE_A = 75, ELLIPSE_B = 20;
    int Y_CENTER_OFFSET = 37;
    int SQUARE_SIZE = 300;

    // Gambar
    draw_square(SQUARE_SIZE);                           // 💗 kotak pink
    draw_triangle(TRI_HALF_HEIGHT, TRI_HALF_WIDTH, Y_CENTER_OFFSET); // 💙 segitiga biru muda
    draw_circle(CIRCLE_RADIUS, RED, Y_CENTER_OFFSET);   // 🔴 lingkaran merah
    drawMidpointElipseWarnaPink(ELLIPSE_A, ELLIPSE_B, LIGHTMAGENTA, Y_CENTER_OFFSET); // 💜 elips ungu muda
    draw_line_vertical(YELLOW, Y_CENTER_OFFSET, ELLIPSE_B);

    getch();
    closegraph();
    return 0;
}

// void elipsPlotpoint(int xc, int yc, int x, int y, int color)
// {
//     putpixel(xc + x, yc + y, color);
//     putpixel(xc - x, yc + y, color);
//     putpixel(xc + x, yc - y, color);
//     putpixel(xc - x, yc - y, color);
// }

// void drawMidpointElipseWarnaPink(int xc, int yc, int rx, int ry, int color)
// {
//     long rx2 = (long)rx * rx;
//     long ry2 = (long)ry * ry;
//     long p1 = ry2 - (long)ry * rx2 + (0.25 * rx2);

//     int x = 0;
//     int y = ry;
//     elipsePlotpoint(xc, yc, x, y, color);
//     while(ry2 * (x+1) < rx2 * (y - 0.5))
//     {
//         x++;
//         if (p1 < 0) {
//             p1 += (2 * x + 1) * ry2;
//         } else {
//             y--;
//             p1 += (2 * x + 1) * ry2 - 2 * y * rx2;
//         }
//         elipsePlotpoint(xc, yc, x, y, color);
//     }

//     long p2 = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;
//     while(y > 0)
//     {
//         y--;
//         if(p2 > 0){
//             p2 += -2 * y * rx2 + rx2;
//         } else {
//             x++;
//             p2 += 2 * x * ry2 - 2 * y * rx2 + rx2;
//         }
//         elipsePlotpoint(xc, yc, x, y, color);
//     }
// }
