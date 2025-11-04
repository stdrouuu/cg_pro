#include <stdio.h>    // printf, scanf
#include <stdlib.h>   // getch()
#include <conio.h>
#include <math.h>     // untuk bisa menggunakan PI radian
#include <graphics.h>

int koor_tr[2][2]; 

void scaling(int koor[2][2], int koor_tr[2][2], int scale[2])
{
    for (int i = 0; i < 2; i++) 
    {
        koor_tr[i][0] = koor[i][0] * scale[0]; 
        koor_tr[i][1] = koor[i][1] * scale[1]; 
    }
}

int main()
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    int x, y;
    x = getmaxx();
    y = getmaxy();
    cleardevice();

    int koor[2][2];
    int scale[2] = {2, 1}; //2 kali lipat discaling
    //xnya dikali 2, ynya dikali 1 (ynya tetap)
    
    for(int i = 0; i < 2; i++) //baris
        {
            (i == 0)? printf("Koordinat awal:\n"):printf("Koordinat akhir:\n");
            for(int j = 0; j < 2; j++) //kolom
            {
                (j == 0)?printf("Masukkan nilai X: "):printf("Masukkan nilai Y: ");
                scanf("%d", &koor[i][j]);
            }
        }
        
        scaling(koor, koor_tr, scale);

        setcolor(CYAN); //sblm scaling
        line(koor[0][0], koor[0][1], koor[1][0], koor[1][1]); 

        setcolor(YELLOW); //hasil scalingnya
        line(koor_tr[0][0], koor_tr[0][1], koor_tr[1][0], koor_tr[1][1]); 

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



