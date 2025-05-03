#include <stdio.h>
#define MAX_BLOCKS 100
#define MAX_PROCESSES 100
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[MAX_PROCESSES]; 
    int fragmentation[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1; 
        fragmentation[i] = 0; 
    }
    for (int i = 0; i < n; i++) {
        int bestIdx = -1; 
        for (int j = 0; j < m; j++) {
          
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            fragmentation[i] = blockSize[bestIdx] - processSize[i]; 
            blockSize[bestIdx] -= processSize[i]; 
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size \tFragmentation\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, processSize[i], allocation[i] + 1, blockSize[allocation[i]], fragmentation[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
        }
    }
    int totalFragmentation = 0;
    for (int i = 0; i < n; i++) {
        totalFragmentation += fragmentation[i];
    }
    printf("\nTotal Fragmentation: %d\n", totalFragmentation);
}
int main() {
    int blockSize[MAX_BLOCKS], processSize[MAX_PROCESSES];
    int m, n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the sizes of the memory blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    bestFit(blockSize, m, processSize, n);
    return 0;
}
