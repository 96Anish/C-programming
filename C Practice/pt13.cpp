#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024

int countOccurrences(const char *line, const char *substring) {
    int count = 0;
    const char *temp = line;

    while ((temp = strstr(temp, substring)) != NULL) {
        count++;
        temp++;
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <substring>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *substring = argv[2];
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int totalOccurrences = 0;

    while (fgets(line, sizeof(line), file)) {
        totalOccurrences += countOccurrences(line, substring);
    }

    fclose(file);

    printf("The substring '%s' occurred %d times in the file '%s'.\n", substring, totalOccurrences, filename);
    
    return 0;
}
