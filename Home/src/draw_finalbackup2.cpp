// 412024022 - Brandon Jeremiah Sutedja

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int x_mid, y_mid;

//void gambar bresenham_line secara vertikal
void drawBresenCenterLine(int x_st, int y_st, int x_to, int y_to, int color) 
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
    putpixel(x, y, color);
    i = 0;

    if (abs(delta_y) < abs(delta_x))
    {
        p = (2 * abs(delta_y)) - abs(delta_x);
        do {
            if (p < 0) {
                x = x + xtemp;
                p = p + 2 * abs(delta_y);
            } else {
                x = x + xtemp;
                y = y + ytemp;
                p = p + 2 * abs(delta_y) - 2 * abs(delta_x);
            }
            putpixel(x, y, color);
            i++;
        } while (i <= abs(delta_x));
    }
    else
    {
        p = (2 * abs(delta_x)) - abs(delta_y);
        do {
            if (p < 0) {
                y = y + ytemp;
                p = p + 2 * abs(delta_x);
            } else {
                x = x + xtemp;
                y = y + ytemp;
                p = p + 2 * abs(delta_x) - 2 * abs(delta_y);
            }
            putpixel(x, y, color);
            i++;
        } while (i <= abs(delta_y));
    }
}

void boundaryFill(int x, int y, int fore, int back)
{
    if (getpixel(x, y) != back && getpixel(x, y) != fore)
    {
        putpixel(x, y, fore);
        boundaryFill(x+1, y, fore, back); // kanan
        boundaryFill(x-1, y, fore, back); // kiri
        boundaryFill(x, y+1, fore, back); // bawah
        boundaryFill(x, y-1, fore, back); // atas
    }
}

//void gambar kotak warna ungu
void drawSquareWarnaUngu(int xa, int ya, int xb, int yb, int color)
{
    drawBresenCenterLine(xa, ya, xb, ya, color);
    drawBresenCenterLine(xa, ya, xa, yb, color);
    drawBresenCenterLine(xb, ya, xb, yb, color);
    drawBresenCenterLine(xa, yb, xb, yb, color);
}

//void gamnbar triangle warna ungu muda
float degressToRadians(float angle)
{
    return angle * M_PI / 180;
}

void drawTriangleWarnaUnguMuda(int xa, int ya, int angle, int sideLen, int color)
{
    int xb = sideLen * cos(degressToRadians(angle-30))+xa;
    int yb = sideLen * sin(degressToRadians(angle-30))+ya;

    int xc = sideLen * cos(degressToRadians(angle+30))+xa;
    int yc = sideLen * sin(degressToRadians(angle+30))+ya;

    drawBresenCenterLine(xa, ya, xb, yb, color);
    drawBresenCenterLine(xb, yb, xc, yc, color);
    drawBresenCenterLine(xa, ya, xc, yc, color);
}


//void gambar lingkaran warna merah pake metode trigonometri (tripoint)
void drawCircleWarnaMerah(int xc, int yc, int r, float theta_s, float theta_e, int color)
{
    float theta_inc = 1.0 / (float)r;
    float theta, x, y;
    theta_s = degressToRadians(theta_s);
    theta_e = degressToRadians(theta_e);
    if (theta_e < theta_s) {
        theta_e = 2 * M_PI + theta_e;
    }
    theta = theta_s;
    do 
    {
        x = (float)r * cos(theta);
        y = (float)r * sin(theta);
        putpixel(round(xc+x), round(yc+y), color);
        theta = theta + theta_inc;
    } while (theta <= theta_e);
}

//void gambar elipse warna pink
void elipsePlotpoint(int xc, int yc, int x, int y, int color)
{
    putpixel(xc+x, yc+y, color);
    putpixel(xc-x, yc+y, color);
    putpixel(xc+x, yc-y, color);
    putpixel(xc-x, yc-y, color);
}

void drawMidpointElipseWarnaPink(int xc, int yc, int rx, int ry, int color)
{
    int rx2 = rx * rx;
    int ry2 = ry * ry;

    //region 1
    int x1 = 0;
    int y1 = ry;
    int p1 = ry2 - (rx2*ry) + (rx2/4); 

     //Gambar Elips utk area
    elipsePlotpoint(xc, yc, x1, y1, color);
    do
    {
        if (p1 < 0)
        {
            x1 = x1 + 1;
            p1 = p1 + 2 * ry2 * x1 + ry2;
        }
        else
        {
            x1 = x1 + 1;
            y1 = y1 - 1;
            p1 = p1 + 2 * ry2 * x1 - 2 * rx2 * y1 + ry2;
        }
        //Gambar Elips utk 4 area
        elipsePlotpoint(xc, yc, x1, y1, color);
     } while (2 * ry2 * x1 < 2 * rx2 * y1); 

    //region 2 
    int x2 = x1;
    int y2 = y1;
    int p2 = (int)(ry2 * (x2+0.5) * (x2+0.5) + rx2 * (y2-1) * (y2-1) - rx2 * ry2);
    
    //Gambar elips utk 4 area
    do 
    {
        if (p2 > 0)
        {
            y2 = y2 - 1;
            p2 = p2 - 2 * rx2 * y2 + rx2;
        }
        else
        {
            x2 = x2 + 1;
            y2 = y2 - 1;
            p2 = p2 + 2 * ry2 * x2 - 2 * rx2 * y2 + rx2;
        }
        //Gambar elips untuk 4 area
        elipsePlotpoint(xc, yc, x2, y2, color);
    } while (y2 > 0);
}

int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();

    x_mid = getmaxx() / 2;
    y_mid = getmaxy() / 2;

    //gambar square
    drawSquareWarnaUngu(
        x_mid - 300/2,  //sisi kiri
        y_mid - 300/2,  //sisi atas
        x_mid + 300/2,  //sisi kanan
        y_mid + 300/2,  //sisi bawah
        YELLOW
    );
    boundaryFill(x_mid, y_mid, MAGENTA, YELLOW);

    //gambar triangle
    drawTriangleWarnaUnguMuda(
        x_mid,
        y_mid - 112, //posisi atas segitiga
        90, //sudut
        259, //panjang sisi
        WHITE
    );
    boundaryFill(x_mid, y_mid + 37, LIGHTBLUE, WHITE);

    //gambar circle
    drawCircleWarnaMerah(
        x_mid,
        y_mid + 37, //pusat Y
        75, //jari-jari lingkaran
        0,
        360,
        YELLOW
    );
    boundaryFill(x_mid, y_mid + 37, RED, YELLOW);

    //gambar elipse
    drawMidpointElipseWarnaPink(
        x_mid,
        y_mid + 37, //pusat sama dengan lingkaran
        75, //jari-jari sb X
        20, //jari-jari sb Y
        WHITE
    );
    boundaryFill(x_mid, y_mid + 37, LIGHTMAGENTA, WHITE);

    //gambar garis tengah vertikal di elipse 
    drawBresenCenterLine(
        x_mid, //x tengah
        (y_mid + 37) - 20, //y atas
        x_mid, //x bawah
        (y_mid + 37) + 20, //y bawah
        BLACK
    );

    system("pause");
    getch();
    closegraph();
}

// 412024022 - Brandon Jeremiah Sutedja