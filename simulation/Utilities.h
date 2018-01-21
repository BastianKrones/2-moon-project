// Declaration of additional functions (those in the end of § 4)

double From_Degree_to_Radians ( double alpha );
double From_Radians_to_Degree ( double alpha );
void From_Polar_to_Cartesian ( double r, double theta , double *x, double *y);
void From_Cartesian_to_Polar ( double x, double y, double *r, double * theta );
void Get_Velocity_Components ( double v, double theta , double *vx , double *vy , short clockwise );
double From_Seconds_to_Days ( double t) ;
double From_Days_to_Seconds ( double t) ;
void Get_Distances_from_Center_of_Mass ( double m[N], double x[N][D], double r[N]) ;
void Save_data_to_file ( char * filename , ... );