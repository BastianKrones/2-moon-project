#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float h = 0.5; //stepsize
	float a = 1; //short for alpha

	//define the intervall
	float t_0 = 0;
	float T = 20;

	float x_0 = 1; //starting position

	int steps = (T - t_0)/h; //Nuber of steps needed
	double t[steps];
	double x[steps];
	
	t[0] = t_0;
	x[0] = x_0;

	for (int i = 1; i <= (steps -1); i++){
		t[i] = t[i-1] + h;
		x[i] = x[i-1] - a * x[i-1] * h;
	}
	

	FILE*fp;
	printf("Hello World\n");
	return 0;
}