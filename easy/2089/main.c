int CMP(const void *a, const void *b) {
    return *(int*) a - *(int*) b;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    int *ret = (int*) malloc(sizeof(int) * numsSize);
    int cnt = 0;
    qsort(nums, numsSize, sizeof(int), CMP);
    
    for (int i = 0; i < numsSize; i++) {
        if(target == nums[i])
            ret[cnt++] = i;
    }

    if(cnt)
    {
        int *tmp = realloc(ret, cnt*sizeof(int));
        if (tmp)
            ret = tmp;
    } else {
        free(ret);
        ret = NULL;
    }
    *returnSize = cnt;
    return ret;
}