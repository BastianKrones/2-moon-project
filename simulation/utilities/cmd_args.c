#include "cmd_args.h"

void process_cmd_args(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            printf("Input initial steplenght: ");
            scanf("%Lf", &h);
        }
        else if (strcmp(argv[i], "-v") == 0)
        {
            calculate_velocities = 1;
        }
        // set end time for hours days years
        else if (strcmp(argv[i], "-th") == 0)
        {
            long double tim;
            printf("Please enter the hours you want to simulate: ");
            scanf("%Lf", &tim);
            t_end = tim * 60 * 60;
        }
        else if (strcmp(argv[i], "-td") == 0)
        {
            long double tim;
            printf("Please enter the days you want to simulate: ");
            scanf("%Lf", &tim);
            t_end = tim * 60 * 60 * 24;
        }
        else if (strcmp(argv[i], "-ty") == 0)
        {
            long double tim;
            printf("Please enter the years you want to simulate: ");
            scanf("%Lf", &tim);
            t_end = tim * 60 * 60 * 24 * 365;
        }
        // set after how many steps the progress should be saved
        else if (strcmp(argv[i], "-u") == 0)
        {
            long double tim;
            printf("Please enter after how many steps the step should be saved: ");
            scanf("%Lf", &u);
        }
        // activate energy check
        // this activates the variable step size
        else if ((strcmp(argv[i], "-ec") == 0))
        {
            enable_energy_check = 1;
            enable_varriable_stepsize = 1;
        }
        // catch any wrong arguments
        else
        {
            printf("Illegal CMD Argument: %s\n", argv[i]);
        }
    }
}