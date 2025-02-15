#include <stdio.h>
void main(){
    int i, j, n;
    float wAvg = 0, tAvg = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    
    int pid[n], bt[n], wt[n], tT[n];

    printf("Enter the Burst time of each Process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        pid[i] = i + 1;  
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  
        wAvg += wt[i];  
    }

    for(i = 0; i < n; i++) {
        tT[i] = wt[i] + bt[i];  
        tAvg += tT[i];  
    }

    printf("\nProcess ID   Burst Time   Waiting Time   Turnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tT[i]);
    }

    printf("\nAverage Turnaround Time = %f\n", tAvg / n);
    printf("Average Waiting Time = %f\n", wAvg / n);

    int temp = 0;
    printf("\n=====================================================================\n");
    printf("Gantt Chart:\n");
    printf("\t");
    for(i = 0; i < n; i++) {
        printf("--------");
    }
    printf("\n\t|");
    for(i = 0; i < n; i++) {
        printf(" P[%d]  |", pid[i]);
    }
    printf("\n\t");
    for(i = 0; i < n; i++) {
        printf("--------");
    }

    printf("\n\t0");
    for(i = 0; i < n; i++) {
        temp = temp + bt[i];
        printf("\t%d", temp);
    }
    printf("\n");
}
