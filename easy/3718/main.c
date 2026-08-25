int CMP (const void *a, const void *b) {
    return *(int*) a - *(int*)b;
}

int missingMultiple(int* nums, int numsSize, int k) {
    int min = k;

    qsort(nums, numsSize, sizeof(int), CMP);

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == min) {
            min += k;
        }
    }
    
    return min;
}