#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./save_to_file.h"


void save_data_to_file(long double t, long double x[N][D], long double v[N][D])
{
    FILE *fp;

    fp = fopen("./output_coord_cartesian", "a");
    

    fprintf(fp, "%50.4Lf", t);
    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < D; k++)
        {
            if (j == 0)
            {
                fprintf(fp, "%50.4Lf", x[j][k]);
            }
            else
            {
                fprintf(fp, "%50.4Lf", x[j][k]);
            }
        }
        for (int k = 0; k < D; k++)
        {
            fprintf(fp, "%50.4Lf", v[j][k]);
        }
    }

    fprintf(fp, "\n");

    fclose(fp);
};