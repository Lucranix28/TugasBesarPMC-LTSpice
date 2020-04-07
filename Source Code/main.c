// #include "Analisis.h"
#include "komponen.h"

// Global Variabel
float w, dt;

int main(void){
    char net_name[] = "netlist/", s[MaxChar], c, temp[MaxChar], *token, node;
    const char space[2] = " ";

    int i = 0, j = 0;
    double param;
    FILE *netlist, *output;

    printf("Input nama netlist : ");
    scanf(" %s", s);

    strcat(net_name, s);
    strcat(net_name, ".txt");
    netlist = fopen(net_name, "r");

    // Input W
    fgets(temp,MaxChar, netlist);
    w = atof(temp);
    printf("w = %.3f \n", w);
    dt = 1/w;
    printf("dt = %.3f \n\n", dt);

    // Input Komponen
    while(fgets(temp,MaxChar, netlist) != NULL)
    {
        i++;
        if (temp[strlen(temp) - 1] == '\n')
        {
            temp[strlen(temp) - 1] = '\0';
        }
        
        printf("Netlist ke-%d : %s \n", i, temp);
        token = strtok(temp, " ");
        printf("\t ID Komponen \t : %s \n", token);
        token = strtok(NULL, " ");
        printf("\t Node pangkal : %s", token);
        token = strtok(NULL, " ");
        printf("\t Node ujung : %s", token);
        token = strtok(NULL, " ");
        param = atof(token);
        printf("\t Parameter : %f \n", param);
    }


    fclose(netlist);
    return (0);
}