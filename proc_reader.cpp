#include "proc_reader.h"
#include <fstream>
#include <sstream>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <iostream>

using namespace std;

vector<ProcessInfo> get_all_processes() {
    vector<ProcessInfo> processes;
    DIR* dir = opendir("/proc");
    struct dirent* entry;

    while ((entry = readdir(dir)) != nullptr) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            string cmd_path = "/proc/" + string(entry->d_name) + "/comm";
            ifstream cmd_file(cmd_path);
            string name;
            getline(cmd_file, name);
            cmd_file.close();

            ProcessInfo p;
            p.pid = pid;
            p.name = name;
            p.cpu_usage = rand() % 100;   // Simulated CPU usage
            p.mem_usage = rand() % 100;   // Simulated Memory usage
            processes.push_back(p);
        }
    }
    closedir(dir);
    return processes;
}

void kill_process(int pid) {
    if (kill(pid, SIGKILL) == 0)
        cout << "Process " << pid << " terminated successfully.\n";
    else
        perror("Error terminating process");
}

