#include <stdio.h>
#include <stdlib.h>

typedef struct Job
{
    int id;
    int deadline;
    int profit;
} Job;

void jobSequence(Job jobs[], int n)
{
    int i, k, dmax = -1, maxprofit = 0, filledTimeSlot = 0;
    // GETTING MAX DEADLINE, TO CREATE TIMESLOT ARRAY OF LENGTH dmax
    for (i = 0; i < n; i++)
        if (jobs[i].deadline > dmax)
            dmax = jobs[i].deadline;
    // INITIALIZING TIMESLOT ARRAY WITH -1
    int timeslot[dmax];
    for (i = 0; i < dmax; i++)
        timeslot[i] = -1;

    //-----------------------------------------------
    // ACTUAL CODE -- THE SEQUQNCING IS DONE HERE
    for (i = 0; i < n; i++)
    {
        for (k = jobs[i].deadline - 1; k >= 0; k--)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = i;
                filledTimeSlot++;
                break;
            }
        }
        if (filledTimeSlot == dmax)
            break;
    }
    //-----------------------------------------------

    // PRINTING REQUIRED JOBS
    printf("\nRequired Jobs: ");
    for (i = 0; i < dmax; i++)
    {
        printf("%d", jobs[timeslot[i]].id);
        if (i < dmax)
            printf(" --> ");
    }

    // PRINTING MAXIMMUM PROFIT
    maxprofit = 0;
    for (i = 0; i < dmax; i++)
    {
        maxprofit += jobs[timeslot[i]].profit;
    }
    printf("\nMax Profit: %d\n", maxprofit);
}

void main()
{
    int i, j, n = 4;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job givenJobs[n];
    for (i = 0; i < n; i++)
    {
        givenJobs[i].id = i + 1;
        printf("Enter the %d th job's profit: ", i + 1);
        scanf("%d", &givenJobs[i].profit);
        printf("Enter the %d th job's deadline: ", i + 1);
        scanf("%d", &givenJobs[i].deadline);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; ++j)
        {
            if (givenJobs[j].profit < givenJobs[j + 1].profit)
            {
                Job temp = givenJobs[j];
                givenJobs[j] = givenJobs[j + 1];
                givenJobs[j + 1] = temp;
            }
        }
    }
    printf("\nId      :");
    for (i = 0; i < n; i++)
        printf("\t%d", givenJobs[i].id);
    printf("\nDeadline:");
    for (i = 0; i < n; i++)
        printf("\t%d", givenJobs[i].deadline);
    printf("\nProfit  :");
    for (i = 0; i < n; i++)
        printf("\t%d", givenJobs[i].profit);
    jobSequence(givenJobs, n);
}
