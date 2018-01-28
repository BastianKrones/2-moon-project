#include "acceleration.h"

// acceleration on the i-th body (centered body has no acceleration)
long double calculate_acceleration(int i, int d, long double x[N][D], long double m[N])
{
    return fExternal(i, d, x, m) / m[i];
}