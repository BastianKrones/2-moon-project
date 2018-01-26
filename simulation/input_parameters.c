// Parameters of the simulation (t0 , tf , h, prec , ...)
#include "input_parameters.h"


h_2 = 0.5

double h()
{
    double h = 0.5;
    return h;
}

int size()
{
    int B = (t_1 - t_0)/h();
    return B;
}
