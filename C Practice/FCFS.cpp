#include <stdio.h>
void FCFS_scheduling(char processes[][10], int arrival_times[], int burst_times[], int n) {
    int start_times[n], completion_times[n], turnaround_times[n], waiting_times[n];
    start_times[0] = arrival_times[0];
    completion_times[0] = start_times[0] + burst_times[0];
    for (int i = 1; i < n; i++) {
        start_times[i] = (arrival_times[i] > completion_times[i - 1]) ? arrival_times[i] : completion_times[i - 1];
        completion_times[i] = start_times[i] + burst_times[i];
    }
    for (int i = 0; i < n; i++) {
        turnaround_times[i] = completion_times[i] - arrival_times[i];
        waiting_times[i] = turnaround_times[i] - burst_times[i];
    }
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        avg_turnaround_time += turnaround_times[i];
        avg_waiting_time += waiting_times[i];
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;
    printf("\nProcess\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], arrival_times[i], burst_times[i], start_times[i], completion_times[i], turnaround_times[i], waiting_times[i]);
    }
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    char processes[n][10];
    int arrival_times[n], burst_times[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Process %d ID (max 9 characters): ", i + 1);
        scanf("%9s", processes[i]);
        printf("Enter Arrival Time of Process %s: ", processes[i]);
        scanf("%d", &arrival_times[i]);
        printf("Enter Burst Time of Process %s: ", processes[i]);
        scanf("%d", &burst_times[i]);
    }
    FCFS_scheduling(processes, arrival_times, burst_times, n);
    return 0;
}
