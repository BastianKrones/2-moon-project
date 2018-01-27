#include "initialize.h"

void initialize(double energy, double t, double x[N][D], double v[N][D], double m[N])
{
    //initialize starting conditions
    t = t_0;
    for (int b = 0; b < N; b++)
    {
        m[b] = initial_masses(b);
        for (int z = 0; z < D; z++)
        {
            x[b][z] = initial_pos(b, z);
            v[b][z] = initial_velocities(b, z);
        }
    }
}