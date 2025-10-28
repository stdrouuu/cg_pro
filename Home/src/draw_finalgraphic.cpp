// 412024022 - Brandon Jeremiah Sutedja

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int x_mid, y_mid;

void drawBresenLineBrandon(int x_awal_bresenvert, int y_awal_bresenvert, int x_akhir_bresenvert, int y_akhir_bresenvert, int color) 
{
    int delta_x, delta_y, p;
    int x_bresenvert, y_bresenvert, i;
    int x_temp, y_temp;

    delta_x = x_akhir_bresenvert - x_awal_bresenvert;
    delta_y= y_akhir_bresenvert - y_awal_bresenvert;

    if (delta_x >= 0) x_temp = 1; 
    else x_temp = -1;

    if (delta_y >= 0) y_temp = 1; 
    else y_temp = -1;

    x_bresenvert = x_awal_bresenvert;
    y_bresenvert = y_awal_bresenvert;
    putpixel(x_bresenvert, y_bresenvert, color);
    i = 0;

    if (abs(delta_y) < abs(delta_x))
    {
        p = (2 * abs(delta_y)) - abs(delta_x);
        do {
            if (p < 0) {
                x_bresenvert = x_bresenvert + x_temp;
                p = p + 2 * abs(delta_y);
            } else {
                x_bresenvert = x_bresenvert + x_temp;
                y_bresenvert = y_bresenvert + y_temp;
                p = p + 2 * abs(delta_y) - 2 * abs(delta_x);
            }
            putpixel(x_bresenvert, y_bresenvert, color);
            i++;
        } while (i <= abs(delta_x));
    }
    else
    {
        p = (2 * abs(delta_x)) - abs(delta_y);
        do {
            if (p < 0) {
                y_bresenvert = y_bresenvert + y_temp;
                p = p + 2 * abs(delta_x);
            } else {
                x_bresenvert = x_bresenvert + x_temp;
                y_bresenvert = y_bresenvert + y_temp;
                p = p + 2 * abs(delta_x) - 2 * abs(delta_y);
            }
            putpixel(x_bresenvert, y_bresenvert, color);
            i++;
        } while (i <= abs(delta_y));
    }
}


void boundaryFill(int koordinat_x, int koordinat_y, int fore_clor, int back_clor)
{
    if (getpixel(koordinat_x, koordinat_y) != fore_clor && getpixel(koordinat_x, koordinat_y) != back_clor)
    {
        putpixel(koordinat_x, koordinat_y, fore_clor);
        boundaryFill(koordinat_x+1, koordinat_y, fore_clor, back_clor); //kanan
        boundaryFill(koordinat_x-1, koordinat_y, fore_clor, back_clor); //kiri
        boundaryFill(koordinat_x, koordinat_y+1, fore_clor, back_clor); //bawah
        boundaryFill(koordinat_x, koordinat_y-1, fore_clor, back_clor); //atas
    }
}


void drawSquareWarnaMagenta(int x_kiri, int y_atas, int x_kanan, int y_bawah, int color)
{
    drawBresenLineBrandon(x_kiri, y_atas, x_kanan, y_atas, color); 
    drawBresenLineBrandon(x_kiri, y_atas, x_kiri, y_bawah, color); 
    drawBresenLineBrandon(x_kanan, y_atas, x_kanan, y_bawah, color); 
    drawBresenLineBrandon(x_kiri, y_bawah, x_kanan, y_bawah, color);  
}


float degressToRadians(float sudut)
{
    return sudut * M_PI / 180;
}
void drawTriangleWarnaBlack(int x_tengah_segi3, int y_tengah_segi3, int sudut, int panjang_sisi, int color)
{
    int x_kiri_segi3 = panjang_sisi * cos(degressToRadians(sudut-30)) + x_tengah_segi3;
    int y_kiri_segi3 = panjang_sisi * sin(degressToRadians(sudut-30)) + y_tengah_segi3;

    int x_kanan_segi3 = panjang_sisi * cos(degressToRadians(sudut+30)) + x_tengah_segi3;
    int y_kanan_segi3 = panjang_sisi * sin(degressToRadians(sudut+30)) + y_tengah_segi3;

    drawBresenLineBrandon(x_tengah_segi3, y_tengah_segi3, x_kiri_segi3, y_kiri_segi3, color);
    drawBresenLineBrandon(x_kiri_segi3, y_kiri_segi3, x_kanan_segi3, y_kanan_segi3, color);
    drawBresenLineBrandon(x_tengah_segi3, y_tengah_segi3, x_kanan_segi3, y_kanan_segi3, color);
}


void drawCircleWarnaLightBlue(int x_pusat_o, int y_pusat_o, int jari2_o, float theta_awal, float theta_akhir, int color)
{
    float theta_inc = 1.0 / (float)jari2_o;
    float theta, x_o, y_o;
    theta_awal = degressToRadians(theta_awal);
    theta_akhir = degressToRadians(theta_akhir);
    if (theta_akhir < theta_awal) {
        theta_akhir = 2 * M_PI + theta_akhir;
    }
    theta = theta_awal;
    do 
    {
        x_o = (float)jari2_o * cos(theta);
        y_o = (float)jari2_o * sin(theta);
        putpixel(round(x_pusat_o+x_o), round(y_pusat_o+y_o), color);
        theta = theta + theta_inc;
    } while (theta <= theta_akhir);
}


