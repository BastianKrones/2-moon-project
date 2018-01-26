// The simulation main program
#include "runge_kutta_4.h"

void nprint(int M, int L)
{
    int status = 1.0*L/M*100;
    printf("Status: [");
    for (int i = 0; i <= 99; i++)
    {
        if (i - 1 <= status)
        {
            printf("#");
        }
        else 
        {
            printf("%s", " ");
        }
    }
    printf("]\n");
}

void save_data_to_file(double x[N][D][S], double v[N][D][S], double t[S])
{
    FILE *fp;

    fp = fopen("./output_coord_cartesian", "w");

    for (int i = 0 ; i < S ; i++)
    {
        fprintf(fp, "%30f", t[i]);
        for (int j = 1 ; j < N ; j++)
        {
            for (int k = 0 ; k < D ; k++)
            {
                fprintf( fp , "%30f", x[j][k][i]);
            }
            for (int k = 0 ; k < D ; k++)
            {
                fprintf( fp , "%30f", v[j][k][i]);
            }
        }
        
        fprintf(fp, "\n");
    }

    fclose(fp);
};


int main(int argc, char* argv[])
{
    //define everything
    double energy[S];
    double x[N][D][S], v[N][D][S], a[N][D][S], t[S];
    double m[N];
    //initialize starting conditions
    t[0] = t_0;
    for (int b = 0; b < N; b++)
    {
        m[b] = initial_masses(b);
        for (int z = 0; z < D; z++)
        {
            x[b][z][0] = initial_pos(b, z);
            v[b][z][0] = initial_velocities(b, z);
        }
    }
    // energy[0] = calculate_energy(x, v, m, 0);


    //calculate every f***ing step
    int L = 0; //stepcounter
    while (L < (S-1) )
    {   
        Next(h(), L, t, x, v, m);
        L += 1;
        //nprint(S,L);
        // energy[L + 1] = calculate_energy(x, v, m, L);
    }

    save_data_to_file(x, v, t);
    
    return 0; //this ... is .... SPARTAAAAA!!!!!
}
