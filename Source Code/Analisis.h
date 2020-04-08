#include "komponen.h"

#define Mat_lim 20

float S[Mat_lim],A[Mat_lim][Mat_lim], Tableau[Mat_lim][Mat_lim];
char *Var_V[Mat_lim], *Var_I[Mat_lim], *Var_e[Mat_lim];

void newBranch(int n_komponen, const char *ID, const char *nodeA, const char *nodeB, const float param);
int Gauss(float A[20][20]); // Source : https://www.codewithc.com/c-program-for-gauss-jordan-method/

void newBranch(int n_komponen, const char *ID, const char *nodeA, const char *nodeB, const float param)
{
    int i = 0, j = 0;
    if (n_komponen == 1)
    {
        // Inisiasi Matriks
        for (i = 0; i < Mat_lim; i++)
        {
            for (j = 0; j < Mat_lim; j++)
            {
                A[i][j] = 0;
                Tableau[i][j] = 0;
            }
            *Var_e[i] = "";
            *Var_V[i] = "";
            *Var_I[i] = "";
            S[i] = 0;
        }
    }
    
    char head;

    head = ID[0];
    switch (head)
    {
    case 'R':
        /* code */
        Resistor();
        break;
    case 'V':
        /* code */
        Voltage();
        break;
    case 'C':
        /* code */
        Capacitor();
        break;
    case 'I':
        /* code */
        Current();
        break;
    case 'L':
        /* code */
        Inductor();
        break;
    default:
        printf("Unknown");
        break;
    };
}

int Gauss(float A[20][20])
{
    int i, j, k, n;
    float A[20][20], c, x[10];
    printf("\nEnter the size of matrix: ");
    scanf("%d", &n);
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= (n + 1); j++)
        {
            printf(" A[%d][%d]:", i, j);
            scanf("%f", &A[i][j]);
        }
    }
    /* Now finding the elements of diagonal matrix */
    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (i != j)
            {
                c = A[i][j] / A[j][j];
                for (k = 1; k <= n + 1; k++)
                {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }
    printf("\nThe solution is:\n");
    for (i = 1; i <= n; i++)
    {
        x[i] = A[i][n + 1] / A[i][i];
        printf("\n x%d=%f\n", i, x[i]);
    }
    return (0);
}