/*  
*   Quiz 4 : 11/02-2020
*   Menghasilkan file berisi waktu dan tegangan C untuk kemudian di Graphign dengan External Excel
*   Vi = 5V, R = 10k, C = 1uF
*   Step Response, Vo,t
*/

#include <stdio.h>

double Vi;
double delta = 0.000001;
double V_accurate = 0.005;

double Vo = 0;      //initial voltage
double R;           //resistance
double C;           //Kapasitor
double temp_Vo = 0;
double dVo = 0;
double I;
double VPrint = 0;
double t_start = 0, t_end = 100, t_each = 0.001;
FILE *fp;

void Input();
void Output();
void Input_Set();

int main(void){
    Input_Set();
    Input();
    Output();
    return(0);
}

void Input(){
    printf("Masukkan Tegangan input(Vi) :");
    scanf("%lf",&Vi);
    printf("\n");
    printf("Masukkan Nilai Resistansi(ohm) :");
    scanf("%lf",&R);
    printf("\n");
    printf("Masukkan Nilai Kapasitor(Farad) :");
    scanf("%lf",&C);
    printf("\n");
}

void Input_set(){
    printf("Masukkan Waktu Mulai Mencatat(ms) :");
    scanf("%lf", &t_start);
    printf("\n");
    printf("Masukkan Waktu Akhir Mencatat(ms) :");
    scanf("%lf", &t_end);
    printf("\n");
    printf("Masukkan ketelitian waktu mencatat(ms) :");
    scanf("%lf", &t_each);
    printf("\n");
}

void Output()
{
    fp = fopen("test.txt", "w");
    for (double t = 0; t < t_end; t += delta)
    {
        /* code */
        I = (Vi - Vo) / R;
        dVo = (I * delta) / C;
        Vo = temp_Vo + dVo;
        temp_Vo = Vo;

        if (t >= t_start)
        {
            /* code */
            fprintf(fp, "%.4lf;%.3lf;.3lf \n", t, Vo, I);
            VPrint += V_accurate;
            Output();
        }
    }
    printf("hasil telah dicetak pada file test.txt");
    fclose(fp);
}
