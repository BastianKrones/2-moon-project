#include "../input_physical_data.h"
#include "input_physical_data_TEST.h"

// double initial_velocities(int n, int d)
// {
// 	const int initial_velocities[N][D] = {{0, 0},
// 										  {0, 0},
// 										  {0, 0}};
// 	return initial_velocities[n][d];
// }
short initial_velocities_TEST()
{
    if (initial_velocities(1, 1) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// double initial_masses(int n)
// {
// 	const int initial_masses[N] = {1,
// 								   1,
// 								   1};
// 	return initial_masses[n];
// }
short initial_masses_TEST()
{
    if (initial_masses(1) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// double initial_pos(int b, int z)
// {
// 	const double initial_positions[N][D] = {{0, 0},
// 											{1, 1},
// 											{1, -1}};
// 	return initial_positions[b][z];
// }
short initial_pos_TEST()
{
    if (initial_pos(2, 1) == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
