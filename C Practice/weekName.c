#include<stdio.h>
int main(){
	int n ,a,b;
	printf("Enter the Operation no:");
	scanf("%d",&n);
	printf("Enter the first number " );
	scanf("%d",&a);
	printf("Enter the second number ");
	scanf("%d",&b);
	switch(n){
		case 1:
			//printf("Sunday");
			printf("Sum %d",a+b);
			break;
		case 2:
			printf("MONday");
			break;
			
		case 3:
			printf("Tuesday");
			break;
		case 4:
			printf("Friday");
			break;
		default:
		    printf("Invalid option");
	}
}
