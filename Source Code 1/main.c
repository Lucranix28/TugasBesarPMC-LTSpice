/*  
*   Quiz 4 : 11/02-2020
*   Menghasilkan file berisi waktu dan tegangan C untuk kemudian di Graphign dengan External Excel
*   Vi = 5V, R = 10k, C = 1uF
*   Step Response, Vo,t
*/

#include <stdio.h>

double Vi = 5;
double delta = 0.000001;
double V_accurate = 0.005;

double Vo = 0;       //initial voltage
double R = 10000;    //resistance
double C = 0.000001; //Kapasitor
double temp_Vo = 0;
double dVo = 0;
double I;
double VPrint = 0;

void Input();
void Output();

int main(void){

    FILE *fp;
    fp = fopen("test.txt", "w");

    for (double t = 0; (Vo + 0.001) < Vi; t += delta)
    {
        /* code */
        I = (Vi - Vo)/R;
        dVo = (I * delta) / C;
        Vo = temp_Vo + dVo;
        temp_Vo = Vo;
        
        if (Vo >= VPrint)
        {
            /* code */
            VPrint += V_accurate;
            fprintf(fp,"%.4lf;%.3lf \n", t, Vo);
        }
    }

    fclose(fp);
    return(0);
}

void Input(){

}

void Output(){

}