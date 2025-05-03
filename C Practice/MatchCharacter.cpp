#include <stdio.h>
#include <string.h>

int FirstMatch(const char *str1, const char *str2) {
    
    for (int i = 0; str1[i] != '\0'; i++) {
       
        for (int j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                return i; 
            }
        }
    }
    return -1; 
}

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; 
    
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;
    
    int index = FirstMatch(str1, str2);

   
    if (index != -1) {
        printf("The first matching character is at index: %d\n", index);
    } else {
        printf("No matching character found.\n");
    }

    return 0;
}
