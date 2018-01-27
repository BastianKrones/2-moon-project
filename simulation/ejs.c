#include "cmd_args.h"
#include "input_parameters.h"
#include "initialize.h"
#include "utilities.h"
#include "energy.h"

int main(int argc, char *argv[])
{
    process_cmd_args(argc, argv);

    //define everything
    double energy;
    double t;
    double x[N][D], v[N][D];
    double m[N];

    initialize(energy, t, x, v, m);

    //to be iterated late on for each step/time
    save_data_to_file(t, x, v);

    calculate_kin_energy(1, v, m);

    return 0; //this ... is .... SPARTAAAAA!!!!!
}
