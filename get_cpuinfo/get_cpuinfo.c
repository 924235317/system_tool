#include "get_cpuinfo.h"

double cal_cpuoccupy (CPU_OCCUPY *o, CPU_OCCUPY *n)  
{  
	double od, nd;  
	double id, sd;  
	double cpu_use ;  

	od = (double) (o->user + o->nice + o->system +o->idle+o->softirq+o->iowait+o->irq);//第一次(用户+优先级+系统+空闲)的时间再赋给od  
	nd = (double) (n->user + n->nice + n->system +n->idle+n->softirq+n->iowait+n->irq);//第二次(用户+优先级+系统+空闲)的时间再赋给od  

	id = (double) (n->idle);    //用户第一次和第二次的时间之差再赋给id  
	sd = (double) (o->idle) ;    //系统第一次和第二次的时间之差再赋给sd  
	if((nd-od) != 0)  
		cpu_use =100.0- ((id-sd))/(nd-od)*100.00; //((用户+系统)乖100)除(第一次和第二次的时间差)再赋给g_cpu_used  
	else cpu_use = 0;  
	return cpu_use;  
}  

void get_cpuoccupy (CPU_OCCUPY *cpust)  
{  
	FILE *fd;  
	int n;  
	char buff[256];  
	CPU_OCCUPY *cpu_occupy;  
	cpu_occupy=cpust;  

	fd = fopen ("/proc/stat", "r");  
	fgets (buff, sizeof(buff), fd);  

	sscanf (buff, "%s %u %u %u %u %u %u %u", cpu_occupy->name, &cpu_occupy->user, &cpu_occupy->nice,&cpu_occupy->system, &cpu_occupy->idle ,&cpu_occupy->iowait,&cpu_occupy->irq,&cpu_occupy->softirq);  

	fclose(fd);  
}  

double getCpuRate()  
{  
	CPU_OCCUPY cpu_stat1;  
	CPU_OCCUPY cpu_stat2;  
	double cpu;  
	get_cpuoccupy((CPU_OCCUPY *)&cpu_stat1);
	sleep(1);  

	//第二次获取cpu使用情况  
	get_cpuoccupy((CPU_OCCUPY *)&cpu_stat2);  

	//计算cpu使用率  
	cpu = cal_cpuoccupy ((CPU_OCCUPY *)&cpu_stat1, (CPU_OCCUPY *)&cpu_stat2);  
	return cpu;  
}  
