#include "komponen.h"

#define Mat_lim 20

typedef struct Volt
{
    /* data */
    char *Node_id;
    float V, dV;
} volt;

typedef struct Amp
{
    /* data */
    char *Branch_id;
    float I, dI;
} amp;

volt default_v = {"", 0, 0};
amp default_i = {"", 0, 0};

float Ki[Mat_lim][Mat_lim],Kv[Mat_lim][Mat_lim], Tableau[Mat_lim][Mat_lim], S[Mat_lim];
int A[Mat_lim][Mat_lim], Transpose_Min_A[Mat_lim][Mat_lim];
char *ground;
amp I[Mat_lim];
volt V[Mat_lim], E[Mat_lim];

void newBranch(int n_komponen, const char *ID, const char *nodeA, const char *nodeB, const float param);
int Gauss(float A[20][20]); // Source : https://www.codewithc.com/c-program-for-gauss-jordan-method/
void resetMat();
int Accepted(const char *nodeA, const char *nodeB);

int Accepted(const char *nodeA, const char *nodeB)
{
    int val = 1;

    // Apakkah node sama
    if (strcmp(nodeA,nodeB))
    {
        /* code */
    }
}
void newBranch(int n_komponen, const char *ID, const char *nodeA, const char *nodeB, const float param)
{
    int i = 0, j = 0, n_id;

    n_id = n_komponen-1;

    if (n_id == 0)
    {
        // Inisiasi Matriks
        resetMat();
        
        
        strcpy(ground, nodeA);
        strcpy(E[0].Node_id ,nodeA); // Set As Ground
        E[0].V = 0;
        
        strcpy(E[1].Node_id,nodeB); // Next Node
        
        strcpy(V[0].Node_id,ID);

        Transpose_Min_A[0][0] = -1; // V = Ea - Eg
        Transpose_Min_A[0][1] = 1;

        printf("Komponen berikut menjadi komponen awal dengan %s sebagai Ground", nodeA);
    }
    else
    {
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

void resetMat(){
    for (int i = 0; i < Mat_lim; i++)
    {
        for (int j = 0; j < Mat_lim; j++)
        {
            Ki[i][j] = 0;
            Kv[i][j] = 0;
            A[i][j] = 0;
            Transpose_Min_A[i][j] = 0;
            Tableau[i][j] = 0;
        }
        S[i] = 0;
        I[i] = default_i;
        V[i] = default_v;
        E[i] = default_v;
    }
    strcpy(ground,"");
}