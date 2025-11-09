🖥️ System Monitor Tool
A lightweight command-line system monitoring utility written in C++ that displays real-time information about running processes — including their CPU usage, memory consumption, and process IDs — all in a simple and efficient interface.

🌟 Features:
🔍 Displays all currently running processes in a clean tabular format
⚙️ Shows PID, CPU %, Memory %, and Command name
🔄 Automatically refreshes process data at regular intervals
🧠 Allows sorting by CPU or Memory usage
🗑️ Enables you to kill any process by PID directly from the interface
🚪 Press Q to exit gracefully anytime

⚙️ Technologies Used
Language: C++
Compiler: g++
Build Tool: Makefile
System Calls: /proc filesystem (Linux)

💻 Installation & Setup
1️⃣ Clone this repository
git clone https://github.com/Beasjha/System-Monitor-Tool.git
cd System-Monitor-Tool

2️⃣ Compile using Makefile
make

3️⃣ Run the executable
./sysmon

4️⃣ Controls inside the tool:
Key	Action
C	Sort by CPU usage
M	Sort by Memory usage
K	Kill a process (enter PID)
Q	Quit the monitor

🧩 Project Structure
SystemMonitorTool/
├── main.cpp           # Main logic and UI loop
├── proc_reader.cpp    # Process information reading from /proc
├── proc_reader.h      # Header file for process structure
├── Makefile           # Build automation
└── README.md          # Project documentation
