#include "internal_force.h"

// force acting on the i-th body from the j-th body
double fInternal(int i, int j, int d, double x[N][D], double m[N])
{
    if (i == 0)
    // on centered body is acting no force
    {
        return 0;
    }
    else if (i == j)
    // there is no force acting on a body itself
    {
        return 0;
    }
    else
    {
        double rsqr = 0;
        for (int k = 0 ; k < D ; k++)
        {
            rsqr += pow( x[i][k] - x[j][k], 2);
        }

        double force = -1 * G * m[i] * m[j] / pow(rsqr, 3.0/2.0) * (x[i][d] - x[j][d]);

        return force;

    }
}