// Parameters of the simulation (t0 , tf , h, prec , ...)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define INPUT_PARAMETERSN

#define N 3
#define D 2
#define G (6.67408*pow(10, -11))
#define t_0 0
#define t_1 20
#define prec 1


extern double h;


double initial_velocities(int n, int d);
double initial_masses(int n);
double initial_pos(int b, int z);

