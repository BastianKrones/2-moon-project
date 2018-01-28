#include "./utilities/cmd_args.h"
#include "./utilities/input_parameters.h"
#include "./utilities/initialize.h"
#include "./utilities/save_to_file.h"
#include "./check_simulation/energy.h"

int main(int argc, char *argv[])
{
    process_cmd_args(argc, argv);

    //define everything
    long double energy;
    long double t;
    long double x[N][D], v[N][D];
    long double m[N];

    initialize(energy, t, x, v, m);

    //to be iterated late on for each step/time
    save_data_to_file(t, x, v);

    calculate_kin_energy(1, v, m);

    return 0; //this ... is .... SPARTAAAAA!!!!!
}
