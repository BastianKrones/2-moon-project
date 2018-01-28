#include <stdio.h>
#include <stdlib.h>
#include "./save_to_file.h"

void save_data_to_file(double t, long double x[N][D], long double v[N][D])
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
                fprintf(fp, "%20.0Lf", x[j][k]);
            }
            else
            {
                fprintf(fp, "%17.3Lf", x[j][k]);
            }
        }
        for (int k = 0; k < D; k++)
        {
            fprintf(fp, "%17.3Lf", v[j][k]);
        }
    }

    fprintf(fp, "\n");

    fclose(fp);
};