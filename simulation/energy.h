#include "input_parameters.h"

#ifndef ENERGYN
#define ENERGYN

double calculate_energy(int i, int j, double x[N][D], double v[N][D], double m[N]);
double calculate_kin_energy(int i, double v[N][D], double m[N]);

#endif