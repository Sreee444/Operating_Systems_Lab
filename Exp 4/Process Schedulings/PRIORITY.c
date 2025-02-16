#include <stdio.h>

int main()
{
    printf("\n\t\tPriority Scheduling\n\n");
    int n, i, j;
    float avgw = 0, avgt = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("\n");

    int bt[n], wt[n], tt[n], pid[n], priority[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time of process %d : ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter the priority of process %d : ", i + 1);
        scanf("%d", &priority[i]);
        pid[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (priority[j] > priority[j + 1])
            {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        avgw += wt[i];
    }

    for (i = 0; i < n; i++)
    {
        tt[i] = bt[i] + wt[i];
        avgt += tt[i];
    }

    printf("\nProcess ID   Burst Time    Priority   \tWaiting Time    Turnaround Time\n");
    printf("____________________________________________________________________\n\n");
    for (i = 0; i < n; i++)
    {
        printf("  P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], priority[i], wt[i], tt[i]);
    }

    printf("\nAverage Waiting Time = %f\n", avgw / n);
    printf("Average Turnaround Time = %f\n", avgt / n);

    int temp = 0;
    printf("\n=========================================================\n");
    printf("Gantt Chart:\n");
    printf("\t");
    for (i = 0; i < n; i++)
    {
        printf("--------");
    }
    printf("\n\t|");
    for (i = 0; i < n; i++)
    {
        printf(" P[%d]  |", pid[i]);
    }
    printf("\n\t");
    for (i = 0; i < n; i++)
    {
        printf("--------");
    }

    printf("\n\t0");
    for (i = 0; i < n; i++)
    {
        temp += bt[i];
        printf("\t%d", temp);
    }
    printf("\n");

    return 0;
}
