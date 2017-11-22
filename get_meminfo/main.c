#include <stdio.h>
#include "get_meminfo.h"

int main()
{
    MEM_PACK *mem_pack = get_memoccupy();

    printf("%f, %f", mem_pack->total, mem_pack->used_rate);
}
