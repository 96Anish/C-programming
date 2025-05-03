#include<stdio.h>
int main()
{
    int a[3][4],b[4][3],i,j;
    printf("Enter the element of the 3*4 matrix \n");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=3;j++)
        {
            b[i][j]=a[i][j];
        }
    }
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=2;j++)
        {
            printf("%d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}