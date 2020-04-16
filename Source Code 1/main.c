/*  
*   STEP RESPONSE ANALYSIS
*/

#include <stdio.h>
#include <stdlib.h>

// Time Processing Setting
double delta = 0.0001;
double t_start = 0, t_end = 10, t_each = 0.01;

// Component Value
double Vi = 1;  // VSource Dc
double R = 1;   // Resistance (Ohm)
double C = 1;   // Capasitor (F)
 
 // Component PRocessing Setting
double Vo = 0;      // Initial voltage
double temp_Vo = 0; // Voltage Before
double dVo = 0;     // Voltage Change
double I = 0;       // Current Passing Circuit

// Storing Data
FILE *Out;

//Menu Setting
int state = 0;
/*
0. Exit
1. Set Time Output
2. Set Component
3. Show Setting
4. Draw Circuit
5. Process to Output
*/

// Function initial
void Output();
void Input_time();
void Input_com();
int Validate_com(double Input);
int Validate_time();
void Process();
void Menu();
void Print_menu();
void Print_set();
void Draw_Circuit();

int main(void){
    do
    {
        /* code */
    Menu();
    } while (state != 0);

    printf("Program Berakhir");
    return(0);
}

void Menu() {
    Print_menu();
    printf("Input pilihan menu : ");
    scanf(" %d", &state);

    switch (state)
    {
    case 0:
        break;
    case 1:
        Input_time();
        break;
    case 2:
        Input_com();
        break;
    case 3:
        Print_set();
        break;
    case 4:
        Draw_Circuit();
        break;
    case 5:
        Output();
        break;
    default:
        printf("--Input Menu Keliru--\n");
        Menu();
        break;
    }
}

void Print_menu(){
    printf("\n Menu :\n");
    printf("\t1. Set Time Output \n");
    printf("\t2. Set Component \n");
    printf("\t3. Show Setting \n");
    printf("\t4. Draw Circuit \n");
    printf("\t5. Process & Output \n");
    printf("\t0. Exit \n");

}

int Validate_com(double Input){
    if (Input > 0)
    {
        return 1;
    }
    printf("--Input Komponen Keliru--\n");
    return 0;
}

int Validate_time(){
    if(t_start >=t_end)
    {
        printf("\n--Input Waktu Keliru--\n");
        return 0;
    }
    if (t_each >= (t_start - t_end))
    {
        printf("\n--Input Ketelitian Keliru--\n");
        return 0;
    }
    return 1;

}
void Input_com(){
    
    printf("\nMasukkan Tegangan Supply (Vi) : ");
    scanf("%lf", &Vi);

    printf("Masukkan Tegangan awal kapasitor (Vo) : ");
    scanf("%lf", &Vo);

    do
    {
        /* code */
        printf("Masukkan Nilai Resistansi(ohm) : ");
        scanf("%lf", &R);
    } while (!Validate_com(R));

    do
    {
        /* code */
        printf("Masukkan Nilai Kapasitor(Farad) : ");
        scanf("%lf", &C);
    } while (!Validate_com(C));

    printf("\n Input Nilai Komponen Berhasil \n");
}

void Input_time(){
    do
    {
        /* code */
        printf("Masukkan Waktu Mulai Mencatat(ms) :");
        scanf("%lf", &t_start);
        printf("Masukkan Waktu Akhir Mencatat(ms) :");
        scanf("%lf", &t_end);
        printf("Masukkan ketelitian waktu mencatat(ms) :");
        scanf("%lf", &t_each);
    } while (!Validate_time());

    printf("\n Input Nilai Output Waktu Berhasil \n");
}

void Output()
{
    Out = fopen("Output/Data.txt", "w");
    for (double t = 0; t < t_end; t += delta)
    {
        /* code */
        Process();
        if (t >= t_start)
        {
            /* code */
            fprintf(Out, "%.4lf;%.4lf;%.4lf \n", t, Vo, I);
            t_start+=t_each;
        }
    }
    printf("Hasil telah dicetak pada file Output/Data.txt\n\n");
    fclose(Out);
}

void Process(){
    temp_Vo = Vo;
    I = (Vi - Vo) / R;
    dVo = (I * delta) / C;
    Vo = temp_Vo + dVo;
}

void Draw_Circuit()
{
    printf("\n(Ground) - VSupply - (%lf V) - RES/%lf OHM - (%lf V) - CAP/%lf F - (Ground)\n", Vi, R, Vo, C);
}

void Print_set(){
    printf("\nSetting Waktu :");
    printf("\n\t Waktu Mulai\t\t\t:\t%lf s", t_start);
    printf("\n\t Waktu Selesai\t\t\t:\t%lf s", t_end);
    printf("\n\t Increment waktu mencatat\t:\t%lf s", t_each);
    printf("\n\t Delta T ketelitian \t\t:\t%lf s", delta);

    printf("\n");

    printf("\nSetting Component :");
    printf("\n\t Tegangan Supply\t\t:\t%lf V", Vi);
    printf("\n\t Resistansi\t\t\t:\t%lf OHM", R);
    printf("\n\t Kapasitansi\t\t\t:\t%lf F", C);
    printf("\n\t Tegangan Awal Kapasitor\t:\t%lf V", Vo);

    printf("\n");
}