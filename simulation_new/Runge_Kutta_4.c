// The definition of the Runge Kutta algorithm functions

//rungekutta shit lol :)
double Next(double h, int step, double t[S], double x[N][D][S], double v[N][D][S])
{
    double k[N][D][3], w[N][D][3];

    //calculate k1 and w1
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            k[i][j][0] = h * v[i][j][step];
            w[i][j][0] = h * calcualte_acceleration(i, j, step, x, m);
        }
    }

    double vprime[N][D], xprimt[N][D];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
        }
    }
    //calculate k2 and w2
    for (int i = 1; i < N; i++)
    {
        w[i][j][1] = h * (v[i][j][step] + w[i][j][0] / 2);
        w[i][j][2] = h * calcualte_acceleration(i, j, step, x, m);
    }
}
