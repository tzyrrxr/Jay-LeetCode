int CMP (const void* a, const void* b) {
    return *(int*) a - *(int*)b;
}

bool isGood(int* nums, int numsSize) {
    if (numsSize <= 1) return false;
    qsort(nums, numsSize, sizeof(int), CMP);
    int i = 0;
    while(i < numsSize-2) {
        if (i != nums[i]-1) {
            return false;
        }
        i++;
    }

    if (i != numsSize-1) return 0;
    
    return nums[numsSize-1] == nums[numsSize-2] ? true : false;
}
