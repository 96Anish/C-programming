#include<stdio.h>
int main(){
    // FILE* ptr=fopen("anish.txt","r");
    // char str[100];
    // while(fgets(str,40,ptr)!=NULL)
    // {
    //     printf("%s",str);
    // }
    FILE* ptr=fopen("mishra.txt","w");
    char str[]="File Handlinging to mere ko samjh aa hi gya ";
    fputs(str,ptr);
    //fclose(ptr);
    fclose(ptr);
}