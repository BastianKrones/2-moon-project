#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float funtion(x,v){
	return 
}



int main(void){		
	float h = 0.05; //stepsize
	float a = 1; //short for alpha

	//define the intervall
	float t_0 = 0;
	float T = 10;

	float x_0 = 0; //starting parameters
	float v_0 = 1

	int steps = (T - t_0)/h; //Nuber of steps needed
	double t[steps];
	double x[steps];
	double v[steps];
	
	t[0] = t_0;
	v[0] = v_0;
	x[0] = x_0;

	for (int i = 1; i <= (steps -1); i++){
		k1 = h*v[i-1]
		w2 = h*
		t[i] = t[i-1] + h;
		x[i] = x[i-1] - a * x[i-1] * h;
	}
	

	FILE*fp;

	fp = fopen("./data.txt","w");
	

	for (int i = 0; i <= (steps -1); i++){
		fprintf(fp, "%f %11f \n", t[i], x[i]);
	}

	fclose(fp);
	
	return 0;
	
}
