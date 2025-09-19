#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>
int xa,ya,xb,yb;
float m,c,x,y;

void m_smaller()
{
    do{
        x = x + 1;
        y = (m * x) + c;
        putpixel(x,y, WHITE);
    }while(x<=xb);
}

void m_larger() 
{
    do{
        y = y + 1;
        x = (y - c) / m;
        putpixel(x,y, WHITE);
    }while(y<=yb);
}

int main ()
{
     printf("Masukkan NIlai kooridnat Awal: ");
     scanf("%d %d", &xa, &ya);
     printf("Masukkan Nilai kooridnat Akhir: ");
     scanf("%d %d", &xb, &yb);

     m = ((float)yb - (float)ya) / ((float)xb - (float)xa);
     c = (float)ya - (m * (float)xa);

     x = xa, y = ya;
     putpixel(x, y, WHITE);
     if (m < 1)
        m_smaller();
     else
        m_larger();
}
