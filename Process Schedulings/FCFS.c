#include <stdio.h>

int main()
{
    int n, j, i;
    float avgw = 0, avgt = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    printf("Enter the Burst time of each Process:\n");
    int bt[n];
    for(i = 0; i < n; i++) 
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int wt[n], tt[n];
    wt[0] = 0; 

    for(i = 1; i < n; i++) 
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        avgw += wt[i];  
    }

    for(i = 0; i < n; i++) 
    {
        tt[i] = bt[i] + wt[i]; 
        avgt += tt[i]; 
    }

    printf("\nProcess ID   Burst Time   Waiting Time   Turnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tt[i]);
    }

    printf("\nAverage Waiting Time = %f\n", avgw / n);
    printf("Average Turnaround Time = %f\n", avgt / n);

    int temp = 0;
    printf("\n=====================================================================\n");
    printf("Gantt Chart:\n");
    printf("\t");
    for(i = 0; i < n; i++)
    {
        printf("--------");
    }
    printf("\n\t|");
    for(i = 0; i < n; i++) 
    {
        printf(" P[%d]  |", i + 1);
    }
    printf("\n\t");
    for(i = 0; i < n; i++) 
    {
        printf("--------");
    }

    printf("\n\t0");
    for(i = 0; i < n; i++) 
    {
        temp += bt[i];
        printf("\t%d", temp);
    }
    printf("\n");

    return 0;
}
