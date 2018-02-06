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

// precition for the energy check
extern long double prec_min;
extern long double prec_max;

extern long double h;
extern long double t_end;
extern int u;

// configuration data
extern int calculate_velocities;
extern int enable_energy_check;
extern int enable_step_check;
extern int enable_varriable_stepsize;
// this should give the user a warning if the initial steplenght
// is not working for the simulation
extern int step_damage;

long double initial_velocities(int n, int d);
long double calculate_initial_velocities(int n, int d);
long double initial_masses(int n);
long double initial_pos(int n, int d);

#endif