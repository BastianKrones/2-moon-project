#include <stdio.h>
#include "input_parameters_TEST.h"
#include "input_physical_data_TEST.h"

#define ANSI_COLOR_RED          "\033[1m\033[31m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_BOLD_RED     "\x1b[31m"
#define ANSI_COLOR_BOLD_GREEN   "\033[1m\033[32m"
#define ANSI_COLOR_WHITE        "\x1b[0;37m"

void print_test(char [], short);

void main()
{
    printf("\n#####################\n");
    printf("#                   #\n");
    printf("# Testing functions #\n");
    printf("#                   #\n");
    printf("#####################\n\n");
    print_test("h", h_TEST());
    print_test("size", h_TEST());
    print_test("initial_velocities", initial_velocities_TEST());
    print_test("initial_masses", initial_masses_TEST());
    print_test("initial_pos", initial_pos_TEST());
}

void print_test(char func_name[], short return_value)
{
    printf(ANSI_COLOR_WHITE "[ ");
    if (return_value == 1)
    {
        printf(ANSI_COLOR_BOLD_GREEN "%s", "\xE2\x9C\x93");
    }
    else
    {
        printf(ANSI_COLOR_BOLD_RED "%s", "X");
    }
    printf(ANSI_COLOR_WHITE " ]: %s \n", func_name);
    return;
}