#include<stdio.h>
main()
{
	struct anish
	{
		int a;
		char nm;
	};
	struct anish a1;
	a1.a=40;
	a1.nm="Anish";
	printf("%d",a1.a);
	printf("\n");
	printf("%s",a1.nm);
	
}
