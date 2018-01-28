#include "external_force.h"

// total force acting on the i-th body at the d-th dimention
long double fExternal(int i, int d, long double x[N][D], long double m[N])
{
    long double force = 0;
    for (int j = 0; j < N; j++)
    {
        force += fInternal(i, j, d, x, m);
    }

    return force;
}