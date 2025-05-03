#include <stdio.h>
#define MAX 10 
int main() {
    int matrix[MAX][MAX];
    int n, m; 
    int isIdentity = 1;
    printf("Enter the number of rows and columns of the matrix (n m): ");
    scanf("%d %d", &n, &m);
    if (n != m) {
        printf("The matrix is not square, hence it cannot be an identity matrix.\n");
        return 0;
    }
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
    
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
               
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if (!isIdentity) {
            break;
        }
    }
    if (isIdentity) {
        printf("The matrix is an identity matrix.\n");
    } else {
        printf("The matrix is not an identity matrix.\n");
    }
    return 0;
}
