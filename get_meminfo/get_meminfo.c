#include "get_meminfo.h" 

MEM_PACK *get_memoccupy ()    // get RAM message  
{  
	FILE *fd;  
	int n;  
	double mem_total,mem_used_rate;;  
	char buff[256];  
	MEM_OCCUPY *m=(MEM_OCCUPY *)malloc(sizeof(MEM_OCCUPY));;  
	MEM_PACK *p=(MEM_PACK *)malloc(sizeof(MEM_PACK));  
	fd = fopen ("/proc/meminfo", "r");  

	fgets (buff, sizeof(buff), fd);  
	sscanf (buff, "%s %lu %s\n", m->name, &m->total, m->name2);  
	mem_total=m->total;  
	fgets (buff, sizeof(buff), fd);  
	sscanf (buff, "%s %lu %s\n", m->name, &m->total, m->name2);  
	mem_used_rate=(1-m->total/mem_total)*100;  
	mem_total=mem_total/(1024*1024);  
	p->total=mem_total;  
	p->used_rate=mem_used_rate;  
	fclose(fd);     //关闭文件fd  
	return p ;  
}  

