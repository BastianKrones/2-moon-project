#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define D 2

double fInternal(int i, int j, int d, double t




int main(void) {
	//inertial parameters (position, velocity, time of simulation)
	double X_0;
	double V_0;
	double T_0; 
	
	//final time of simulation
	double T_1; 
	
	//stepsize of simulation
	double h;

	//amount of steps
	int S = (T_1 - T_0)/h; 

	typedef struct {
		short energy_check;
		double prec;
		double x[N][D][S], v[N][D][S], t[S];
	} RungeKutta4;
}
