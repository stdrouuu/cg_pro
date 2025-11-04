#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

float koor_rot[2][2]; 

void rotation(int koor[2][2], float koor_rot[2][2], float angle)
{
    float rad = angle * M_PI / 180.0; 

    for (int i = 0; i < 2; i++) { 
        koor_rot[i][0] = round(koor[i][0] * cos(rad) - koor[i][1] * sin(rad));
        koor_rot[i][1] = round(koor[i][0] * sin(rad) + koor[i][1] * cos(rad));
    }
}

int main()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();

    int koor[2][2];
    float angle = 45.0; //sudut rotasinya dideclare 45 drjt

    for (int i = 0; i < 2; i++) {
        (i == 0) ? printf("Koordinat awal:\n"):printf("Koordinat akhir:\n");
        printf("Masukkan nilai X: ");scanf("%d", &koor[i][0]);
        printf("Masukkan nilai Y: ");scanf("%d", &koor[i][1]);
    }

    rotation(koor, koor_rot, angle);

    setcolor(CYAN); //sblm rotasi
    line(koor[0][0], koor[0][1], koor[1][0], koor[1][1]);
    setcolor(YELLOW); //hasil rotasinya
    line(koor_rot[0][0], koor_rot[0][1], koor_rot[1][0], koor_rot[1][1]);

    getch();
    closegraph();

    return 0;
}

// Koordinat awal:
// Masukkan nilai X: 100
// Masukkan nilai Y: 50
// Koordinat akhir:
// Masukkan nilai X: 200
// Masukkan nilai Y: 50
