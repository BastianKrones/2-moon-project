#include <stdio.h>
#include <stdlib.h>
#include "uprint.h"

void nprint(int M, int L)
{
    int status = L/M*100;
    printf("%d",status);
    printf("Status: [");
    for (int i = 0; i <= M; i++)
    {
        if (i <= status)
        {
            printf("#");
        }
        else 
        {
            printf("%s", " ");
        }
    }
    printf("]");
}

int main()
{
    nprint(100, 50);
    return 0;
}




