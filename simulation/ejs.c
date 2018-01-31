#include "./utilities/cmd_args.h"
#include "./utilities/input_parameters.h"
#include "./utilities/initialize.h"
#include "./utilities/save_to_file.h"
#include "./check_simulation/energy.h"
#include "./runge_kutta/connector.h"
#include "./runge_kutta/next.h"

int main(int argc, char *argv[])
{
    process_cmd_args(argc, argv);

    //define everything
    long double energy;
    long double t;
    long double x[N][D], v[N][D];
    long double m[N];

    initialize(energy, t, x, v, m);

    printf("t = %Lf\n", t);
    printf("x = %Lf\n", x[1][1]);
    t = 0;
    // working loop remember t = t_0
    while (t <= 200)
    {
        // printf("t = %Lf\n", t);
        next(x, v, &t, m);
        // printf("x = %Lf\n", x[1][1]);

        //to be iterated late on for each step/time
        save_data_to_file(t, x, v);
    }

    // calculate_kin_energy(1, v, m);

    return 0; //this ... is .... SPARTAAAAA!!!!!
}
