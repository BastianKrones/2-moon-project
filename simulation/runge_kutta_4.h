// The declaration of the Runge Kutta algorithm functions
#include "input_physical_data.h"

void Next(double h, int step, double t[S], double x[N][D][S], double v[N][D][S], double m[N]);
// double calculate_energy(double x[N][D][S], double v[N][D][S], double m[N], int step);
double calculate_acceleration(int i, int d, int step, double x[N][D][S], double m[N]);
