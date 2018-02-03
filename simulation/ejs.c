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

    long double t_end = 20 * 365 * 24 * 60 * 60;

    fp = fopen("./output_coord_cartesian", "a");
    // working loop remember t = t_0
    int u = 0;
    while (t <= t_end)
    {
        // save_data_to_file(t, x, v);
        if (u % 1 == 0)
        {

            printf("%4.2Lf\n", t / (t_end)*100);

            // fprintf(fp, "%50.4Lf", t);

            fprintf(fp, "%20.4Lf", t);

            for (int i = N-1; i >= 0; i--)
            {
                for (int j = D-1; j >= 0; j--)
                {
                    fprintf(fp, "%20.4Lf", x[i][j]);
                }
            }

            long double p = calculate_distance(1, 2, x);

            fprintf(fp, "%20.4Lf", p);

            fprintf(fp, "\n");
        }

        u++;

        // Calculated step
        next(x, v, &t, m);
    }

    fclose(fp);

    // calculate_kin_energy(1, v, m);

    return 0; // this ... is .... SPARTAAAAA!!!!!
}
