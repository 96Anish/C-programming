#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
};
typedef struct stack node;
node *top=NULL;
void push();
void pop();
void display();
void push()
{
	node *p;
	p=(node *)malloc(sizeof (node));
	if(p==NULL)
		printf("\n\t Stack Overflow");
	printf("\n\t Insert the data:");
	scanf("%d",&p->data);
	p->next=top;
	top=p;
}
void pop()
{
	node *p;
	if(top==NULL)
	{
		printf("\n\tStack is Underflow");
	}
	p=top;
	top=top->next;
	free(p);
	printf("\n\tPoped your data");
}
void display()
{
	node *p;
	p=top;
	if(top == NULL) 
	{
        printf("\n\tStack is empty");
        return;
	}
	//node *p = top;
    //printf("\n\tStack elements:");
	while(p!=NULL)
	{
		printf("\n\tInserted data:%d",p->data);
		p=p->next;
	}
}
int main() {
    int ch;
    do {
        printf("\n\t======Choose Option======");
        printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. Exit");
        printf("\n\tYour choice: ");
        scanf("%d", &ch);

        switch (ch) 
		{
            case 1: 
				push(); 
				break;
            case 2: 
				pop(); 
				break;
            case 3:
				 display(); 
				 break;
            case 4: 
				printf("\n\tExiting program..."); 
				break;
            default:
				 printf("\n\tInvalid option, please try again");
        }
    } while (ch != 4);

    return 0;
}
