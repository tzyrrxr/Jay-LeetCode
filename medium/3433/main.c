#include <stdio.h> 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countMentions(int numberOfUsers, char*** events, int eventsSize, int* eventsColSize, int* returnSize) {
 int *memtions = (int*) calloc(numberOfUsers, sizeof(int));
  *returnSize = numberOfUsers;
    
}
