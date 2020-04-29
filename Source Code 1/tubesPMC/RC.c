/* Tugas Besar_ Code 1
*Nama/NIM    : Balkan Khilmi/13218057, Andy Lucky/13218058
*Nama File   : RC.c
*Deskripsi   : Mencari nilai tegangan kapasitor pada rangkaian RC dari input Tkinter
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
    FILE *fptr;
    double T_S = 0.00001;
    double resistor, kap_mikro, Vs, kap, curr, TimeMAX;
    double delV, Vc;
    int TimeMAX_mil;
    int time_system;
    char *ptr1;

    fptr = fopen("out.csv", "w+");

    // Mengkonversi Input dari Tkinter
    Vs = strtod(argv[1], &ptr1);
    kap_mikro = strtod(argv[2], &ptr1);
    resistor = strtod(argv[3], &ptr1);
    Vc = strtod(argv[4], &ptr1);
    TimeMAX_mil = atoi(argv[5]);

    // // TEST UNIT : Menerima input dari Tkinter
    // printf("%lf\n", Vs);
    // printf("%lf\n", kap_mikro);
    // printf("%lf\n", resistor);
    // printf("%d\n", TimeMAX_mil);

    // Mengubah ke nilai satuan
    kap = kap_mikro / 1000000; // mengubah input menjadi mikro
    TimeMAX = TimeMAX_mil / (1000 * T_S) ; // dari ms diubah menjadi s dan dibagi per T_S
    curr = (Vs - Vc) / resistor; // Inisiasi nilai arus
    delV = 0;

    fprintf(fptr, "Waktu,Vc(V)\n");

    printf("\nAnalisis Dimulai\n");

    time_system = 0;
    while (time_system < TimeMAX)
    {

        delV = curr * T_S / kap; // mencari nilai perubahan V
        Vc += delV;                   // mengubah nilai tegangan kapasitor akibat delta V
        curr = (Vs - Vc) / resistor;  //current yang digunakan pada iterasi selanjutnya

        fprintf(fptr, "%f,%f\n", time_system * T_S, Vc); //output pada file out
        time_system++;
    }
    fclose(fptr);

    printf("\nAnalisis Selesai\n");

    return 0;
}
