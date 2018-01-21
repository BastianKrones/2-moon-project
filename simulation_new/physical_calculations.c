//the force applied on the i-th body due to the j-th body at the d-th dimention
#include "input_parameters.h"
#include <math.h>
double fInternal(int i, int j, int d, int step, double x[N][D][S], double m[N])
{
    if (i == j)
    {
        return 0;
    }
    else
    {
        //maybe add a negative sign
        double rquar;
        for (int b = 0; b < D; b++)
        {
            rquar += pow(x[i][b][step] - x[j][b][step], 2);
        }
        return G * (m[i] * m[j]) / pow(rquar, 3 / 2) * (x[j][d][step] - x[i][d][step]);
    }
}

//all the forces acting on the j-th body at the d-th dimention
double fExternal(int i, int d, int step, double x[3][2][20], double m[3])
{
    //maybe change negative sign here too
    double force = -G * (m[0] * m[i]) / pow(pow(x[i][0][step], 2) + pow(x[i][1][step], 2) + pow(x[i][2][step], 2), 3 / 2) * x[i][d][step];

    for (int j = 1; j < N; j++)
    {
        force += fInternal(i, j, d, step, x, m);
    }
    return force;
}

//calculate the next step
//double Next(int step):

//calculate the energy for each step
double calculate_energy(double x[N][D][S], double v[N][D][S], double m[N], int step)
{
    double energy = 0;
    for (int i = 1; 1 < N; i++)
    {
        for (int k = i; k < N; k++)
        {
            if (k == i)
            {
                energy += 1 / 2 * m[k] *
                              (pow(v[k][0][step], 2) + pow(v[k][1][step], 2) + pow(v[k][2][step], 2)) -
                          G * m[0] * m[k] /
                              (pow(x[k][0][step], 2) + pow(x[k][1][step], 2) + pow(x[k][2][step], 2));
            }
            else
            {
                energy += -G * m[k] * m[i] /
                          (pow(x[k][0][step] - x[i][0][step], 2) + pow(x[k][1][step] - x[i][1][step], 2) + pow(x[k][2][step] - x[i][2][step], 2));
            }
        }
    }
    return energy;
}

//calculate accseleration acting on the i-th body
double calculate_acceleration(int i, int d, int step, double x[N][D][S], double m[N])
{
    return fExternal(i, d, step, x, m) / m[i];
}