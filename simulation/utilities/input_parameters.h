#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//###########################################
#ifndef INPUT_PARAMETERSN
#define INPUT_PARAMETERSN

#define N 3
#define D 2
#define G (6.67408*pow(10, -11))
#define t_0 0
#define prec 1


extern long double h;
extern int calculate_velocities;
extern long double t_end;
extern int u;

long double initial_velocities(int n, int d);
long double calculate_initial_velocities(int n, int d);
long double initial_masses(int n);
long double initial_pos(int n, int d);

#endif