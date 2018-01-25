#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    //Process CMD Arguments
    for (int i = 1; i < argc ; i++)
    {
        if (strcmp(argv[i],"-h") == 0)
        {
            printf("yay it works\n");
        }
        else
        {
            printf("Illegal CMD Argument: %b\n", argv[i]=="-h");
        }
    }


    // //define everything
    // double energy[S];
    // double x[N][D], v[N][D], a[N][D], t;
    // double m[N];
    // //initialize starting conditions
    // t[0] = t_0;
    // for (int b = 0; b < N; b++)
    // {
    //     m[b] = initial_masses(b);
    //     for (int z = 0; z < D; z++)
    //     {
    //         x[b][z] = initial_pos(b, z);
    //         v[b][z] = initial_velocities(b, z);
    //     }
    // }
    
    return 0; //this ... is .... SPARTAAAAA!!!!!
}


