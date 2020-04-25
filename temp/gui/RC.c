/* EL2008 Pemecahan Masalah dengan C
*Nama/NIM    : Balkan Khilmi/13218057
*Nama File   : main.c
*Deskripsi   : Mencari nilai tegangan kapasitor pada rangkaian RC
*/


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define T_S 0.00001
#include <stdlib.h>


main(int argc, char *argv[]){
FILE * fptr;
fptr = fopen("out.csv","w");
	double resistor, kapasitor, Vs;
    double delV = 0, Vc = 0;
    int TimeMAX;					
	int i=0;				
	char *ptr1;
	
   	Vs = strtod(argv[1],&ptr1);
    kapasitor  = strtod(argv[2],&ptr1);
    resistor  = strtod(argv[3],&ptr1);
    TimeMAX  = atoi(argv[4]);
    
    printf("%lf\n",Vs);
	printf("%lf\n",kapasitor);
	printf("%lf\n",resistor);
	printf("%d\n",TimeMAX);
	
double kapmikro = kapasitor/1000000;
double curr = Vs/resistor;
int time = TimeMAX * 100;				// current awal;	

fprintf(fptr,"Waktu,Vc(V)\n");

    while(i < time){

        delV = curr*T_S/kapmikro;				// mencari nilai perubahan V
        Vc += delV;								//ditambahkan
        curr = (Vs - Vc)/ resistor;				//current yang digunakan pada iterasi selanjutnya
        
        fprintf(fptr,"%f,%f\n", i*T_S,Vc);		//output pada file out
        i++;
    }
    
printf("\n");


i=0;
		
    while(i < time){

        delV = curr*T_S/kapmikro;		 	// mencari nilai perubahan V
        Vc += delV;							//ditambahkan
        curr = (Vs - Vc)/ resistor;			//current yang digunakan pada iterasi selanjutnya
        
        i++;
    }		
	
fclose(fptr);

printf("File sudah masuk\n");

return 0;
    
}
