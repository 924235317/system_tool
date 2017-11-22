#include <stdio.h>

typedef struct CPU_PACKED         //定义一个cpu occupy的结构体  
{  
    char name[20];             //定义一个char类型的数组名name有20个元素  
    unsigned int user;        //定义一个无符号的int类型的user  
    unsigned int nice;        //定义一个无符号的int类型的nice  
    unsigned int system;    //定义一个无符号的int类型的system  
    unsigned int idle;         //定义一个无符号的int类型的idle  
    unsigned int iowait;  
    unsigned int irq;  
    unsigned int softirq;  
}CPU_OCCUPY;  
double cal_cpuoccupy (CPU_OCCUPY *o, CPU_OCCUPY *n); 
void get_cpuoccupy (CPU_OCCUPY *cpust);
double getCpuRate();
