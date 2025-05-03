#include <stdio.h>
#include <stdlib.h>
void sstf(int requests[], int n, int head) {
    int total_seek_time = 0;
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("Seek sequence: %d", head);
    for (int i = 0; i < n; i++) {
        int min_distance = __INT_MAX__;
        int next_request = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = abs(requests[j] - head);
                if (distance < min_distance) {
                    min_distance = distance;
                    next_request = j;
                }
            }
        }
        visited[next_request] = 1;
        total_seek_time += min_distance;
        head = requests[next_request];
        printf(" -> %d", head);
    }
    printf("\nTotal seek time: %d\n", total_seek_time);
    printf("Average seek time: %.2f\n", (float)total_seek_time / n);
}
int main() {
    int n, head;
    printf("Enter the number of disk I/O requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk I/O requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);
    sstf(requests, n, head);
    return 0;
}

