#include<stdio.h>
int main()
{
	int a;
	a=natural(10);
	printf("%d",a);
}
int natural(int n)
{
	int s=0;
	if(n==1)
		return 1;
	else
	{
		s=s+n;
		return s+natural(n-1);
	}
}
