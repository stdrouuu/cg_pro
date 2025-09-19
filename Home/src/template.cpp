#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <graphics.h>
int main()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
    // Declaration of variables
    initgraph(&gd, &gm, data);
    cleardevice();
    getch();
    closegraph();

    return 0;
}