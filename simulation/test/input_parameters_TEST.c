#include "../input_parameters.h"
#include "input_parameters_TEST.h"

short int h_TEST()
{
    return (h() == 0.5) ? 1 : 0;
}

short int size_TEST()
{
    return (size() == 40) ? 1 : 0;
}
