#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <termios.h>
#include "proc_reader.h"

using namespace std;

void print_header(int refresh, string sort_mode) {
    cout << "============================================\n";
    cout << "     SYSTEM MONITOR TOOL (Refresh: " << refresh << "s)\n";
    cout << "     Sort by: " << sort_mode << "\n";
    cout << "============================================\n";
    cout << "PID\tCPU%\tMEM%\tNAME\n";
}

void prompt_kill() {
    int pid;
    cout << "\nEnter PID to kill (0 to cancel): ";
    cin >> pid;
    if (pid != 0) {
        kill_process(pid);
    }
}

int main(int argc, char** argv) {
    int refresh_time = 3;
    string sort_mode = "CPU";

    while (true) {
        system("clear");
        print_header(refresh_time, sort_mode);

        vector<ProcessInfo> processes = get_all_processes();

        if (sort_mode == "CPU")
            sort(processes.begin(), processes.end(), [](auto &a, auto &b) { return a.cpu_usage > b.cpu_usage; });
        else
            sort(processes.begin(), processes.end(), [](auto &a, auto &b) { return a.mem_usage > b.mem_usage; });

        for (auto &p : processes) {
            cout << p.pid << "\t" << p.cpu_usage << "\t" << p.mem_usage << "\t" << p.name << "\n";
        }

        cout << "\nPress [c] to sort by CPU, [m] for Memory, [k] to kill, [q] to quit.\n";

        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        char c;
        read(STDIN_FILENO, &c, 1);

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        if (c == 'q') break;
        if (c == 'c') sort_mode = "CPU";
        if (c == 'm') sort_mode = "Memory";
        if (c == 'k') prompt_kill();

        sleep(refresh_time);
    }

    return 0;
}

