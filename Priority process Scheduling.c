#include <stdio.h>

struct process {
    int pid;    // Process ID
    int burst;  // Burst Time
    int wait;   // Waiting Time
    int turn;   // Turnaround Time
    int priority; // Priority
};

struct process temp, a[10];

int main() {
    int i, j, n;

    // Input the number of processes
    printf("ENTER THE TOTAL NUMBER OF PROCESSES: ");
    scanf("%d", &n);

    // Input burst time and priority, assign process IDs
    for (i = 0; i < n; i++) {
        printf("ENTER BURST TIME FOR PROCESS P-%d: ", i);
        scanf("%d", &a[i].burst);
        printf("ENTER PRIORITY FOR PROCESS P-%d: ", i);
        scanf("%d", &a[i].priority);
        a[i].pid = i;  // Assign process ID
    }

    // Sorting processes by priority (ascending order)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j].priority > a[j + 1].priority) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Calculate waiting and turnaround times
    a[0].wait = 0;                 // First process has no waiting time
    a[0].turn = a[0].burst;        // Turnaround time = burst time for first process
    for (i = 1; i < n; i++) {
        a[i].wait = a[i - 1].turn;             // Waiting time = Turnaround time of previous process
        a[i].turn = a[i].burst + a[i].wait;    // Turnaround time = Burst time + Waiting time
    }

    // Print process details
    printf("\nPROCESS ID\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("P-%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a[i].pid, a[i].priority, a[i].burst, a[i].wait, a[i].turn);
    }

    // Calculate average waiting time and turnaround time
    float total_wait = 0, total_turn = 0;
    for (i = 0; i < n; i++) {
        total_wait += a[i].wait;
        total_turn += a[i].turn;
    }

    printf("\nAVERAGE WAITING TIME: %.2f\n", total_wait / n);
    printf("AVERAGE TURNAROUND TIME: %.2f\n", total_turn / n);

    return 0;
}
