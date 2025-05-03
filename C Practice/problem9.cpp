#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,TST, head, total_seek_time = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk requests (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);
    printf("Order of servicing requests:\n");
    for (int i = 0; i < n; i++) {
        int distance = abs(requests[i] - head);
        total_seek_time += distance; 
        printf("Servicing track %d, Seek distance = %d\n", requests[i], distance);
        head = requests[i]; 
    }

    printf("Total seek time: %d\n", total_seek_time);
	printf("Average seek time:%2f\n",(float)TST/n);
    return 0;
}
