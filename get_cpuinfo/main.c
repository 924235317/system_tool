#include <stdio.h>
#include "get_cpuinfo.h"

int main()
{
    double rate = getCpuRate();

    printf("%f\n", rate);
}
