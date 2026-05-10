int DFS (int* nums, int n, int target, int* dp, int index) {
    if (index == n-1) return 0;
    if (dp[index] != INT_MIN) return dp[index];
    // count max jump times 
    int ret = INT_MIN;
    for (int next = index + 1; next < n; next++) {
        if (fabs(nums[next] - nums[index]) <= target) {
            ret = fmax(ret, 
                    DFS(nums, n, target, dp, next) + 1);
        }
    }
    dp[index] = ret;
    return ret;
}

int maximumJumps(int* nums, int numsSize, int target) {
    int *dp = (int*)malloc(numsSize*sizeof(int));
    for (int i = 0; i < numsSize; i++) dp[i] = INT_MIN;

    int index = 0;
    int ret = DFS(nums, numsSize, target, dp, index);
    free(dp);

    // ret add 1 at the least.
    return ret < 0 ? -1 : ret;

}
