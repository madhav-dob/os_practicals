#include <iostream>
using namespace std;

void calculateWaitingTime(int processIDs[], int numOfProcesses, int burstTime[], int waitTime[]) {
    waitTime[0] = 0;
    for (int i = 1; i < numOfProcesses; i++)
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
}

void calculateTurnAroundTime(int processIDs[], int numOfProcesses, int burstTime[], int waitTime[], int turnAroundTime[]) {
    for (int i = 0; i < numOfProcesses; i++)
        turnAroundTime[i] = burstTime[i] + waitTime[i];
}
void calculateAvgTime(int processIDs[], int numOfProcesses, int burstTime[]) {
    
    int waitTime[numOfProcesses], turnAroundTime[numOfProcesses], totalWaitTime = 0, totalTurnAroundTime = 0;
    calculateWaitingTime(processIDs, numOfProcesses, burstTime, waitTime);
    calculateTurnAroundTime(processIDs, numOfProcesses, burstTime, waitTime, turnAroundTime);

    cout << "----------------------------------------------\n";
    cout << " Process ID | Burst Time | Waiting Time | Turnaround Time\n";
    cout << "----------------------------------------------\n";
    for (int i = 0; i < numOfProcesses; i++) {
        totalWaitTime += waitTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        cout << "     " << processIDs[i] << "\t   |     " << burstTime[i] << "\t  |     "
             << waitTime[i] << "\t   |     " << turnAroundTime[i] << endl;
    }
    cout << "----------------------------------------------\n";
    cout << "Average Waiting Time = "
         << (float)totalWaitTime / (float)numOfProcesses << endl;
    cout << "Average Turnaround Time = "
         << (float)totalTurnAroundTime / (float)numOfProcesses << endl;
}

int main() {
    int processIDs[] = {1, 2, 3};
    int numOfProcesses = sizeof processIDs / sizeof processIDs[0];
    int burstTime[] = {10, 5, 8};

    calculateAvgTime(processIDs, numOfProcesses, burstTime);
    return 0;
}
