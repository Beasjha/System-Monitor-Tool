#include "system_info.h"
#include <fstream>
#include <sstream>
#include <unistd.h>


using namespace std;


unsigned long long get_total_jiffies() {
ifstream f("/proc/stat");
if (!f.is_open()) return 0;
string line; getline(f, line);
// line: cpu 3357 0 4313 1362393 ...
istringstream iss(line);
string cpu; unsigned long long val, total = 0;
iss >> cpu;
while (iss >> val) total += val;
return total;
}
unsigned long long get_idle_jiffies() {
ifstream f("/proc/stat");
if (!f.is_open()) return 0;
string line; getline(f, line);
istringstream iss(line);
string cpu; unsigned long long user, nice, system, idle;
iss >> cpu >> user >> nice >> system >> idle;
return idle;
}
unsigned long long get_uptime_seconds() {
ifstream f("/proc/uptime");
if (!f.is_open()) return 0;
double up; f >> up; return (unsigned long long)up;
}
unsigned long long get_mem_total_kb() {
ifstream f("/proc/meminfo");
if (!f.is_open()) return 0;
string key; unsigned long long val; string unit;
while (f >> key >> val >> unit) {
if (key == "MemTotal:") return val; // in KB
}
return 0;
}

int get_num_cpus() {
long n = sysconf(_SC_NPROCESSORS_ONLN);
return (int)(n>0?n:1);
}
