#include <stdio.h>

struct process {
    int pid;    // Process ID
    int burst;  // Burst Time
    int wait;   // Waiting Time
    int turn;   // Turnaround Time
    int priority; //Priority order
};

struct process temp, a[10];
int main()
{
    
    int i, j, n;

    // Input the number of processes
    printf("ENTER THE TOTAL NO. OF PROCESS: ");
    scanf("%d", &n);

    // Input burst time and assign process IDs
    for (i = 0; i < n; i++) {
        printf("ENTER BURST TIME OF P-%d: ", i);
        scanf("%d", &a[i].burst);
        a[i].pid = i;  // Assign process ID
        printf("ENTER PRIORITY OF P-%d: ", i); //Assign Priority order
        scanf("%d", &a[i].priority);
    }

    // Sorting processes by priority order (Priority Scheduling)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (a[j].priority > a[j + 1].priority) 
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Calculate waiting and turnaround times
    a[0].wait = 0;                // First process has no waiting time
    a[0].turn = a[0].burst;       // Turnaround time = burst time for first process
    for (i = 1; i < n; i++) 
    {
        a[i].wait = a[i-1].turn;               // Waiting time = Turnaround time of previous process
        a[i].turn = a[i].burst + a[i].wait;     // Turnaround time = Burst time + Waiting time
    }


    printf("\nPROCESS ID\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("P-%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a[i].pid, a[i].priority,a[i].burst, a[i].wait, a[i].turn);
    }

}
