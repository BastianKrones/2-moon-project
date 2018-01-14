// The definition of the Runge Kutta algorithm functions

//rungekutta shit lol :)
double Next(double h, int step, double t[S], double x[N][D][S], double v[N][D][S]){
	
	//these k and w variables
	double k[N][D][3], w[N][D][3];

	double vprime[N][D][S] = v;
       	double xprime[N][D][S] = x;


	//calculate k1 and w1
	for (int i = 1; i<N; i++){
		for (int j = 0; j<D; j++){
			k[i][j][0] = h * v[i][j][step];
			w[i][j][0] = h * calcualte_acceleration(i, j, step, x, m);
		}
	}

	//calculate k2 and w2
	for (int i = 1; i<N; i++){
		for (int j = 0; j<D; j++){
			vprime[i][j][step] += w[i][j][0]/2;
			xprime[i][j][step] += k[i][j][0]/2;
		}
	}

	for (int i = 1; i<N; i++){
		for (int j = 1; j<D; j++){
			w[i][j][1] = h * (vprime[i][j][step]);
			w[i][j][1] = h * calcualte_acceleration(i, j, step, xprime, m);
		}
	}

	//calculate k3 and w3
	for (int i = 1; i<N; i++){
		for (int j = 0; j<D; j++){
			vprime[i][j][step] += w[i][j][1]/2;
			xprime[i][j][step] += k[i][j][1]/2;
		}
	}

	for (int i = 1; i<N; i++){
		for (int j = 1; j<D; j++){
			w[i][j][2] = h * (vprime[i][j][step]);
			w[i][j][2] = h * calcualte_acceleration(i, j, step, xprime, m);
		}
	}

	//calculate k4 and w4
	for (int i = 1; i<N; i++){
		for (int j = 0; j<D; j++){
			vprime[i][j][step] += w[i][j][2];
			xprime[i][j][step] += k[i][j][2];
		}
	}

	for (int i = 1; i<N; i++){
		for (int j = 1; j<D; j++){
			w[i][j][3] = h * (vprime[i][j][step]);
			w[i][j][3] = h * calcualte_acceleration(i, j, step, xprime, m);
		}
	}

	//calculate the new variables	
	for (int i = 1; i<N; i++){
		for (int j = 1; j<D; j++){
			x[i][j][step + 1] = x[i][j][step] + k[i][j][0]/6 + k[i][j][1]/3 + k[i][j][3]/3 + k[i][j]/6;
			v[i][j][step + 1] = v[i][j][step] + w[i][j][0]/6 + w[i][j][1]/3 + w[i][j][3]/3 + w[i][j]/6;
		}
	}
	return x, v;
}
