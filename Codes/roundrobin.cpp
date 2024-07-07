#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Process
{
    int id;
    int burstTime;
    int remainingTime;
};
void roundRobinScheduling(vector<Process> &processes, int quantum)
{
    queue<Process> processQueue;
    for (const auto &process : processes)
    {
        processQueue.push(process);
    }
    int currentTime = 0;
    while (!processQueue.empty())
    {
        Process currentProcess = processQueue.front();
        processQueue.pop();
        if (currentProcess.remainingTime > quantum)
        {
            currentTime += quantum;
            currentProcess.remainingTime -= quantum;
            processQueue.push(currentProcess);
        }
        else
        {
            currentTime += currentProcess.remainingTime;
            currentProcess.remainingTime = 0;
            cout << "Process " << currentProcess.id << " completed at time " << currentTime << endl;
        }
    }
}
int main()
{
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    vector<Process> processes(numProcesses);
    for (int i = 0; i < numProcesses; ++i)
    {
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].id = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }
    int quantum;
    cout << "Enter the time quantum: ";
    cin >> quantum;
    roundRobinScheduling(processes, quantum);
    return 0;
}

