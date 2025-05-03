#include<stdio.h>
int main()
{
	int i,j,k,n=5;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==0 || i==n-1 || j==0 || j==n-1){
				printf("S");
			}
			else{
				printf(" ");
			}
			
		}
	 printf("\n");  	
	}
}
