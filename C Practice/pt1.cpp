#include <stdio.h>
void rearrangeArray(int arr[], int n) {
    int temp[n];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
        
                int tempSwap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempSwap;
            }
        }
    }

    int left = 0;
    int right = n - 1;
    int index = 0;

    while (left <= right) {
        if (index % 2 == 0) {
            temp[index++] = arr[left++]; 
        } else {
            temp[index++] = arr[right--];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    rearrangeArray(arr, n);

    printf("Rearranged array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
