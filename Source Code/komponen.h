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
    
    
    Componen :
    -> Independent Source :
        1. Voltage Source
        2. Current Source

    -> Dependent Source :
        1. A voltage-controlled voltage source (VCVS).
        2. A current-controlled voltage source (CCVS).
        3. A voltage-controlled current source (VCCS).
        4. A current-controlled current source (CCCS).

    
*/

struct Node
{
    // Bentukan Node
    float volt;
    struct Node *next;
};

struct Branch
{
    // Bentukan Branch
    float amp;
    int elemen_id;
    char point_a, point_b;
    struct Branch *next; 
};