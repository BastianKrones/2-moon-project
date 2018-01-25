// Definition of additional functions
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

// double From_Degree_to_Radians(double alpha){

// };

// double From_Radians_to_Degree(double alpha){

// };

// void From_Polar_to_Cartesian(double r, double theta, double *x, double *y){

// };

// void From_Cartesian_to_Polar(double x, double y, double *r, double *theta){

// };

// void Get_Velocity_Components(double v, double theta, double *vx, double *vy, short clockwise){

// };

// double From_Seconds_to_Days(double t){

// };

// double From_Days_to_Seconds(double t){

// };

// void Get_Distances_from_Center_of_Mass(double m[N], double x[N][D], double r[N]){

// };

// void Save_data_to_file(char *filename, ...){
//fprintf(fp, "%f %11f %11f\n", t[i], x[i], v[i]);
/*
It is important how to save tha file, so here is a breef example,
where the time moves downwards.

time | y_0_0 | y_0_1 | ... | y_1_0 | y_1_2 | ... | y_0_0 | y_0_1 | ... | y_1_0 | y_1_2 | ... |

*/
void save_data_to_file(double x[N][D], double v[N][D], double t[S])
{
    FILE *fp;

    fp = fopen("./output_coord_cartesian", "w");

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
