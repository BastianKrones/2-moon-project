#include "utilities.h"

void save_data_to_file(double x[N][D], double v[N][D], double t[S])
{
    FILE *fp = fopen("./output_coord_cartesian", "w");

    for (int i = 0 ; i < S ; i++)
    {
        fprintf(fp, "%11f", t[i]);
        for (int j = 0 ; j < N ; j++)
        {
            for (int k = 0 ; k < D ; k++)
            {
                fprintf( fp , "%11f", x[j][k][i]);
            }
            for (int k = 0 ; k < D ; k++)
            {
                fprintf( fp , "%11f", v[j][k][i]);
            }
        }
        
        fprintf(fp, "\n");
    }

    fclose(fp);
};