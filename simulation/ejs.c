// The simulation main program

#include <stdio.h>
#include <stdlib.h>

// #include "Runge_Kutta_4.h"
#include "Runge_Kutta_4.h"


int main(void)
{
    //define everything
    double energy[S];
    double x[N][D][S], v[N][D][S], a[N][D][S], t[S];
    double m[N];

    //initialize starting conditions
    t[0] = t_0;
    for (int b = 0; b < N; b++)
    {
        m[b] = initial_masses(b);
        for (int z = 0; z < D; z++)
        {
            x[b][z][0] = initial_pos(b, z);
            v[b][z][0] = initial_velocities(b, z);
        }
    }

    energy[0] = calculate_energy(x, v, m, 0);


    //calculate every f***ing step
    int L = 1; //stepcounter
    while (L < S)
    {   
        printf("%e", L/S);
        L += 1;
        Next(h(), L, &t, &x, &v, m);
        energy[L + 1] = calculate_energy(x, v, m, L);
    }

    return 0; //this ... is .... SPARTAAAAA!!!!!
}
