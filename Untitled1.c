#include<stdio.h>
#include<stdlib.h>
  typedef struct {
	int id;
	int deadline;
	int profit;
} Job;

void jobSequencing(Job jobs[], int n) {
   // qsort(jobs, n, sizeof(Job), cmpfunc);
    int i,j;
    int max_deadline = 0;
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline) {
            max_deadline = jobs[i].deadline;
        }
    }
    
    int slot[max_deadline];
    for ( i = 0; i < max_deadline; i++) {
        slot[i] = -1;
    }
    
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline-1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                break;
            }
        }
    }
    
    printf("Job sequence: ");
    int profit = 0;
    for (i = 0; i < max_deadline; i++) {
        if (slot[i] != -1) {
            printf("%d ", jobs[slot[i]].id);
            profit += jobs[slot[i]].profit;
        }
    }
    printf("\nTotal profit: %d\n", profit);
}

void bubbleSort(Job jobs[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (jobs[j].profit < jobs[j+1].profit) {
                // Swap jobs[j] and jobs[j+1]
                Job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}
int main() {
    int n,i;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    printf("Enter the job details (id, deadline, profit):\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d%d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    // Sort the jobs based on profit
    bubbleSort(jobs, n);

    // Now perform job sequencing
    jobSequencing(jobs, n);
    return 0;
}

