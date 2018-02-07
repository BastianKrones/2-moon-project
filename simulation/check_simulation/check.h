#include "../utilities/input_parameters.h"
#include "../runge_kutta/next.h"
#include "./energy.h"

#ifndef CHECKN
#define CHECKN

int check(long double v[N][D], long double x[N][D], long double t, long double energy, long double v_old[N][D], long double x_old[N][D], long double t_old, long double energy_old, long double m[N]);

#endif