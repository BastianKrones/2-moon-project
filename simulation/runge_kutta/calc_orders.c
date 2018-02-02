#include "calc_orders.h"

void calculate_orders(int mode, long double k[N][D][4], long double w[N][D][4], long double xprime[N][D], long double vprime[N][D], long double m[N])
// for w and k list places are [Body number][Dimention][mode]
// mode goes from 0 to 3
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            k[i][j][mode] = h * vprime[i][j];
            w[i][j][mode] = h * calculate_acceleration(i, j, xprime, m);
            printf("i= %d, j= %d, k= %Le, mode= %d\n", i,j,k[i][j][mode], mode);
        }
    }
}