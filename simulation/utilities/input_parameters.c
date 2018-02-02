// Parameters of the simulation (t0 , tf , h, prec , ...)
#include "input_parameters.h"

// Initialvelocities of all bodies
long double initial_velocities(int n, int d)
{
	const long double initial_velocities[N][D] = {{0, 0},
											 {0, -23630},
											 {0, -36234}};
	return initial_velocities[n][d];
}

// Mass of all bodies
long double initial_masses(int n)
{
	const long double initial_masses[N] = {5.68319 * pow(10, 26),
									  5.266 *  pow(10, 17),
									  1.912 * pow(10, 18)};
	return initial_masses[n];
}

// InitialIposition of all bodies (first entry = Saturn, second = moon 1, third = moon 2)
long double initial_pos(int b, int z)
{
	const long double initial_positions[N][D] = {{0, 0},
											{151410, 0},
											{151460, 0}};
	return initial_positions[b][z];
}

long double h = 60*60*24*100;