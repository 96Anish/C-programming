#include<stdio.h>
int push(int[],int*);
int pop(int[],int*);
int display(int[],int) ;
int main()
{
	int stack[10],top=-1;
	int choice;
	do
	{
		printf("\n\tPress 1 for push\n\tPress 2 for pop\n\tPress for display\n\tPress 4 for exit");
		printf("\n\tYour choice is :");
		scanf("%d",&choice);
		printf("\n\t");
		if(choice==1)
			push(stack,&top);
		else if(choice==2)
			pop(stack,&top);
		else if(choice==3)
			display(stack,top);
		else if(choice==4)
			break;
		else
		{
			printf("\n\tNo more option");
		
		}
	}while(choice>=1 && choice<=3);
	
}
int push(int stack[],int *top)
{
	if(*top>=9)
		printf("\n\tSatck is overflow");
	(*top)++;
	printf("\n\tInsert data:");
	scanf("%d",&stack[*top]);
}
int pop(int stack[],int *top)
{
	int d;
	if(*top==-1)
		printf("\n\tStack is underflow");
	d=stack[*top];
	(*top)--;
	printf("\n\tdeleted elements is %d",d);
	printf("\n");
}
int display(int stack[],int top)
{
	int i=top;
	if(top == -1) 
	{
        printf("\n\tStack is empty!");
        return 0;
    }
	while(i>=0)
	//for(i=top;i>=0;i--)
	{
		printf("%d ",stack[i]);
		i--;
	}
}

