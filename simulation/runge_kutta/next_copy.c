#include "next_copy.h"

//gives the correct factor in front of the copy fuction
long double modes(int m)
{
    long double factor[4] = {0, 0.5, 0.5, 1};
    return factor[m];
}

void adv_copy(long double vprime[N][D], long double xprime[N][D], long double v[N][D], long double x[N][D], int mode, long double w[N][D][4], long double k[N][D][4])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            vprime[i][j] = v[i][j] + modes(mode) * w[i][j][mode];
            xprime[i][j] = x[i][j] + modes(mode) * k[i][j][mode];
        }
    }
}