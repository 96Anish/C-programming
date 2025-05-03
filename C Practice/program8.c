#include <stdio.h>
#include <stdlib.h>
#define MAX_PAGES 100
void printTable(int pages[], int n, int page_faults, int page_hits) {
	int i;
    printf("\nPage Reference String:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n\nPage Faults: %d\n", page_faults);
    printf("Page Hits: %d\n", page_hits);
//    printf("Page Fault Rate: %.2f%%\n", (float)page_faults / n * 100);
}
void LRU(int pages[], int n, int frame_size) 
{
	int i,j;
    int memory[MAX_PAGES];
    int page_faults = 0, page_hits = 0;
    int page_index = 0;
    for (i = 0; i < frame_size; i++) 
	{
        memory[i] = -1;
    }
    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        for (j = 0; j < frame_size; j++) {
            if (memory[j] == page) {
                found = 1;
                page_hits++;
                break;
            }
        }
        if (!found) {
            page_faults++;
            int empty_frame = -1;
            for (j = 0; j < frame_size; j++) {
                if (memory[j] == -1) {
                    empty_frame = j;
                    break;
                }
            }
            if (empty_frame != -1) {
                memory[empty_frame] = page;
            } else {
                int lru_index = 0;
                for (j = 1; j < frame_size; j++) {
                    if (memory[j] < memory[lru_index]) {
                        lru_index = j;
                    }
                }
                memory[lru_index] = page; 
            }
        }
        printf("\nCurrent Memory State after accessing page %d:\n", page);
        printf("Frame\tPage\n");
        for (j = 0; j < frame_size; j++) {
            printf("%d\t%d\n", j + 1, memory[j]);
        }
    }
    printTable(pages, n, page_faults, page_hits);
}
int main() {
    int i, n, frame_size;
    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page reference string (space-separated): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frame_size);
    LRU(pages, n, frame_size);
    return 0;
}
