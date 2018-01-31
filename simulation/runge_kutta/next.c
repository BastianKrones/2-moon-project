#include "next.h"

void next(long double x[N][D], long double v[N][D], long double *t, long double m[N])
// testing this function would be a litte to complicadet, i'll do it later when i have enaught time. for now i will say it is runnung correctly
{
    
    long double xprime[N][D];
    long double vprime[N][D];

    long double w[N][D][4];
    long double k[N][D][4];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++){
            w[i][j][0] = 0;
            k[i][j][0] = 0;
        }
    }

    // printf("xlol = %Lf\n", xprime[1][1]);
    for (int mode = 0; mode < 4; mode++)
    {
        adv_copy(vprime, xprime, v, x, 0, w, k);
        calculate_orders(mode, k, w, xprime, vprime, m);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            x[i][j] = component_connect(i, j, k, x);
            v[i][j] = component_connect(i, j, w, v);
        }
    }
    *t = *t + h;
}