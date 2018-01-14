// Definition of additional functions

double From_Degree_to_Radians(double alpha){

};

double From_Radians_to_Degree(double alpha){

};

void From_Polar_to_Cartesian(double r, double theta, double *x, double *y){

};

void From_Cartesian_to_Polar(double x, double y, double *r, double *theta){

};

void Get_Velocity_Components(double v, double theta, double *vx, double *vy, short clockwise){

};

double From_Seconds_to_Days(double t){

};

double From_Days_to_Seconds(double t){

};

void Get_Distances_from_Center_of_Mass(double m[N], double x[N][D], double r[N]){

};

// void Save_data_to_file(char *filename, ...){
void Save_data_to_file(double x[N][D], double v[N][D], double t[S]{
    FILE *fp;

    fp = fopen("./output_coord_cartesian", "w");

    for (int i = 0; i < S) {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < D; k++)
                fprintf(fp, "%f %11f", x[j][k]);

            for (int k = 0; k < D; k++)
                fprintf(fp, "%11f %11f", v[j][k]);
        }
        fprintf(fp, "%11f", t[i])
    }

        fclose(fp);

    return 0;
};
