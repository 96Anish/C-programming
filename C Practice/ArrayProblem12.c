#include <stdio.h>

void mergeSortedArrays(int A[], int sizeA, int B[], int sizeB, int C[]) {
    int i = 0, j = 0, k = 0;
    
    // Merge both arrays until one is exhausted
    while (i < sizeA && j < sizeB) {
        if (A[i] < B[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    
    // Copy remaining elements of A, if any
    while (i < sizeA) {
        C[k++] = A[i++];
    }
    
    // Copy remaining elements of B, if any
    while (j < sizeB) {
        C[k++] = B[j++];
    }
}

int main() {
	int i;
    int A[] = {1, 3, 5, 7, 9, 11};
    int B[] = {2, 4, 6, 8, 10, 12, 14};
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);
    int C[sizeA + sizeB];
    
    // Merge A and B into C
    mergeSortedArrays(A, sizeA, B, sizeB, C);
    
    // Display merged sorted array
    printf("Merged Sorted Array: ");
    for (i = 0; i < sizeA + sizeB; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");
    
    return 0;
}

