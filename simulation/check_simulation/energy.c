#include "energy.h"

// calculates the kintetic energy of the i-th body
long double calculate_kin_energy(int i, long double v[N][D], long double m[N])
{
    long double kin_energy = 0;

    for (int k = 0; k < D; k++)
    {
        kin_energy += 0.5 * m[i] * pow(v[i][k], 2);
    }

    return kin_energy;
}

// calculate the potential energy between the i-th and the j-th body
long double calculate_potential_energy(int i, int j, long double x[N][D], long double m[N])
{
    return -G * m[i] * m[j] / calculate_distance(i, j, x);
}

// calculates the distance between the i-th and the j-th body
long double calculate_distance(int i, int j, long double x[N][D])
{
    long double distance = 0;
    for (int k = 0; k < D; k++)
    {
        distance += pow(x[i][k] - x[j][k], 2);
    }

    return pow(distance, 0.5);
}

// calculate the total energy
long double calculate_energy(long double x[N][D], long double v[N][D], long double m[N])
{
    long double energy = 0;

    for (i; i < N; i++)
    {
        energy += calculate_kin_energy(i, v, m);

        // this choice of loop prevents dubbeld calculation for the potential energy ex.
        // 1 -> 2; 2 -> 1
        // drawing this by hand makes is clear
        for (int j = i; j < N; j++)
        {
            if (j != i)
            {
                energy += calculate_potential_energy(i, j, x, m);
            }
        }
    }
    return energy;
}