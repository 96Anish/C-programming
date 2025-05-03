#include <stdio.h>
int main() {
    int n, i, j, temp;
    int pid[20], bt[20], wt[20], tat[20];
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;
    printf("Enter the number of processes (max 20): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter Process ID for process %d: ", i + 1);
        scanf("%d", &pid[i]);
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
    wt[0] = 0; 
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
return 0;
}
