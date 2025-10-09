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

void scanlineFill (int n, int color)
{
    float slope[20];
    int delta_x, delta_y, k, i, j,xi[20], yi[20], temp, y;\

    for(i = 0; i < n; i++)
    {
        delta_x = koor[i+1][0] - koor[i][0];
        delta_y = koor[i+1][1] - koor[i][1];
        if(delta_y == 0) slope[i] = 1.0;
        if(delta_x == 0) slope[i] = 0.0;
        if((delta_y != 0) && (delta_x != 0))
            slope[i] = (float) delta_x/delta_y;
    }
    for(y = 0; y < 480; y++) //ambil nilai terendah dan tertinggi yang ada
    {
        k = 0;
        for(i = 0; i < n; i++)
        {
            if(((koor[i][1] <= y) && (koor[i+1][1]>y)) || (((koor[i][1] > y) && koor[i+1][1] <= y)))
            {
                xi[k] =(int) (koor[i][0]) + slope[i] * (y-koor[i][1]);
                k++;
            }       
        }
        
        for (j = 0; j < k; j++)
        {
            for(i = 0 ; i < k; i++)
            {
                if(xi[i] > xi [i+1])
                { 
                    temp = xi[i];
                    xi[i] = xi[i+1];
                }
            }
        }

        for(i = 0; i < k; i += 2)
        {
            printf("%d %d - %d, %d\n", xi[i], y, xi[i+1], y);
            // dda_line(xi[i], y, xi[i+1]+1, y, color);    
            bre_line(xi[i]+x_mid, y_mid - y, xi[i+1]+x_mid+1, y_mid - y, color);
        }

        /* for(i=0;i<k;i+=2)
            for(j = 0;j<100;j++)
            {
                dda_line(xi[i]+1,y+(float)j/100,xi[i+1]+1,y+(float)j/100, color);
            } */
    }
}

void coordCenter(int n)
{
    float a, t;
    int i;

    a = 0.0;
    for (i=0; i<n; i++) {
        a += koor[i][0] * koor[i+1][1] - koor[i+1][0] * koor[i][1];
    }
    a *= 0.5;

    cx = cy = 0.0;
    for (i=0; i<n; i++) {
        t = koor[i][0] * koor[i+1][1] - koor[i+1][0] * koor[i][1];
        cx += (koor[i][0]+koor[i+1][0]) * t;
        cy += (koor[i][1]+koor[i+1][1]) * t;
    }
    cx = cx / (6.0 * a);
    cy = cy / (6.0 * a);
}

void boundaryFill(int x, int y, int fore, int back)
{
    if(getpixel(x,y) != back && getpixel(x,y) != fore)
    {
        putpixel(x,y, fore);
        boundaryFill(x+1,y,fore,back); //kanan
        boundaryFill(x,y+1,fore,back); //atas
        boundaryFill(x-1,y,fore,back); //kiri
        boundaryFill(x,y-1,fore,back); //bawah 
    }
}

void floodFill(int x, int y, int newC, int oldC)
{
    if(getpixel(x,y) == oldC)
    {
        putpixel(x,y, newC);
        floodFill(x+1,y,newC,oldC); //kanan
        floodFill(x,y+1,newC,oldC); //atas
        floodFill(x-1,y,newC,oldC); //kiri
        floodFill(x,y-1,newC,oldC); //bawah 
    }
}

// using boundaryFill -----------------------
int main()
{
    int gm, gd = DETECT;
    int n;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();

    int xmax = getmaxx(), ymax = getmaxy();
    x_mid = xmax / 2;
    y_mid = ymax / 2;

    printf("Masukkan jumlah sisi polygon: ");
    scanf("%d", &n);

    polygon(n,15);
    // polygon(n,YELLOW);
    // scanlineFill(n,4);

    coordCenter(n);
    boundaryFill(int(cx)+x_mid,y_mid-int(cy),4,15);

    // int oldC = getpixel(int(cx)+x_mid,y_mid-int(cy));
    // floodFill(int(cx)+x_mid,y_mid-int(cy),4,oldC);
    // floodFill(int(cx)+x_mid,y_mid-int(cy),BLUE,oldC);

    getch();
    closegraph();
}

// using floodFill -------------------------------
// int main()
// {
//     int gm, gd = DETECT;
//     int n;
//     char data[] = "C:\\MinGW\\lib\\libbgi.a";
//     initgraph(&gd, &gm, data);
//     cleardevice();

//     int xmax = getmaxx(), ymax = getmaxy();
//     x_mid = xmax / 2;
//     y_mid = ymax / 2;

//     printf("Masukkan jumlah sisi polygon: ");
//     scanf("%d", &n);

// 	polygon(n,15);
// 	// polygon(n,YELLOW);
//     // scanlineFill(n,4);

// 	coordCenter(n);
//     // boundaryFill(int(cx)+x_mid,y_mid-int(cy),4,15);

//     int oldC = getpixel(int(cx)+x_mid,y_mid-int(cy));
//     floodFill(int(cx)+x_mid,y_mid-int(cy),4,oldC);
//     // floodFill(int(cx)+x_mid,y_mid-int(cy),BLUE,oldC);

//     getch();
//     closegraph();
// }


// using scanlineFill
// int main()
// {
//     int gm, gd = DETECT;
//     int n;
//     char data[] = "C:\\MinGW\\lib\\libbgi.a";
//     initgraph(&gd, &gm, data);
//     cleardevice();

//     int xmax = getmaxx(), ymax = getmaxy();
//     x_mid = xmax / 2;
//     y_mid = ymax / 2;

//     printf("Masukkan jumlah sisi polygon: ");
//     scanf("%d", &n);

// 	polygon(n,15);
// 	// polygon(n,YELLOW);
//     scanlineFill(n,4);

// 	coordCenter(n);
//     // boundaryFill(int(cx)+x_mid,y_mid-int(cy),4,15);

//     // int oldC = getpixel(int(cx)+x_mid,y_mid-int(cy));
//     // floodFill(int(cx)+x_mid,y_mid-int(cy),4,oldC);
//     // floodFill(int(cx)+x_mid,y_mid-int(cy),BLUE,oldC);

//     getch();
//     closegraph();
// }


// Masukkan jumlah sisi polygon: 5
// Masukkan Nilai Koordinat Titik ke-1;0 50
// Masukkan Nilai Koordinat Titik ke-2;75 20
// Masukkan Nilai Koordinat Titik ke-3;50 -30
// Masukkan Nilai Koordinat Titik ke-4;-50 -30
// Masukkan Nilai Koordinat Titik ke-5;-75 20   

// Masukkan jumlah sisi polygon: 6
// Masukkan Nilai Koordinat Titik ke-1: 0 50
// Masukkan Nilai Koordinat Titik ke-2: 25 25
// Masukkan Nilai Koordinat Titik ke-3: 25 -25
// Masukkan Nilai Koordinat Titik ke-4: 0 -50
// Masukkan Nilai Koordinat Titik ke-5: -25 -25
// Masukkan Nilai Koordinat Titik ke-6: -25 25

