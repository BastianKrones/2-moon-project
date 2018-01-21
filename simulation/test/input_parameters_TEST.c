#include "../input_parameters.h"
#include "input_parameters_TEST.h"

short h_TEST()
{
    if(h() == 0.5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

short size_TEST()
{
    if(h() == 40)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}