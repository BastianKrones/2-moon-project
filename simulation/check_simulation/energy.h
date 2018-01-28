#include "../utilities/input_parameters.h"

#ifndef ENERGYN
#define ENERGYN

long double calculate_energy(int i, int j, long double x[N][D], long double v[N][D], long double m[N]);
long double calculate_kin_energy(int i, long double v[N][D], long double m[N]);

#endif