#include <stdio.h>
#include <stdlib.h>
struct Employee {
    char name[50];
    char department[50];
    int eid;
    float sal;
    int age;
};
void writeData() {
    FILE *file = fopen("Emp.txt", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    struct Employee emp;
    printf("Enter Name: ");
    scanf("%s", emp.name);
    printf("Enter Department: ");
    scanf("%s", emp.department);
    printf("Enter Eid: ");
    scanf("%d", &emp.eid);
    printf("Enter Salary: ");
    scanf("%f", &emp.sal);
    printf("Enter Age: ");
    scanf("%d", &emp.age);
    fwrite(&emp, sizeof(struct Employee), 1, file);
    fclose(file);
}
void readData() {
    FILE *file = fopen("Emp.txt", "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    struct Employee emp;
    while (fread(&emp, sizeof(struct Employee), 1, file)) {
    	printf("\n");
        printf("Name: %s\n", emp.name);
        printf("Department: %s\n", emp.department);
        printf("Eid: %d\n", emp.eid);
        printf("Salary: %.2f\n", emp.sal);
        printf("Age: %d\n", emp.age);
        printf("\n");
    }
    fclose(file);
}
int main() {
    writeData();
    readData();
    return 0;
}

