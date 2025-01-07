#include <stdio.h>

struct process {
    int pid;    // Process ID
    int burst;  // Burst Time
    int wait;   // Waiting Time
    int turn;   // Turnaround Time
};

int main() {
    int n, i;
    struct process a[10];

    // Input the number of processes
    printf("ENTER THE TOTAL NUMBER OF PROCESSES: ");
    scanf("%d", &n);

    // Input burst time and assign process IDs
    for (i = 0; i < n; i++) {
        printf("ENTER BURST TIME FOR PROCESS P-%d: ", i);
        scanf("%d", &a[i].burst);
        a[i].pid = i;  // Assign process ID
    }

    // Calculate waiting time and turnaround time
    a[0].wait = 0;              // First process has no waiting time
    a[0].turn = a[0].burst;     // Turnaround time = Burst time for first process
    for (i = 1; i < n; i++) {
        a[i].wait = a[i - 1].turn;            // Waiting time = Turnaround time of previous process
        a[i].turn = a[i].burst + a[i].wait;  // Turnaround time = Burst time + Waiting time
    }

    // Display process details
    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("P-%d\t\t%d\t\t%d\t\t%d\n", a[i].pid, a[i].burst, a[i].wait, a[i].turn);
    }

    // Calculate and display average times
    float total_wait = 0, total_turn = 0;
    for (i = 0; i < n; i++) {
        total_wait += a[i].wait;
        total_turn += a[i].turn;
    }
    printf("\nAVERAGE WAITING TIME: %.2f\n", total_wait / n);
    printf("AVERAGE TURNAROUND TIME: %.2f\n", total_turn / n);

    return 0;
}
