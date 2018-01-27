#include "external_force.h"

// total force acting on the i-th body at the d-th dimention
double fExternal(int i, int d, double x[N][D], double m[N])
{
    double force = 0;
    for (int j = 0; j < N ; j++)
    {
        force += fInternal(i, j, d, x, m);
    }
    printf("force = %e\n", force);

    return force;
}