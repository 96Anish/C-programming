#include<stdio.h>
int sum(int a,int b)
{
	int c;
	return c=a+b;
}
int sub(int a,int b)
{
	int c;
	return c=a-b;
}
int mult(int a,int b)
{
	int c;
	return c=a*b;
}
int div(int a,int b)
{
	int c;
	return c=a/b;
}
int main()
{
	system("color F0");
	int num1,num2;
	printf("Enter the two number :");
	scanf("%d%d",&num1,&num2);
	printf("%d \n",sum(num1,num2));
	printf("%d \n",sub(num1,num2));
	printf("%d \n",mult(num1,num2));
	printf("%d \n",div(num1,num2));
	
}
