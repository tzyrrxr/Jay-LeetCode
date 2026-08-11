/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int max = 6 * n;
    int *ret = (int *) malloc(max*sizeof(int));
    int pt = max-1;

    for (int i = n-1; i >= 0; i--) {
        int num = nums[i];
        if (num == 0) {
            ret[pt--] = 0;
        } else {
            while(num > 0) {
                ret[pt--] = num%10;
                num /= 10;
            }
        }
    }

    *returnSize = max -1 - pt;
    int *ret2 = (int*) malloc(*returnSize*sizeof(int));
    memcpy(ret2, ret+pt+1, *returnSize*sizeof(int));
    free(ret);

    return ret2;
    
}
