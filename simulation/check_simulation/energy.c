#include "energy.h"

long double calculate_distance(int i, int j, long double x[N][D]);
long double calculate_kin_energy(int i, long double v[N][D], long double m[N]);
// long double calculate_pot_energy(long double x[N][D], long double v[N][D], long double m[N]);

long double calculate_energy(int i, int j, long double x[N][D], long double v[N][D], long double m[N])
{
    // on centered body is acting no energy
    if (i == 0)
    {
        return 0;
    }
    // there is no force acting on a body itself
    else if (i == j)
    {
        return 0;
    }
    else
    {
        calculate_distance(0, 1, x);
        long double energy = calculate_kin_energy(i, v, m);

        return energy;
    }
}

long double calculate_kin_energy(int i, long double v[N][D], long double m[N])
{
    long double kin_energy = 0;
    for (int k = 0; k < D; k++)
    {
        kin_energy += 0.5 * m[i] * pow(v[i][k], 2);
    }

    return kin_energy;
}

// calculate the energy for each step
long double calculate_pot_energy(long double x[N][D], long double v[N][D], long double m[N])
{
    // long double energy = 0;
    // for (int i = 1; 1 < N; i++)
    // {
    //     for (int j = i; j < N; j++)
    //     {
    //         if (j == i)
    //         {
    //             energy += 1 / 2 * m[k] *
    //                           (pow(v[j][0], 2) + pow(v[j][1], 2) + pow(v[j][2], 2)) -
    //                       G * m[0] * m[j] /
    //                           (pow(x[j][0], 2) + pow(x[j][1], 2) + pow(x[j][2], 2));
    //         }
    //         else
    //         {
    //             calculate_distance(i, j);
    //             energy += -G * m[j] * m[i] /
    //                       (pow(x[j][0] - x[i][0], 2) + pow(x[j][1] - x[i][1], 2) + pow(x[j][2] - x[i][2], 2));
    //         }
    //     }
    // }
    // return energy;
}

<<<<<<< HEAD
long double calculate_distance(int i, int j, double x[N][D])
=======
long double calculate_distance(int i, int j, long double x[N][D])
>>>>>>> 91bd431928abf7fae3d5c00c0eb942b622e64710
{
    long double distance = 0;
    for (int k = 0; k < D; k++)
    {
        distance += pow(x[i][k] - x[j][k], 2);
    }

    return pow(distance,0.5);
}