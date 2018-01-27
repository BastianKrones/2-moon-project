#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

void save_data_to_file(double t, double x[N][D], double v[N][D])
{
    FILE *fp;

    fp = fopen("./output_coord_cartesian", "w");

    fprintf(fp, "%17.0f", t);
    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < D; k++)
        {
            if (j == 0)
            {
                fprintf(fp, "%20.0f", x[j][k]);
            }
            else
            {
                fprintf(fp, "%17.3f", x[j][k]);
            }
        }
        for (int k = 0; k < D; k++)
        {
            fprintf(fp, "%17.3f", v[j][k]);
        }
    }

    fprintf(fp, "\n");

    fclose(fp);
};