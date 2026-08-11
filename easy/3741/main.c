int minimumDistance(int* nums, int numsSize) {
    int n = numsSize;
    if (n < 3) return -1;
    int min = INT_MAX;
    int *hash = (int*) malloc((n+1)*sizeof(int));
    memset(hash, 0, (n+1)*sizeof(int));

    for (int i = 0; i < n; i++) {
        hash[nums[i]]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (hash[nums[i]] > 2) {
            int target = nums[i];
            int pick = nums[i];
            for (int j = i+1; j<n; j++) {
                if (target == nums[j]) {
                    pick ^= target;
                    if (pick == target) {
                        min = fmin(min, (j-i)*2);
                        break;
                    }
                }
            }
            hash[nums[i]]--;
        }
    }
    
    free(hash);
    
    return min == INT_MAX ? -1 : min;

}