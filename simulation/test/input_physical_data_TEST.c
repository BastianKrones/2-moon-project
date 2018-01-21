#include "../input_physical_data.h"
#include "input_physical_data_TEST.h"

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

// InitialIposition of all bodies (first entry = Saturn, second = moon 1, third = moon 2)
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

// Mass of all bodies
/* short initial_masses_TEST(int n)
{
	if(h() == 0.5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

short initial_pos_TEST(int b, int z)
{
	if(h() == 0.5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
} */