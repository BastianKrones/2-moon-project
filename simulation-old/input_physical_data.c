// Physical data of the system ( masses and distances of the 3 bodies )
#include "input_physical_data.h"

// Initialvelocities of all bodies
double initial_velocities(int n, int d)
{
	const int initial_velocities[N][D] = {{0, 0},
										  {325634, -23630},
										  {15324, -36234}};
	return initial_velocities[n][d];
}

// Mass of all bodies
double initial_masses(int n)
{
	const int initial_masses[N] = {542781632,
								   12414421,
								   125252};
	return initial_masses[n];
}

// InitialIposition of all bodies (first entry = Saturn, second = moon 1, third = moon 2)
double initial_pos(int b, int z)
{
	const double initial_positions[N][D] = {{0, 0},
											{631952837, 6532892},
											{4567843432, -467456634}};
	return initial_positions[b][z];
}