#include "energy.h"

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

// calculate the energy for each body
long double calculate_pot_energy(long double x[N][D], long double v[N][D], long double m[N])
{
    long double pot_energy = 0;
    long double curr_pot_energy = 0;

    printf("###################\n");
    for (int i = 0; i < N; i++)
    {
        // iterating all following bodies
        // all j-bodies later than i
        for (int j = i; j < N; j++)
        {
            if (j != i)
            {
                curr_pot_energy = -G * m[i] * m[j] / calculate_distance(i, j, x);
                printf("pot_energy %d %d: %0.30Le\n", i, j, curr_pot_energy);
                // curr_pot_energy = -G * m[j] * m[i] / calculate_distance(i, j, x);
                // // curr_pot_energy = 6.67408 * pow(10, -11) * m[0] * m[2] / calculate_distance(0, 2, x);
                // printf("pot_energy %d %d: %0.30Le\n", i, j, curr_pot_energy);
                // if (i == 0 && j == 2)
                // {
                //     printf("################\n");
                //     printf("Pot energy 0 2: %.30Le\n", 6.67408 * pow(10, -11) * m[0] * m[2] / calculate_distance(0, 2, x));
                //     printf("Pot energy 0 2: %.30Le\n", G * m[0] * m[2] / calculate_distance(0, 2, x));
                //     printf("################\n");
                // }
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