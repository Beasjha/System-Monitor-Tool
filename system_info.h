#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H


#include <string>


unsigned long long get_total_jiffies();
unsigned long long get_idle_jiffies();
unsigned long long get_uptime_seconds();
unsigned long long get_mem_total_kb();
int get_num_cpus();


#endif
