#include "cmd_args.h"
#include "input_parameters.h"
#include "initialize.h"


int main(int argc, char* argv[])
{
    process_cmd_args(argc, argv);

    //define everything
    double energy;
    double t;
    double x[N][D], v[N][D];
    double m[N];

    initialize(energy, t, x, v, m);

    return 0; //this ... is .... SPARTAAAAA!!!!!
}


