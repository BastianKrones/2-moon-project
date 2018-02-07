#include "./initialize.h"

void initialize(long double *energy, long double *t, long double x[N][D], long double v[N][D], long double m[N])
{
    //initialide starting conditions
    for (int n = 0; n < N; n++)
    {
        m[n] = initial_masses(n);
        for (int d = 0; d < D; d++)
        {
            x[n][d] = initial_pos(n, d);
            if (calculate_velocities == 1)
            {
                v[n][d] = calculate_initial_velocities(n, d);
            }
            else
            {
                v[n][d] = initial_velocities(n, d);
            }
        }
    }
    *t = t_start;
    *energy = calculate_energy(x, v, m);
}