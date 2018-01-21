#include "initial_data.h"
// Starttime
double t_0()
{
	const double t_0 = 0;
	return t_0;
}
// Endtime
double t_1()
{
	const double t_1 = 1;
	return t_1;
}

// Amount of bodies
int N()
{
	const int N = 3;
	return N;
}

// Space dimensions
int D()
{
	const int D = 2;
	return D;
}

// Gravitational constant
double G()
{
	const double G = 6.67408 * pow(10, -11);
	return G;
}

// Steps of simulation | needs to be calculated individually
int S()
{
	const int S = 20;
	return S;
}

// Initialvelocities of all bodies
int initial_velocities(int n, int d)
{
	const int initial_velocities[N][D] = { {0, 0},
										   {0, 0},
										   {0, 0} } return initial_velocities[n][d];
}
// Mass of all bodies
int initial_masses(int n)
{
	const int initial_masses[N] = { 1,
									1,
									1 } return initial_masses[n];
}

// InitialIposition of all bodies (first entry = Saturn, second = moon 1, third = moon 2)
double inital_pos(int b, int z)
{
	const double initial_positions[N][D] = { {0, 0},
											 {1, 1},
											 {1, -1} } return initial_positions[b][z];
}
