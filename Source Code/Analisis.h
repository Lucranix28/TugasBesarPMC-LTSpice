#include "komponen.h"

void newBranch(const char *ID, const char *nodeA, const char *nodeB, const float param);

void newBranch(const char *ID, const char *nodeA, const char *nodeB, const float param)
{
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

