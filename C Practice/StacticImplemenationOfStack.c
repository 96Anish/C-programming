#include<stdio.h>
void push();
void pop();
void display();
int stack[10];
int top =-1;
int main()
{
	int choice;
	do
	{
		printf("\n\t======Enter the Choice======");
		printf("\n\tPress 1 for push\n\tPress 2 for pop\n\tPress 3 for display\n\tPress 4 for exit"
		);
		printf("\n\n\tYour choice is: ");
		scanf("%d",&choice);
		if(choice==1)
			push();
		if(choice==2)
			pop();
		if(choice==3)
			display();
		if(choice==4)
			break;
	}while(choice>=1 && choice<=3 );
}
void push(){
	if(top>=9)
	{
		printf("\n\tStack is overflow");
		return;
	}
	top++;
	printf("\n\tInsert the data:");
	scanf("%d",&stack[top]);	
}
void pop()
{
	int d;
	if(top==-1)
		printf("\n\tStack is overflow");
	d=stack[top];
	top--;
	printf("\n\tDeleted element is %d",d);
}
void display()
{
	int i =top; 
	printf("\n\t======Display the Data======");
	while(i>=0)
	{
	
		printf("\n\tInserted data is:%d",stack[i]);
		i--;
	}
}
