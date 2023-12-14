#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime = 0;
    int turnAroundTime = 0;
};
bool compareProcesses(const Process& p1, const Process& p2) {
    if (p1.priority < p2.priority) {
        return true;
    } else if (p1.priority == p2.priority) {
        return p1.arrivalTime < p2.arrivalTime;
    } else {
        return false;
    }
}
void calculateWaitingTime(vector<Process>& processes) {
    for (size_t i = 1; i < processes.size(); i++) {
        int previousCompletionTime = processes[i - 1].arrivalTime + processes[i - 1].burstTime;
        processes[i].waitingTime = max(0, previousCompletionTime - processes[i].arrivalTime);
    }
}
void calculateTurnAroundTime(vector<Process>& processes) {
    for (Process& process : processes) {
        process.turnAroundTime = process.waitingTime + process.burstTime;
    }
}
void displayProcessDetails(const vector<Process>& processes) {
    cout << "--------------------------------------------------------------------------------------\n";
    cout << " Process ID | Arrival Time | Burst Time | Priority | Waiting Time | Turn Around Time\n";
    cout << "--------------------------------------------------------------------------------------\n";
    for (const Process& process : processes) {
        cout << "     " << process.processId << "\t\t" << process.arrivalTime << "\t\t" << process.burstTime << \
        "\t\t" << process.priority << "\t\t" << process.waitingTime << "\t\t" << process.turnAroundTime << endl;
    }
    cout << "--------------------------------------------------------------------------------------\n";
}
int main() {
    int numberOfProcesses;
    cout << "Enter the number of processes: ";
    cin >> numberOfProcesses;
    vector<Process> processes(numberOfProcesses);

    for (int i = 0; i < numberOfProcesses; i++) {
        cout << "\nEnter process " << i + 1 << " details:" << endl;
        cout << "Process ID: ";
        cin >> processes[i].processId;
        cout << "Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> processes[i].burstTime;
        cout << "Priority: ";
        cin >> processes[i].priority;
    }
    sort(processes.begin(), processes.end(), compareProcesses);

    calculateWaitingTime(processes);
    calculateTurnAroundTime(processes);
    cout << "\nProcess Details:\n";
    displayProcessDetails(processes);
    return 0;
}
