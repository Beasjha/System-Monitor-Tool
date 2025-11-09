#ifndef PROC_READER_H
#define PROC_READER_H

#include <string>
#include <vector>
using namespace std;

struct ProcessInfo {
    int pid;
    string name;
    double cpu_usage;
    double mem_usage;
};

vector<ProcessInfo> get_all_processes();
void kill_process(int pid);

#endif

