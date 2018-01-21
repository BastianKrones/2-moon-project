// The simulation main program

#include <stdio.h>
#include <stdlib.h>

// #include "Runge_Kutta_4.h"
#include "Runge_Kutta_4.h"


int main(void)
{
    double energy[S];
    double x[N][D][S], v[N][D][S], a[N][D][S], t[S];
    double m[N];

    // initialize the starting conditionis
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

    for (int b = 0; b < N; b++)
    {
        for (int z = 0; z < D; z++)
        {
            energy[0] = calculate_energy(x, v, m, 0);
            a[b][z][0] = calculate_acceleration(b, z, 0, x, m);
        }
    }

    int L = 1; //stepcounter
    while (L < S)
    {
        L += 1;
        for (int j = 1; j < N; j++)
        {
            for (int k = 1; k < D; k++)
            {
                Next(h(), L, &t, &x, &v, m);
            }
        }
    }

    return 0;
}
