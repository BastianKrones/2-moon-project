#include "../input_parameters.h"
#include "input_parameters_TEST.h"

short h_TEST()
{
    return (h() == 0.5) ? 1 : 0;
}

short size_TEST()
{
    return (h() == 40) ? 1 : 0;
}