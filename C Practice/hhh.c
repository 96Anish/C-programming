#include <stdio.h>
void arithmetic(int x, int y, int* sum, int* product) {
    *sum = x + y;
    *product = x * y;
}
int main() {
    int a, b, sum, product;
    printf("\n\t Enter the Two numbers: ");
    scanf("%d%d", &a, &b);
    arithmetic(a, b, &sum, &product);
    printf("Sum of two numbers: %d", sum);
    printf("\nMultiplication of two numbers: %d", product);

    return 0;
}

