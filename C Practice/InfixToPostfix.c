#include<stdio.h>
#include<string.h>
char stack[50];
int top=-1;
void push(char);
char pop();
int preced(char);
int main()
{
	char ch,temp;
	char infix[100],postfix[100];
	int len;
	printf("\n\tEnter the an infix Expression");
	scanf("%s",infix);
	len=strlen(infix);
	infix[len]=')';
	infix[len+1]='\0';
	push('(');
	int i=0,j=0;
	while(infix[i]!=0)
	{
		ch=infix[i];
		if(ch=='(')
		{
			push(ch);
		}
		if(ch>=65 && ch <=90)
			postfix[j++]=ch;
		if(ch==')')
		{
			temp=pop();
			while(temp!='(')
			{
				postfix[j+1]=ch;
				temp=pop();
			}
		}
		if(ch=='+'|| ch=='-'||ch=='*'||ch=='/'||ch=='^')
		{
			while (top >= 0 && preced(stack[top]) >= preced(ch))
			{
				temp=pop();
				postfix[j++]=temp;
			}
			push(ch);
		}
		i++;
	}//end of while
	postfix[j]='\0';
	printf("%s",postfix);
}//end of main
int preced (char c)
{
	if(c=='^')
		return 6;
	if(c=='*')
		return 5;
	if(c=='/')
		return 5;
	if(c=='+')
		return 4;
	if(c=='-')
		return 4;
	return 3;
}
void push(char ch)
{
	if(top>=49)
		return;
	top++;
	stack[top]=ch;
	
}
char pop()
{
	if(top==-1)
	{
		return;
	}
	char ch=stack[top];
	return ch;
}
