#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "initial_data.c"

//the force applied on the i-th body due to the j-th body at the d-th dimention
double fInternal(int i, int j, int d, int step, double x[N][D][S], double m[N]) {
	if (i==j) {
		return 0;
	}
	else {
		//maybe add a negative sign
		return G * (m[i]*m[j])/
			pow(pow(x[i][0][step] - x[j][0][step],2) 
			+ pow(x[i][1][step] - x[j][1][step],2) 
			+ pow(x[i][2][step] - x[j][2][step],2),3/2) 
			* (x[j][d][step] - x[i][d][step]);
	}
}

//all the forces acting on the j-th body at the d-th dimention
double fExternal(int i, int d, int step, double x[N][D][S], double m[N]){
	//maybe change negative sign here too
	double force = -G * (m[0]*m[i])/pow(pow(x[i][0][step],2) 
			+ pow(x[i][1][step],2) 
			+ pow(x[i][2][step],2) ,3/2) 
			* x[i][d][step];

	for (int j = 1; j < N; j++){
		force += fInternal(i, j, d, step, x, m);
	}

	return force;
}


int main(void) {
	
// Starttime
const double t_0 = 0;

// Endtime
const double t_1 = 1;

// Amount of bodies
const int N = 3;

// Space dimensions
const int D = 2;

// Gravitational constant
const double G = 6.67408 * pow(10, -11);

// Steps of simulation | needs to be calculated individually
const int S = 20;

// InitialIposition of all bodies (first entry = Saturn, second = moon 1, third = moon 2)
const double initial_positions[N][D] = {{0,0},{1,1},{1,-1}}

// Initialvelocities of all bodies
const int initial_velocities[N][D] = {{0,0}, {0,0}, {0,0}}

// Mass of all bodies
const int initial_masses[N] = {1, 1, 1}
	//stepsize of simulation
	double h = 0.1;
		
	double energy[S];
	double prec;
	double x[N][D][S], v[N][D][S], t[S];
	double m[N];
	

	for (int b = 0; b<N; b++){
		for (int z = 0; z<D; z++){
			x[b][z][0] = initial_positions[b][z];
			v[b][z][0] = initial_velocities[b][z];
		}
	}



	return 0;
}
