#include <stdio.h>
#include "input_parameters_TEST.h"
#include "input_physical_data_TEST.h"

void print_test(char [], short);

void main()
{
    printf("Testing functions: \n");
    print_test("h", h_TEST());
    print_test("size", h_TEST());
    print_test("initial_velocities", initial_velocities_TEST());
    print_test("initial_masses", initial_masses_TEST());
    print_test("initial_pos", initial_pos_TEST());
}

void print_test(char func_name[], short return_value)
{
    printf("%s: %s \n", (return_value==1) ? "SUCCESS" : "FAILED ", func_name);
    return;
}-.