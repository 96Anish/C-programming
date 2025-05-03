#include<stdio.h>
int main()
{
    int a[3][3],b[3][3],i,j;
    int c[3][3];
    printf("Enter the element of  3*3 matrix \n");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            scanf("%d",&a[i][j]);
            
        }
        printf("\n");
    }
    printf("Enter the element of second 3*3 matrix \n ");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("Multiply of two matrix \n");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}