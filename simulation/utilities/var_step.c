#include "./var_step.h"

void recalculate_stepsize(int solution, int convergence)
{
    if (enable_varriable_stepsize == 1)
    {
        // case: increase
        if (solution == 1)
        {
            h = h + h / convergence;
        }
        // case: decrease
        else if (solution == -1)
        {
            h = h/2;
        }
    }
}