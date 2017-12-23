#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	//stepsize
	float h = 0.05;

	//short for alpha
	float a = 1;
	//define the intervall
	float t_0 = 0;
	float T = 20;

	//starting position
	float x_0 = 1;

	//Nuber of steps needed
	int steps = (T - t_0) / h;
	double t[steps];
	double x[steps];

	t[0] = t_0;
	x[0] = x_0;

	for (int i = 1; i <= (steps - 1); i++)
	{
		t[i] = t[i - 1] + h;
		x[i] = x[i - 1] - a * x[i - 1] * h;
	}

	FILE *fp;

	fp = fopen("./data.txt", "w");

	for (int i = 0; i <= (steps - 1); i++)
	{
		fprintf(fp, "%f %11f \n", t[i], x[i]);
	}

	fclose(fp);

	return 0;
}
