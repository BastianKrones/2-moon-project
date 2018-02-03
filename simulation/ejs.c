#include "./utilities/cmd_args.h"
#include "./utilities/input_parameters.h"
#include "./utilities/initialize.h"
#include "./utilities/save_to_file.h"
#include "./check_simulation/energy.h"
#include "./runge_kutta/connector.h"
#include "./runge_kutta/next.h"

int main(int argc, char *argv[])
{
    FILE *fp;

    fp = fopen("./output_coord_cartesian", "w");
    
    fclose(fp);

    //define everything
    long double energy;
    long double t;
    long double x[N][D], v[N][D];
    long double m[N];

    initialize(energy, t, x, v, m);

    t = 0;
    save_data_to_file(t, x, v);
    // working loop remember t = t_0
    int u = 0;
    while (t <= 100 * 24 * 60 * 60)
    {
        // printf("t = %Lf\n", t);
        next(x, v, &t, m);
        // printf("x = %Lf\n", x[1][1]);

        //to be iterated late on for each step/time
        if (u%300 == 0)
        {
        save_data_to_file(t, x, v);
        }
        printf("%Le\n", t/(100*24*60*60));
        u++;
    }

    // calculate_kin_energy(1, v, m);

    return 0; //this ... is .... SPARTAAAAA!!!!!
}
