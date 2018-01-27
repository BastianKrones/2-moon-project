#include "acceleration.h"

double calculate_acceleration(int i, int d, double x[N][D], double m[N])
{
    return fExternal(i, d, x, m)/m[i];
}