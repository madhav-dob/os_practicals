#include<iostream>
#include<algorithm>
#include<vector>
#include<climits> 
using namespace std;
struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
};
bool compareArrivalTime(const Process& a, const Process& b) {
    return a.arrival_time < b.arrival_time;
}
int main() {
    int num_processes;
    cout << "Enter the number of processes: ";
    cin >> num_processes;
    vector<Process> processes(num_processes);
    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < num_processes; ++i) {
        processes[i].process_id = i + 1;
        cout << "Process " << processes[i].process_id << " Arrival Time: ";
        cin >> processes[i].arrival_time;
        cout << "Process " << processes[i].process_id << " Burst Time: ";
        cin >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }
    sort(processes.begin(), processes.end(), compareArrivalTime);
    int current_time = 0;
    int completed = 0;
    vector<int> waiting_time(num_processes, 0);
    cout << "\nGantt Chart:\n";
    while (completed < num_processes) {
        int shortest = -1;
        int shortest_remaining_time = INT_MAX;

        for (int i = 0; i < num_processes; ++i) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < \
            shortest_remaining_time && processes[i].remaining_time > 0) {
                shortest = i;
                shortest_remaining_time = processes[i].remaining_time;
            }
        }
        if (shortest == -1) {
            ++current_time;
            continue;
        }
        processes[shortest].remaining_time--;
        cout << "P" << processes[shortest].process_id << " | ";
        current_time++;

        if (processes[shortest].remaining_time == 0) {
            completed++;
            int finish_time = current_time;
            int turnaround_time = finish_time - processes[shortest].arrival_time;
            waiting_time[shortest] = turnaround_time - processes[shortest].burst_time;
        }
    }
    cout << "\n\nProcess\tTurnaround Time\tWaiting Time\n";
    double total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < num_processes; ++i) {
        cout << "P" << processes[i].process_id << "\t" << (processes[i].burst_time + waiting_time[i]) << "\t\t" << waiting_time[i] << "\n";
        total_waiting_time += waiting_time[i];
        total_turnaround_time += (processes[i].burst_time + waiting_time[i]);
    }
    cout << "\nAverage Turnaround Time: " << (total_turnaround_time / num_processes) << endl;
    cout << "Average Waiting Time: " << (total_waiting_time / num_processes) << endl;
    return 0;
}
