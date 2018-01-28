#include "../utilities/input_parameters.h"
#include "../forces/acceleration.h"

#ifndef CALC_ORDERSN
#define CALC_ORDERSN

void calculate_orders(int mode, long double k[N][D][3], long double w[N][D][3], long double xprime[N][D], long double vprime[N][D], long double m[N]);

#endif