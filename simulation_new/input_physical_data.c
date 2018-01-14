// Physical data of the system ( masses and distances of the 3 bodies )
#include "input_parameters.h"

// Initialvelocities of all bodies
double initial_velocities(int n, int d)
{
	const int initial_velocities[N][D] = {{0, 0},
										  {0, 0},
										  {0, 0}};
	return initial_velocities[n][d];
}

// Mass of all bodies
double initial_masses(int n)
{
	const int initial_masses[N] = {1,
								   1,
								   1};
	return initial_masses[n];
}

// InitialIposition of all bodies (first entry = Saturn, second = moon 1, third = moon 2)
double inital_pos(int b, int z)
{
	const double initial_positions[N][D] = {{0, 0},
											{1, 1},
											{1, -1}};
	return initial_positions[b][z];
}