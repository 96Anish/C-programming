#include <stdio.h>
int power(int base, int exponent) {
    
    if (exponent == 0) {
        return 1;
    }
    
    return base * power(base, exponent - 1);
}
int main() {
    int base, exponent, result;
    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    result = power(base, exponent);
    printf("%d raised to the power of %d is %d\n", base, exponent, result);
    
    return 0;
}
