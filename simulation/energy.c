#include "energy.h"

double calculate_kin_energy(int i, double v[N][D], double m[N]);

double calculate_energy(int i, int j, double x[N][D], double v[N][D], double m[N])
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
        double energy = calculate_kin_energy(i, v, m);

        return energy;
    }
}

double calculate_kin_energy(int i, double v[N][D], double m[N])
{
    double kin_energy = 0;
    for (int k = 0; k < D; k++)
    {
        kin_energy += 0.5 * m[i] * pow(v[i][k], 2);
    }

    printf("%.30e", kin_energy);
    return kin_energy;
}

// calculate the energy for each step
double calculate_pot_energy(double x[N][D], double v[N][D], double m[N])
{
    double energy = 0;
    for (int i = 1; 1 < N; i++)
    {
        for (int k = i; k < N; k++)
        {
            if (k == i)
            {
                energy += 1 / 2 * m[k] *
                              (pow(v[k][0], 2) + pow(v[k][1], 2) + pow(v[k][2], 2)) -
                          G * m[0] * m[k] /
                              (pow(x[k][0], 2) + pow(x[k][1], 2) + pow(x[k][2], 2));
            }
            else
            {
                energy += -G * m[k] * m[i] /
                          (pow(x[k][0] - x[i][0], 2) + pow(x[k][1] - x[i][1], 2) + pow(x[k][2] - x[i][2], 2));
            }
        }
    }
    return energy;
}