#include "./check.h"

int check(long double v[N][D], long double x[N][D], long double t, long double m[N])
{
    // could be -1 for stepsize needs to be decreased
    // could be 0 for everything is fine
    // could be 1 for stepsize needs to be increased
    int check_result = 0;

    // Save the old steps vor comparrison and create copies
    // so that the current positions stays unchanged
    long double x_old[N][D], x_test[N][D];
    long double v_old[N][D], v_test[N][D];
    long double t_old, t_test;

    t_old = t;
    t_test = t;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            x_old[i][j] = x[i][j];
            x_test[i][j] = x[i][j];

            v_old[i][j] = v[i][j];
            v_test[i][j] = v[i][j];
        }
    }

    // calculate the next steps
    next(x_test, v_test, &t_test, m);

    // check for energy conservation
    if (enable_energy_check == 1)
    {
        // in order to test the change of the energy we measure here the
        // flow of energy in the  time direction, loke the first derivative
        // this is something like the Power
        long double P = (calculate_energy(x_old, v_old, m) - calculate_energy(x_test, v_test, m)) / h;
        // there is probably a factor befor prec_min and prec_max so that the
        // energy check and the step check are equivalent
        if (P < prec_min)
        {
            check_result = -1;
            step_damage = 1;
        }
        else if (P < prec_max)
        {
            check_result = 0;
        }
        else
        {
            check_result = 1;
        }
    }



    return check_result;
}