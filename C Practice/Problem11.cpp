#include<stdio.h>
int main(){
	int pn,bn,i,j,frag,f;
	printf("Enter the number of process: ");
	scanf("%d",&pn);
	printf("Enter the number of blocks: ");
	scanf("%d",&bn);
	int ps[pn],bs[bn];
	printf("Enter the size of process:\n");
	for(i=0;i<pn;i++){
		printf("Size of %d process:",i+1);
		scanf("%d",&ps[i]);
	}
	printf("Enter the size of blocks:\n");
	for(i=0;i<bn;i++){
		printf("Size of %d block: ",i+1);
		scanf("%d",&bs[i]);
	}
		printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\tFragment\n");
	for(i=0;i<pn;i++){
		f=0;
		frag=0;
		for(j=0;j<bn;j++){
			if(ps[i]<=bs[j]){
				frag=bs[j]-ps[i];
				f=1;
				break;
			}
		}
		if(f==1){
			printf("\n");
			printf("P%d\t\t%d\t\tB%d\t\t%d\t\t%d",i+1,ps[i],j+1,bs[j],frag);
			bs[j]=frag;
		}
		if(f==0){
			printf("\n");
			printf("P%d\t\t%d\t\t",i+1,ps[i]);
			printf("Not Allocated\t-\t\t-");
			bs[j]=frag;
		}
	}
}
