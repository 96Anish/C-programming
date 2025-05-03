#include<stdio.h>
int main()
{
	int num;
	printf("\n\t Enter the Number:");
	scanf("%d",&num);
	if(num%2==0)
	{
		printf("\n\tInputted Number is even %d",num);
		
	}
	else
	{
		printf("\n\tInputted Number is Odd %d",num);
	}
	return 0;
}
