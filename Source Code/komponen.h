#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Rules :
    1. amp = dq/dt = volt/R
    2. volt = dw/dq : joule/coulomb
    3. power = dw/dt = volt.amp
        power + -> absorbed
        power - -> released
        in a circuit -> stigma p = 0
    4. w = integral from t0 to t of p.dt

    Ohm's law
        v = i.R
        Short Circuit : Lim R -> 0, v = 0
        Open Circuit : Lim R -> infinite, i = 0

    Conductance : G = 1/R = i/v

    Node, Branch, Loop
        Branch = represent a single element
        Node = point of connection between two or more branches
        Loop = any closed path

        b branches, n nodes, and l independent loops
        b = l + n -1

        Series
            same Current, diff Voltage
            Req = R1 + R2 + R3 + Rn

        Parallel
            same Voltage, diff Current
            Req = Ri.R2.R3.Rn/R1+R2+R3+R4

    Kirchoff
        Current Law
            stigma n = 1 to N in = 0, in a Node
        Current Voltage
            stigma n = 1 to N Vm = 0, in a Closed Loop

    Componen :
    ->  0. Ground
    -> Independent Source :
        1. Voltage Source
        2. Current Source

    -> Dependent Source :
        3. A voltage-controlled voltage source (VCVS).
        4. A current-controlled voltage source (CCVS).
        5. A voltage-controlled current source (VCCS).
        6. A current-controlled current source (CCCS).

    ->  7. Resistor
    ->  8. Kapasitor
    ->  9. Induktor

    
*/
#define pi 3.14159265359

struct Node
{
    // Bentukan Node
    float volt;
    int n_cabang;
    struct Node *next;
};

struct Branch
{
    // Bentukan Branch
    float amp;
    char *elemen_id;
    int elemen_type;
    char *a_id, *b_id; 
    struct Branch *next; 
};

void searchNode(char *id, struct Node *a);

void Resistor(struct Branch *target, struct Node *head, float Res){
    int a_id, b_id;
    struct Node *b, *a;

    a_id = target->a_id;

    searchNode(a_id, a);
    searchNode(b_id, b);
    target->amp = (b->volt - a->volt);
}

