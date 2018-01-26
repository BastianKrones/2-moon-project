// The definition of the Runge Kutta algorithm functions
#include "runge_kutta_4.h"


double fInternal(int i, int j, int d, int step, double x[N][D][S], double m[N])
{
    if (i == j)
    {
        return 0;
    }
    else
    {
        //maybe add a negative sign
        double rsqr;
        for (int b = 0; b < D; b++)
        {
            // printf("b= %d\n", b);
            rsqr += pow(x[i][b][step] - x[j][b][step], 2);
            // printf("rquar %11f\n", rquar);
        }
        return G * (m[i] * m[j]) / pow(rsqr, 3.0 / 2) * (x[j][d][step] - x[i][d][step]);
    }
}

//all the forces acting on the j-th body at the d-th dimention
double fExternal(int i, int d, int step, double x[N][D][S], double m[N])
{

    double rsqr;
    for (int b = 0; b < D; b++)
    {
        // printf("b= %d\n", b);
        rsqr += pow(x[i][b][step], 2);
        // printf("rquar %11f\n", rquar);
    }
    //maybe change negative sign here too
    double force = -G * (m[0] * m[i]) / pow(rsqr , 3.0 / 2) * x[i][d][step];
    // printf("force %11f\n", force);
    for (int j = 1; j < N; j++)
    {
        // printf("fInternal %11f\n", fInternal(i, j, d, step, x, m));
        force += fInternal(i, j, d, step, x, m);
    }
    return force;
}



//calculate the energy for each step
// double calculate_energy(double x[N][D][S], double v[N][D][S], double m[N], int step)
// {
//     double energy = 0;
//     for (int i = 1; 1 < N; i++)
//     {
//         for (int k = i; k < N; k++)
//         {
//             if (k == i)
//             {
//                 energy += 1 / 2 * m[k] *
//                               (pow(v[k][0][step], 2) + pow(v[k][1][step], 2) + pow(v[k][2][step], 2)) -
//                           G * m[0] * m[k] /
//                               (pow(x[k][0][step], 2) + pow(x[k][1][step], 2) + pow(x[k][2][step], 2));
//             }
//             else
//             {
//                 energy += -G * m[k] * m[i] /
//                           (pow(x[k][0][step] - x[i][0][step], 2) + pow(x[k][1][step] - x[i][1][step], 2) + pow(x[k][2][step] - x[i][2][step], 2));
//             }
//         }
//     }
//     return energy;


//calculate accseleration acting on the i-th body
double calculate_acceleration(int i, int d, int step, double x[N][D][S], double m[N])
{
    printf("u I %3d %3d %3d", i, d, step);
    printf("u%f\n", x[i][d][step]);
    // printf("fExternal %11f\n", fExternal(i, d, step, x, m));
    return fExternal(i, d, step, x, m) / m[i];
}


//rungekutta shit lol :) // x and v call by reference
void Next(double h, int step, double t[S], double x[N][D][S], double v[N][D][S], double m[N])
{
    //these k and w variables
    double k[N][D][3], w[N][D][3];

    double vprime[N][D][S];
    double xprime[N][D][S];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            for (int k = 0; k < step; k++)
            {
                vprime[i][j][k] = v[i][j][k];
                xprime[i][j][k] = x[i][j][k];
            }
        }
    }

    //calculate k1 and w1
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            // printf("calculate acceleration %11f\n", calculate_acceleration(i, j, step, xprime, m));
            k[i][j][0] = h * vprime[i][j][step];
            w[i][j][0] = h * calculate_acceleration(i, j, step, xprime, m);
        }
    }

    //calculate k2 and w2
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            vprime[i][j][step] = v[i][j][step] + w[i][j][0] / 2.0;
            xprime[i][j][step] = x[i][j][step] + k[i][j][0] / 2.0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            w[i][j][1] = h * (vprime[i][j][step]);
            w[i][j][1] = h * calculate_acceleration(i, j, step, xprime, m);
        }
    }

    //calculate k3 and w3
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            vprime[i][j][step] = v[i][j][step] + w[i][j][1] / 2.0;
            xprime[i][j][step] = x[i][j][step] + k[i][j][1] / 2.0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            w[i][j][2] = h * (vprime[i][j][step]);
            w[i][j][2] = h * calculate_acceleration(i, j, step, xprime, m);
        }
    }

    //calculate k4 and w4
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            vprime[i][j][step] = v[i][j][step] + w[i][j][2];
            xprime[i][j][step] = x[i][j][step] + k[i][j][2];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            w[i][j][3] = h * (vprime[i][j][step]);
            printf("i I %3d %3d %3d", i, j, step);
            printf(" X %f\n", xprime[i][j][step]);
            w[i][j][3] = h * calculate_acceleration(i, j, step, xprime, m);
            //printf("%f\n", calculate_acceleration(i, j, step, xprime, m));
        }
    }

    // for (int i=0; i < N; i++)
    // {
    //     for (int j=0; j < D; j++)
    //     {
    //         for (int k=0; k < 3; k++)
    //         {
    //             printf("%f\n", w[i][j][k]);
    //         }
    //     }
    // }

    
    //calculate the new variables
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            x[i][j][step + 1] = x[i][j][step] + (k[i][j][0] / 6.0) + (k[i][j][1] / 3.0) + (k[i][j][2] / 3.0) + (k[i][j][3] / 6.0);
            v[i][j][step + 1] = v[i][j][step] + (w[i][j][0] / 6.0) + (w[i][j][1] / 3.0) + (w[i][j][2] / 3.0) + (w[i][j][3] / 6.0);
            t[step + 1] = t[step] + h;
        }
    }
    return;
}



