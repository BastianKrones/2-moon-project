#include "./utilities/cmd_args.h"
#include "./utilities/input_parameters.h"
#include "./utilities/initialize.h"
#include "./utilities/save_to_file.h"
#include "./check_simulation/energy.h"
#include "./runge_kutta/next.h"
#include "./check_simulation/check.h"

int main(int argc, char *argv[])
{
    FILE *fp;

    fp = fopen("./output_coord_cartesian", "w");

    fclose(fp);

    // define everything
    long double energy;
    int valid_step;
    int convergence_value;
    long double t;
    long double x[N][D], v[N][D];
    long double m[N];

    // initialisation, needs to be changes
    process_cmd_args(argc, argv);

    initialize(energy, t, x, v, m);

    t = 0;

    fp = fopen("./output_coord_cartesian", "a");

    // working loop remember t = t_0
    int k = 0;
    convergence_value = 1;
    while (t <= t_end)
    {
        // save_data_to_file(t, x, v);
        if (k % u == 0)
        {
            if (step_damage == 0)
            {
                printf("\r%4.2Lf %%", t / (t_end)*100);
            }
            else
            {
                printf("\r%4.2Lf %% |WARNING| initial steplenght failure", t / (t_end)*100);
            }

            // saves the data to the file
            fprintf(fp, "%20.4Lf", t);

            for (int i = N - 1; i >= 0; i--)
            {
                for (int j = D - 1; j >= 0; j--)
                {
                    fprintf(fp, "%20.4Lf", x[i][j]);
                }
            }

            long double p = calculate_distance(1, 2, x);

            fprintf(fp, "%20.4Lf", p);

            fprintf(fp, "\n");
        }

        k++;

        /*
        There is a possibility by just changing h by dubbeling or halving it
        that you could miss the wanted area where valid_step = 1, we encounter
        this issue by letting h converge into this Area
        */
        // Calculated step and checking the simulation
        // note: checks beeing disabeld will be handeld in ckeck()
        valid_step = check(v, x, t, m);
        if (valid_step == 0)
        {
            next(x, v, &t, m);
            convergence_value = 1;
        }
        else if (valid_step == 1)
        // note: this means the step needs to be increased
        // there is no problem running this step
        {
            recalculate_stepsize(valid_step);
            next(x, v, &t, m);
            convergence_value += 1;
        }
        else if (valid_step == -1)
        {
            recalculate_stepsize(valid_step);
        }
    }

    printf("\rDONE!                                                                            \n");
    fclose(fp);

    // calculate_kin_energy(1, v, m);

    return 0; // this ... is .... SPARTAAAAA!!!!!
}
