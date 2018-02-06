#include "../utilities/input_parameters.h"
#include "../runge_kutta/next.h"
#include "./energy.h"

#ifndef CHECKN
#define CHECKN

int check(long double v[N][D], long double x[N][D], long double t, long double m[N]);

#endif