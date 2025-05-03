#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    switch (open) {
        case '(': return close == ')';
        case '{': return close == '}';
        case '[': return close == ']';
        default: return 0;
    }
}

int checkBalanced(char* expr) 
{
	int i;
    for(i = 0; expr[i] != '\0'; i++) 
	{
        switch (expr[i]) {
            case '(':
            case '{':
            case '[':
                push(expr[i]);
                break;

            case ')':
            case '}':
            case ']':
                if (top == -1 || !isMatchingPair(pop(), expr[i])) {
                    return 0;
                }
                break;
        }
    }
    return top == -1;
}

int main() {
    char expr[] = "[A+{B*C-(D/{+F}+K]}";

    if (checkBalanced(expr)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is NOT balanced.\n");
    }

    return 0;
}
