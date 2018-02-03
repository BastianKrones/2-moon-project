#include "next.h"

// doing unit tests later on
void next(long double x[N][D], long double v[N][D], long double *t, long double m[N])
{

    long double xprime[N][D];
    long double vprime[N][D];

    long double w[N][D][4];
    long double k[N][D][4];


    // printf("xlol = %Lf\n", xprime[1][1]);

    // copy of vprime and xprime
    adv_copy(vprime, xprime, v, x, 0, w, k);

    // calculate k_0 und w_0
    calculate_orders(0, k, w, xprime, vprime, m);

    // copy new vectors with new conditions
    adv_copy(vprime, xprime, v, x, 1, w, k);

    calculate_orders(1, k, w, xprime, vprime, m);

    // printf("w_100 = %.20Le\n", vprime[1][0]);
    adv_copy(vprime, xprime, v, x, 2, w, k);

    calculate_orders(2, k, w, xprime, vprime, m);

    adv_copy(vprime, xprime, v, x, 3, w, k);
    calculate_orders(3, k, w, xprime, vprime, m);





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