void eclipsePlotpoint(int x_pusat_ecl, int y_pusat_ecl, int x_ecl, int y_ecl, int color)
{
    putpixel(x_pusat_ecl+x_ecl, y_pusat_ecl+y_ecl, color);
    putpixel(x_pusat_ecl-x_ecl, y_pusat_ecl+y_ecl, color);
    putpixel(x_pusat_ecl+x_ecl, y_pusat_ecl-y_ecl, color);
    putpixel(x_pusat_ecl-x_ecl, y_pusat_ecl-y_ecl, color);
}
void drawMidpointEclipseWarnaRed(int x_pusat_ecl, int y_pusat_ecl, int jari2_x_ecl, int jari2_y_ecl, int color)
{
    int kuadrat_x_ecl = jari2_x_ecl * jari2_x_ecl;
    int kuadrat_y_ecl = jari2_y_ecl * jari2_y_ecl;

    //region 1
    int x_r1 = 0;
    int y_r1 = jari2_y_ecl; 
    int p_r1 = kuadrat_y_ecl - (kuadrat_x_ecl * jari2_y_ecl) + (kuadrat_x_ecl / 4); 

    eclipsePlotpoint(x_pusat_ecl, y_pusat_ecl, x_r1, y_r1, color);
    do
    {
        if (p_r1 < 0)
        {
            x_r1 = x_r1 + 1;
            p_r1 = p_r1 + 2 * kuadrat_y_ecl * x_r1 + kuadrat_y_ecl;
        }
        else
        {
            x_r1 = x_r1 + 1;
            y_r1 = y_r1 - 1;
            p_r1 = p_r1 + 2 * kuadrat_y_ecl * x_r1 - 2 * kuadrat_x_ecl * y_r1 + kuadrat_y_ecl;
        }
        eclipsePlotpoint(x_pusat_ecl, y_pusat_ecl, x_r1, y_r1, color);
    } while (2 * kuadrat_y_ecl * x_r1 < 2 * kuadrat_x_ecl * y_r1);

    //region 2
    int x_r2 = x_r1;
    int y_r2 = y_r1;
    int p_region_2 = (int)(kuadrat_y_ecl * (x_r2 + 0.5) * (x_r2 + 0.5) + kuadrat_x_ecl * (y_r2 - 1) * (y_r2 - 1) - kuadrat_x_ecl * kuadrat_y_ecl);
    do
    {
        if (p_region_2 > 0)5
        {
            y_r2 = y_r2 - 1;
            p_region_2 = p_region_2 - 2 * kuadrat_x_ecl * y_r2 + kuadrat_x_ecl;
        }
        else
        {
            x_r2 = x_r2 + 1;
            y_r2 = y_r2 - 1;
            p_region_2 = p_region_2 + 2 * kuadrat_y_ecl * x_r2 - 2 * kuadrat_x_ecl * y_r2 + kuadrat_x_ecl;
        }
        eclipsePlotpoint(x_pusat_ecl, y_pusat_ecl, x_r2, y_r2, color);
    } while (y_r2 > 0);
}


int main()
{
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();

    x_mid = getmaxx() / 2;
    y_mid = getmaxy() / 2;

    drawSquareWarnaMagenta(x_mid - 300/2, y_mid - 300/2, x_mid + 300/2, y_mid + 300/2, YELLOW); //(batas kiri square, batas atas, batas kanan, batas bawah, warna garis);
    boundaryFill(x_mid, y_mid, MAGENTA, YELLOW);
    //sintaks diatas ini utk isi bagian dalam square dgn garis YELLOW dan warnafill MAGENTA.

    drawTriangleWarnaBlack(x_mid, y_mid - 112, 90, 259, LIGHTGREEN); //isi parameternya ada (posisi tengah sb x triangle, posisi sb y triangle agak keatas, sudut, panjang sisi, warna garis);
    boundaryFill(x_mid, y_mid + 37, BLACK, LIGHTGREEN); //ini utk isi bagian dalam triangle dgn garis LIGHTGREEN dan warnafill BLACK.

    drawCircleWarnaLightBlue(x_mid,y_mid + 37, 75, 0, 360, WHITE); //isi paramnneternya ada (posisi tengah sb x circle, posisi sb y circle agak kebawah, jari2, sudutawal, sudutakhir, warna garis);
    boundaryFill(x_mid, y_mid + 37, LIGHTBLUE, WHITE);//ini utk isi bagian dalam circle dgn garis WHITE dan warnafill LIGHTBLUE.

    drawMidpointEclipseWarnaRed(x_mid, y_mid + 37, 75, 20, LIGHTCYAN); //isi parameternya ada(posisi tengah sb x ecl, posisi tengah sb y ecl, jari2 sb x, jari2 sb y, warna garis);
    boundaryFill(x_mid, y_mid + 37, RED, LIGHTCYAN); //ini utk isi bagian dalam eclpise dgn garis LIGHTCYAN dan warnafill RED.

    //ini utk gambar gamabr line vertikal di tengah eclipsenya
    drawBresenLineBrandon(x_mid, (y_mid + 37) - 20, x_mid, (y_mid + 37) + 20, WHITE); //(x tengah, y atas, x bawah, y bawah, warna garis);

    getch();
    closegraph();
}

// 412024022 - Brandon Jeremiah Sutedja