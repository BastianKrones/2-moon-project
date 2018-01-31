#include "connector.h"

long double component_connect(int i, int j, long double modify[N][D][4], long double origin[N][D])
{
    long double returned_value = origin[i][j] + modify[i][j][0] / 6.0 + modify[i][j][1] / 3.0 + modify[i][j][2] / 3.0 + modify[i][j][3] / 6.0;
    return returned_value;
}