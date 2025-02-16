#include <stdio.h>

void main() {
    int i, j, n;
    float wAvg = 0, tAvg = 0;

    // Input the number of processes
    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], wt[n], tT[n], priority[n];

    // Input burst times and priorities for each process
    printf("Enter the Burst time and Priority of each Process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        pid[i] = i + 1;  // Assign process IDs
    }

    // Sorting based on priority (higher priority = lower priority number)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(priority[i] > priority[j]) {
                // Swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap priority
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate waiting time for each process
    wt[0] = 0;  // First process has no waiting time
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  
        wAvg += wt[i];  // Accumulate waiting times
    }

    // Calculate turnaround time for each process
    for(i = 0; i < n; i++) {
        tT[i] = wt[i] + bt[i];  
        tAvg += tT[i];  // Accumulate turnaround times
    }

    // Display process details (ID, Burst Time, Waiting Time, Turnaround Time)
    printf("\nProcess ID   Burst Time   Waiting Time   Turnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tT[i]);
    }

    // Print average waiting and turnaround times
    printf("\nAverage Turnaround Time = %f\n", tAvg / n);
    printf("Average Waiting Time = %f\n", wAvg / n);

    // Gantt Chart
    int temp = 0;
    printf("\n=====================================================================\n");
    printf("Gantt Chart:\n");
    printf("\t");
    for(i = 0; i < n; i++) {  // Print horizontal lines for Gantt chart
        printf("--------");
    }
    printf("\n\t|");
    for(i = 0; i < n; i++) {  // Print process IDs for the Gantt chart
        printf(" P[%d]  |", pid[i]);
    }
    printf("\n\t");
    for(i = 0; i < n; i++) {  // Print horizontal lines again
        printf("--------");
    }

    printf("\n\t0");
    for(i = 0; i < n; i++) {  // Print time intervals for the Gantt chart
        temp = temp + bt[i];
        printf("\t%d", temp);
    }
    printf("\n");
}
