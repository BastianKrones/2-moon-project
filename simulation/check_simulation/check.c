#include "./check.h"

int check(long double v[N][D], long double x[N][D], long double t, long double energy, long double v_old[N][D], long double x_old[N][D], long double t_old, long double energy_old, long double m[N])
{
    // could be -1 for stepsize needs to be decreased
    // could be 0 for everything is fine
    // could be 1 for stepsize needs to be increased
    int check_result = 0;

    // check for energy conservation
    if (enable_energy_check == 1)
    {
        // in order to test the change of the energy we measure here the
        // flow of energy in the  time direction, loke the first derivative
        // this is something like the Power
        long double P = fabsl(energy / energy_old - 1);
        // printf("P = %Le energy = %Le, energy_old = %Le\n", P, energy, energy_old);
        // there is probably a factor befor prec_min and prec_max so that the
        // energy check and the step check are equivalent
        if (P < prec_min)
        {
            check_result = 1;
        }
        else if (P < prec_max)
        {
            check_result = 0;
        }
        else
        {
            check_result = -1;
        }
    }

    if (enable_step_check == 1)
    // create data to 2 step
    {
        long double x_test[N][D];
        long double v_test[N][D];
        long double t_test;

        t_test = t_old;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < D; j++)
            {
                x_test[i][j] = x_old[i][j];
                v_test[i][j] = v_old[i][j];
            }
        }

        // do 2 step
        next(x_test, v_test, &t_test, m, h / 2);
        next(x_test, v_test, &t_test, m, h / 2);

        //calculate maximum distance between the 2 step and 1 step coordinate
        long double max = 0;
        long double distance;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < D; j++)
            {
                distance = fabsl(x_test[i][j] - x[i][j]);
                if (max < distance)
                {
                    max = distance;
                }
            }
        }

        // this is made to make step check kind of equivalent to energy check
        long double factor = 8500000000000;

        // evaluate the distance
        if (max < factor * prec_min)
        {
            check_result = 1;
        }
        else if (max < factor * prec_max)
        {
            check_result = 0;
        }
        else
        {
            check_result = -1;
        }
    }

    return check_result;
}