#include "./utilities/cmd_args.h"
#include "./utilities/input_parameters.h"
#include "./utilities/initialize.h"
#include "./utilities/save_to_file.h"
#include "./check_simulation/energy.h"
#include "./runge_kutta/next.h"


int main(int argc, char *argv[])
{
    FILE *fp;

    fp = fopen("./output_coord_cartesian", "w");
    
    fclose(fp);

    // define everything
    long double energy;
    long double t;
    long double x[N][D], v[N][D];
    long double m[N];

    // initialisation, needs to be changes
    initialize(energy, t, x, v, m);

    t = 0;

    long double t_end = 10 * 365 * 24 * 60 * 60;
    save_data_to_file(t, x, v);

    // working loop remember t = t_0
    int u = 0;
    while (t <= t_end)
    {
        // Calculated step
        next(x, v, &t, m);

        // show a progress and save the data to the file every x steps
        if (u%300 == 0)
        {

            save_data_to_file(t, x, v);
            printf("\r%4.2Lf\n", t/(t_end) * 100);
        }
        u++;
    }

    // calculate_kin_energy(1, v, m);

    return 0; // this ... is .... SPARTAAAAA!!!!!
}
