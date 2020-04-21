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
void Process();



int main(int argc, char *argv[]){
	
	char * ptr1;
    
   	Vi = strtod(argv[1],&ptr1);
     C  = strtod(argv[2],&ptr1);
     R  = strtod(argv[3],&ptr1);
     t_start = strtod(argv[4],&ptr1); //waktu mulai mencatat
     t_end   = strtod(argv[5],&ptr1); //waktu akhir mencatat
     t_each  = strtod(argv[6],&ptr1); //ketelitian waktu mencatat
    

	Output();
    return(0);
}


void Output(){
	double t;
    Out = fopen("Output/Data.csv", "w");
    fprintf(Out,"Waktu;Vo;I\n");
    for (t = 0; t < t_end; t += delta)
    {
        /* code */
        Process(Vo,Vi,I,C,R,dVo,temp_Vo,delta);
        if (t >= t_start)
        {
            /* code */
            fprintf(Out, "%.4lf;%.4lf;%.4lf \n", t, Vo, I);
            t_start+=t_each;
        }
    }
    printf("Hasil telah dicetak pada file Output/Data.csv\n\n");
    fclose(Out);
}

void Process(double Vo,double Vi,double I,double C,double R, double dVo, double temp_Vo,double delta){
    temp_Vo = Vo;
    I = (Vi - Vo) / R;
    dVo = (I * delta) / C;
    Vo = temp_Vo + dVo;
}

