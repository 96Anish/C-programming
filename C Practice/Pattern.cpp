#include<stdio.h>
int main()
{
	int i,j;
	int n=10;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("9");
		}
		printf("Anish ");
		for(j=n-i;j>=1;j--)
		{
			printf("6 ");
		}
		printf("\n");
	}
	
}
