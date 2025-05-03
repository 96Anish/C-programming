#include<stdio.h>
int main()
{
	int a[20],i,sum=0;float avg;
	printf("Enter the 10 numbers :");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<=9;i++)
	{
		sum=sum+a[i];
	}	
	avg=sum/10.0;
	printf("Average is %d",avg);
	printf("\n");
	return 0;
}
