#include<stdio.h>
int evenOdd(int n);
int main()
{
	int a;
	printf("\n\tEnter a number:");
	scanf("%d",&a);
	if(evenOdd(a))
		printf("\n\tEven");
	else
	{
		printf("\n\tOdd");
	}
}
int evenOdd(int n)
{
	return n%2;
}
