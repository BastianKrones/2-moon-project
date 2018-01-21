#include <stdio.h>
#include "input_parameters_TEST.h"
#include "input_physical_data_TEST.h"

void main()
{
    printf("h()-Function: %i \n", h_TEST());
    printf("size()-Function: %i \n", h_TEST());
    printf("initial_velocities_TEST-Function: %i \n", initial_velocities_TEST());
    printf("initial_masses_TEST-Function: %i \n", initial_masses_TEST());
    printf("initial_pos_TEST-Function: %i \n", initial_pos_TEST());
}