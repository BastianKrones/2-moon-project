#include "./utilities/cmd_args.h"
#include "./utilities/input_parameters.h"
#include "./utilities/initialize.h"
#include "./utilities/save_to_file.h"
#include "./check_simulation/energy.h"
#include "./runge_kutta/next.h"
#include "./check_simulation/check.h"
#include "./utilities/var_step.h"
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

    long double t_old;
    long double energy_old;
    long double x_old[N][D], v_old[N][D];

    // create test date for energy check
    // initialisation, needs to be changes
    process_cmd_args(argc, argv);

    initialize(&energy, &t, x, v, m);

    t = 0;

    fp = fopen("./output_coord_cartesian", "a");

    // working loop remember t = t_0
    int k = 0;
    convergence_value = 1;
    while (t <= t_end)
    {
        // Save data and create output
        if ((k % u == 0) && (valid_step == 1 || valid_step == 0))
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

            fprintf(fp, "\n");
        }

        //########################################################################
        //########################################################################
        //##########################Calculate#####################################
        //############################Step########################################
        //########################################################################
        //########################################################################

        /*
        There is a possibility by just changing h by dubbeling or halving it
        that you could miss the wanted area where valid_step = 1, we encounter
        this issue by letting h converge into this Area
        */

        // note: checks beeing disabeld will be handeld in ckeck()
        if (k != 0)
        {
            valid_step = check(v, x, t, energy, v_old, x_old, t_old, energy_old, m);
        }
        else
        {
            valid_step = 0;
        }

        // create copy for next step and backup precition error
        if (valid_step == -1)
        {
            t = t_old;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    energy = energy_old;
                    x[i][j] = x_old[i][j];
                    v[i][j] = v_old[i][j];
                }
            }
        }
        else
        {
            t_old = t;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    energy_old = energy;
                    x_old[i][j] = x[i][j];
                    v_old[i][j] = v[i][j];
                }
            }
        }

        // calculate the next step
        if ((valid_step == 0) || (enable_varriable_stepsize == 0))
        {
            next(x, v, &t, m, h);
            energy = calculate_energy(x, v, m);
            // convergence_value = 1;
            k++;
        }
        else if (valid_step == 1)
        // note: this means the step needs to be increased
        // there is no problem running this step
        {
            next(x, v, &t, m, h);
            recalculate_stepsize(valid_step, convergence_value);
            energy = calculate_energy(x, v, m);
            convergence_value += 1;
            k++;
        }
        else if (valid_step == -1)
        {
            recalculate_stepsize(valid_step, convergence_value);
        }

        // This starts the error message for the user
        if (valid_step == 1)
        {
            step_damage = 1;
        }
    }

    printf("\rDONE!                                                                            \n");
    fclose(fp);

    // calculate_kin_energy(1, v, m);

    return 0; // this ... is .... SPARTAAAAA!!!!!
}
