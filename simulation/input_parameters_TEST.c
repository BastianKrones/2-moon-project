#include "input_parameters.h"

double h_TEST()
{
    double h;
    h = h();
    if(h == 0.5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Size_TEST()
{
    int B = (t_1 - t_0) / h();
    return B;
}

void main()
{
    h_TEST();
}