// The 2nd introductory exercise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long double f(long double v,long double x){
	long double w = 1; //short for alpha
	return -w*x;
}



int main(void){
	long double h = 0.005; //stepsize

	//define the intervall
	long double t_0 = 0;
	long double T = 10;

	long double x_0 = 0; //starting parameters
	long double v_0 = 1;
	


	int steps = (T - t_0)/h; //Nuber of steps needed
	long double t[steps];
	long double x[steps];
	long double v[steps];
	
	t[0] = t_0;
	v[0] = v_0;
	x[0] = x_0;

	
	long double k1, k2, k3, k4, w1, w2, w3, w4;

	for (int i = 1; i <= (steps -1); i++){
		k1 = h*v[i-1];
		w1 = h*f(v[i-1],x[i-1]);
		k2 = h*(v[i-1] + w1/2);
		w2 = h*f(v[i-1] + w1/2, x[i-1] + k1/2);
		k3 = h*(v[i-1] + w2/2);
		w3 = h*f(v[i-1] + w2/2, x[i-1] + k2/2);
		k4 = h*(v[i-1] + w3/2);
		w4 = h*f(v[i-1] + w3/2, x[i-1] + k3/2);

		t[i] = t[i-1] + h;
		x[i] = x[i-1] + k1/6 + k2/3 + k3/3 + k4/6;
		v[i] = v[i-1] + w1/6 + w2/3 + w3/3 + w4/6;
	}
	

	FILE*fp;

	fp = fopen("./exercise_2/data.txt","w");
	

	for (int i = 0; i <= (steps -1); i++){
		fprintf(fp, "%Lf %11Lf %11Lf\n", t[i], x[i], v[i]);
	}

	fclose(fp);
	
	return 0;
	
}
