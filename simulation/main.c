#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define D 2
#define g 6.67408 * pow(10,-11)
#define S //need to calculated before
//set inertial condition in form of xIJ where I is the I-th body and J the J-th dimention
//set inertial condition in form of vIJ where I is the I-th body and J the J-th dimention

//the force applied on the i-th body due to the j-th body
double fInternal(int i, int j, int d, int step, double x[N][D][S], double m[N]) {
	if i==j {
		return 0;
	}
	else {
		double G = g;
		//maybe change negative sign
		return -G * (m[i]*m[j])/(pow(x[i][0][step] - x[j][0][step],2) + pow(x[i][1][step] - x[j][1][step],2) + pow(x[i][2][step] - x[j][2][step],2))	
	}
}

//all the forces acting on the j-th body
double fExternal(int i, int d, int step, double x[N][D][S], double m[N]){
	double G = g;
	double radius = 0;
	for (int k = 0, k < N, k++){
		radius += pow(x[i][k][step], 2);
	}
	double force = -G * (m[0]*m[i])/radius
	for (int j = 1, j < N, j++){
		force += fInternal(i, j, d, step, x, m)
	}

}

//calculate the energy
double calculate_energy(double x10, double x11, double x20, double x22, ){
	double E = 
}

int main(void) {
	//inertial parameters (position, velocity, time of simulation)
	double T_0 = 0; 
	
	//final time of simulation
	double T_1 = 10; 
	
	//stepsize of simulation
	double h = 0.1;
		
	typedef struct {
		double energy[S];
		double prec;
		double x[N][D][S], v[N][D][S], t[S];
		double m[N];
	} RungeKutta4;
	
	RungeKutta4 rg = {
		.energy[0] = 
	};	



	return 0;
}
