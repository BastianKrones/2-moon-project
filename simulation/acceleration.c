#include "acceleration.h"

// acceleration on the i-th body (centered body has no acceleration)
double calculate_acceleration(int i, int d, double x[N][D], double m[N])
{
    return fExternal(i, d, x, m)/m[i];
}