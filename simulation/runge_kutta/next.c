#include "next.h"

// doing unit tests later on
void next(long double x[N][D], long double v[N][D], long double *t, long double m[N], long double L)
{

    long double xprime[N][D];
    long double vprime[N][D];

    long double w[N][D][4];
    long double k[N][D][4];

    for (int i = 0; i < 4; i++)
    {
        adv_copy(vprime, xprime, v, x, i, w, k);

        calculate_orders(i, k, w, xprime, vprime, m, L);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            x[i][j] = component_connect(i, j, k, x);
            v[i][j] = component_connect(i, j, w, v);
        }
    }
    *t = *t + L;
}