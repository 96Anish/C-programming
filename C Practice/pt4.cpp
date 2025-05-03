#include <stdio.h>
#define MAX_SIZE 100 
int main() {
    int arr[MAX_SIZE], freq[MAX_SIZE];
    int n, i, j, count;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }
    for (i = 0; i < n; i++) {
        count = 1; 
        if (freq[i] == -1) {
            for (j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0; 
                }
            }
            freq[i] = count;
        }
    }
    printf("Unique numbers are: ");
    for (i = 0; i < n; i++) {
        if (freq[i] == 1) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    printf("Duplicate numbers are: ");
    for (i = 0; i < n; i++) {
        if (freq[i] > 1) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    printf("Occurrence of each number are:\n");
    for (i = 0; i < n; i++) {
        if (freq[i] != -1) { 
            printf("%d : %d\n", arr[i], freq[i]);
        }
    }
    return 0;
}
