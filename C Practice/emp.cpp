#include <stdio.h>
#include <stdlib.h>
struct Employee {
    char name[50];
    char dep[50];
    int eid;
    float salary;
};
int main() {
    int N, i;
    struct Employee *emp;
    printf("Enter the number of employees: ");
    scanf("%d", &N);
    emp = (struct Employee *)malloc(N * sizeof(struct Employee));
    for (i = 0; i < N; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Department: ");
        	scanf("%s",emp[i].dep);
        printf("Employee ID: ");
        scanf("%d", &emp[i].eid);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    printf("\n\t\tEmployee Records:\n");
    printf("Employee ID:\tName:\t\tDepartment:\tSalary:");
    for (i = 0; i < N; i++) {
        printf("\n%d\t%s \t\t%s \t%.2f\n",emp[i].eid,emp[i].name, emp[i].dep, emp[i].salary);
    }
    free(emp);
    return 0;}

