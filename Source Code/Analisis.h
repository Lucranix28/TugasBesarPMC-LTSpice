#include "komponen.h"

float S[20][20],A[20][20], Tableau[20][20];

void newBranch(int n_komponen, const char *ID, const char *nodeA, const char *nodeB, const float param);
int Gauss(float A[20][20]); // Source : https://www.codewithc.com/c-program-for-gauss-jordan-method/

void newBranch(int n_komponen, const char *ID, const char *nodeA, const char *nodeB, const float param)
{
    if (n_komponen == 1)
    {
        // Inisiasi Matriks

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