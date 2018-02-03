// Parameters of the simulation (t0 , tf , h, prec , ...)
#include "input_parameters.h"

// Initialvelocities of all bodies
long double initial_velocities(int n, int d)
{
	const long double initial_velocities[N][D] = {{0, 0},
												  {0, 15830},
												  {0, -15833}};
	return initial_velocities[n][d];
}

long double calculate_initial_velocities(int n, int d)
{
	const long double initial_velocities[N][D] = {{0, 0},
												  {0, sqrt(G*initial_masses(0)/initial_pos(1,0))},
												  {0, sqrt(G*initial_masses(0)/initial_pos(2,0))}};
	return initial_velocities[n][d];
}
// Mass of all bodies
long double initial_masses(int n)
{
	const long double initial_masses[N] = {
		5.699 * pow(10, 26), // 5.68319 * pow(10, 26),
		1.98 * pow(10, 18),  //   5.266 *  pow(10, 17),
		5.5 * pow(10, 17)	// 1.912 * pow(10, 18)};
	};
	return initial_masses[n];
}

// InitialIposition of all bodies (first entry = Saturn, second = moon 1, third = moon 2)
long double initial_pos(int n, int d)
{
	const long double initial_positions[N][D] = {{0, 0},
												 {-151410000, 0},
												 {151460000, 0}};
	return initial_positions[n][d];
}

long double h = 60;
int calculate_velocities = 0;