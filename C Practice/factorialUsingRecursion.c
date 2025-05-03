#include<stdio.h>
int main()
{
	int a =factorial(5);
	printf("%d",a);
}
int factorial(int n)
{
	if(n==1)
		return 1;
	else
	{
		return n*factorial(n-1);
	}
}
