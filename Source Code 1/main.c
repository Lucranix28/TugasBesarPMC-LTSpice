/*  
*   Quiz 4 : 11/02-2020
*   Menghasilkan file berisi waktu dan tegangan C untuk kemudian di Graphign dengan External Excel
*   Vi = 5V, R = 10k, C = 1uF
*   Step Response, Vo,t
*/

#include <stdio.h>
// Time Processing Setting
double delta = 0.001;
double t_start = 0, t_end = 100, t_each = 0.001;

// Component Value
double Vi = 0;  // VSource Dc
double R = 0;   // Resistance (Ohm)
double C = 0;   // Capasitor (F)
 
 // Component PRocessing Setting
double Vo = 0;      // Initial voltage
double temp_Vo = 0; // Voltage Before
double dVo = 0;     // Voltage Change
double I = 0;       // Current Passing Circuit
double VPrint = 0;

// Storing Data
FILE *Out;

// Function initial
void Input();
void Output();
void Input_Set();
int Validate_com(double Input);
int Validate_time();
void Process();

int main(void){
    Input_Set();
    Input();
    Output();
    return(0);
}

int Validate_com(double Input){
    if (Input > 0)
    {
        return 1;
    }
    printf("--Input Keliru--\n");
    return 0;
}

int Validate_time(){
    if(t_start >=t_end)
    {
        printf("\n--Input Keliru--\n");
        return 0;
    }
    if (t_each >= (t_start - t_end))
    {
        printf("\n--Input Keliru--\n");
        return 0;
    }

}
void Input(){
    
    printf("\nMasukkan Tegangan input (Vi) :");
    scanf("%lf", &Vi);

    printf("\nMasukkan Tegangan awal kapasitor (Vo) :");
    scanf("%lf", &Vo);

    do
    {
        /* code */
        printf("\nMasukkan Nilai Resistansi(ohm) :");
        scanf("%lf", &R);
    } while (Validate_com(R));

    do
    {
        /* code */
        printf("\nMasukkan Nilai Kapasitor(Farad) :");
        scanf("%lf", &C);
    } while (Validate_com(C));

    printf("\n Input Nilai Komponen Berhasil \n");
}

void Input_set(){
    do
    {
        /* code */
        printf("Masukkan Waktu Mulai Mencatat(ms) :");
        scanf("%lf", &t_start);
        printf("\n");
        printf("Masukkan Waktu Akhir Mencatat(ms) :");
        scanf("%lf", &t_end);
        printf("\n");
        printf("Masukkan ketelitian waktu mencatat(ms) :");
        scanf("%lf", &t_each);
        printf("\n");
    } while (Validate_time());

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
            printf(Output, "%.4lf;%.3lf;%.3lf \n", t, Vo, I);
            t_start+=t_each;
        }
    }
    printf("hasil telah dicetak pada file test.txt");
    fclose(Output);
}

void Process(){
    I = (Vi - Vo) / R;
    dVo = (I * delta) / C;
    Vo = temp_Vo + dVo;
    temp_Vo = Vo;
}

void Draw_Circuit()
{

    printf("(Ground) - VSupply - (Vi) - RES/%.4lf OHM - (V) - CAP/%.4lf F - (Ground)", R, C);
}