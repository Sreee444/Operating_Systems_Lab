#include <stdio.h>

int main()
{
    printf("\n\t\tRound Robin Scheduling\n\n");
    int n, i, j, time = 0, tq;
    float avgw = 0, avgt = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("\n");

    int bt[n], wt[n], tt[n], pid[n], rem_bt[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time of process %d : ", i + 1);
        scanf("%d", &bt[i]);
        pid[i] = i + 1;
        rem_bt[i] = bt[i];  
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    while (1)
    {
        int done = 1;
        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = 0;
                if (rem_bt[i] > tq)
                {
                    time += tq;
                    rem_bt[i] -= tq;
                }
                else
                {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    for (i = 0; i < n; i++)
    {
        tt[i] = bt[i] + wt[i];
        avgw += wt[i];
        avgt += tt[i];
    }

    printf("\nProcess ID   Burst Time   Waiting Time   Turnaround Time\n");
    printf("________________________________________________________\n\n");
    for (i = 0; i < n; i++)
    {
        printf("  P[%d]\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tt[i]);
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
