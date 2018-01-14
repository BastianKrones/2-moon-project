// The definition of the Runge Kutta algorithm functions
#include "physical_calculations.h"

//rungekutta shit lol :) // x and v call by reference
void Next(double h, int step, double t[S], double x[N][D][S], double v[N][D][S], double m)
{

    //these k and w variables
    double k[N][D][3], w[N][D][3];

    double vprime[N][D][S];
    double xprime[N][D][S];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            for (int k = 0; k < S; k++)
            {
                vprime[i][j][k] = v[i][j][k];
                xprime[i][j][k] = x[i][j][k];
            }
        }
    }

    //calculate k1 and w1
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            k[i][j][0] = h * vprime[i][j][step];
            w[i][j][0] = h * calculate_acceleration(i, j, step, xprime, m);
        }
    }

    //calculate k2 and w2
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            vprime[i][j][step] += w[i][j][0] / 2;
            xprime[i][j][step] += k[i][j][0] / 2;
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < D; j++)
        {
            w[i][j][1] = h * (vprime[i][j][step]);
            w[i][j][1] = h * calculate_acceleration(i, j, step, xprime, m);
        }
    }

    //calculate k3 and w3
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            vprime[i][j][step] += w[i][j][1] / 2;
            xprime[i][j][step] += k[i][j][1] / 2;
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < D; j++)
        {
            w[i][j][2] = h * (vprime[i][j][step]);
            w[i][j][2] = h * calculate_acceleration(i, j, step, xprime, m);
        }
    }

    //calculate k4 and w4
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            vprime[i][j][step] += w[i][j][2];
            xprime[i][j][step] += k[i][j][2];
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < D; j++)
        {
            w[i][j][3] = h * (vprime[i][j][step]);
            w[i][j][3] = h * calculate_acceleration(i, j, step, xprime, m);
        }
    }

    //calculate the new variables
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < D; j++)
        {
            // x[i][j][step + 1] = x[i][j][step] + (k[i][j][0] / 6) + (k[i][j][1] / 3) + (k[i][j][3] / 3) + (k[i][j] / 6);
            x[i][j][step + 1] = x[i][j][step] + (k[i][j][0] / 6.0) + (k[i][j][1] / 3.0) + (k[i][j][2] / 3.0) + (k[i][j][3] / 6.0);
            v[i][j][step + 1] = v[i][j][step] + w[i][j][0] / 6 + w[i][j][1] / 3 + w[i][j][2] / 3 + w[i][j][3] / 6;
        }
    }
}
