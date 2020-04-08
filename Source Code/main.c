#include "Analisis.h"

// Global Variabel -> default
float w = 50, dt = 0.02;
int n_komponen = 0;

int main(void)
{
    char net_name[] = "netlist/", dir_out[] = "output/", s[MaxChar], c, temp[MaxChar], *token, *tipe, *nodeA, *nodeB;
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
    printf("w = %.2f \n", w);
    dt = 1/w;
    printf("dt = %.4f \n\n", dt);

    // Input Komponen
    while(fgets(temp,MaxChar, netlist) != NULL)
    {
        n_komponen++;
        if (temp[strlen(temp) - 1] == '\n')
        {
            temp[strlen(temp) - 1] = '\0';
        }

        printf("Netlist ke-%d : %s \n", n_komponen, temp);
        token = strtok(temp, " ");
        tipe = token;

        token = strtok(NULL, " ");
        nodeA = token;

        token = strtok(NULL, " ");
        nodeB = token;
        
        token = strtok(NULL, " ");
        param = atof(token);
        
        printf("\t ID Komponen : %s \n", tipe);
        printf("\t Node pangkal : %s", nodeA);
        printf("\t Node ujung : %s", nodeB);
        printf("\t Parameter : %f \n", param);
        
        newBranch(n_komponen, tipe, nodeA, nodeB, param); // Mengatur Matriks S dam A
    }

    printf("Input nama output : ");
    scanf(" %s", s);

    strcat(dir_out, s);
    strcat(dir_out, ".txt");
    output = fopen(dir_out, "w");

    

    fclose(output);
    fclose(netlist);
    return (0);
}