#include <stdio.h>

int main() 
{
    printf("\n\tPost increment with pre increment");
    int a=5,b=7;
    int c = a++ + ++b - a++ + a++ - a++ + ++b - a++ + a++ + a++ + ++b - a++ + a++;
    printf("\n\t%d",c);
    return 0;
}
