#include "energy.h"

// Calculates total energy of body i relating to a second body j
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
        long double kin_energy = calculate_kin_energy(i, v, m);
        long double pot_energy = calculate_pot_energy(i, x, v, m);
        long double energy = 0;

        energy += kin_energy + pot_energy;

        return energy;
    }
}

// Calculates kinetic energy of one body of all used dimensions
long double calculate_kin_energy(int i, long double v[N][D], long double m[N])
{
    long double kin_energy = 0;
    for (int k = 0; k < D; k++)
    {
        kin_energy += 0.5 * m[i] * pow(v[i][k], 2);
    }

    return kin_energy;
}

// calculate the energy for each body
long double calculate_pot_energy(int i, long double x[N][D], long double v[N][D], long double m[N])
{
    long double pot_energy = 0;
    long double curr_pot_energy = 0;

    // iterate ith-body up to jth-body
    for (i; i < N; i++)
    {
        // iterating all following bodies
        // all j-bodies later than i
        for (int j = i; j < N; j++)
        {
            if (j != i)
            {
                // Calculates potential energy of each body
                curr_pot_energy = -G * m[i] * m[j] / calculate_distance(i, j, x);

                // Sums up all potentiall energies
                pot_energy += curr_pot_energy;
            }
        }
    }
    return pot_energy;
}

long double calculate_distance(int i, int j, long double x[N][D])
{
    long double distance = 0;
    for (int k = 0; k < D; k++)
    {
        distance += pow(x[i][k] - x[j][k], 2);
    }

    return pow(distance, 0.5);
}