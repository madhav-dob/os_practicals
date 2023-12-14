#include <iostream>
#include <queue>

// Structure to represent a process
struct Process {
    int id;       // process ID
    int priority; // priority of the process
};

// Custom comparison function for the priority queue
struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority < p2.priority;
    }
};

int main() {
    // Create a priority queue of processes
    std::priority_queue<Process, std::vector<Process>, ComparePriority> scheduler;

    // Add processes to the scheduler
    Process p1 = {1, 2};
    Process p2 = {2, 1};
    Process p3 = {3, 3};

    scheduler.push(p1);
    scheduler.push(p2);
    scheduler.push(p3);

    // Process the scheduled tasks
    while (!scheduler.empty()) {
        Process currentProcess = scheduler.top();
        scheduler.pop();

        std::cout << "Processing process with ID: " << currentProcess.id << std::endl;
        // Perform necessary computations or operations for the current process
    }

    return 0;
}
