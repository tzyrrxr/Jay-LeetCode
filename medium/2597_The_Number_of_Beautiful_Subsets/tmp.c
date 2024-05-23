int CMP(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

// Recursive function to count beautiful subsets
int Count(int *nums, int len, int diff, int *hash, int index) {
    if (index == len) return 1;
    int totalCount = 0;

    totalCount = Count(nums, len, diff, hash, index + 1); // Mark status

    int exist = nums[index] - diff;
    int val = nums[index];
    if (exist < 0 || hash[exist] == 0) { // Check for out-of-bounds and existence
        hash[val]++;
        totalCount += Count(nums, len, diff, hash, index + 1); // Backtracking
        hash[val]--;
    }

    return totalCount;
}

// Main function to calculate beautiful subsets
int beautifulSubsets(int* nums, int numsSize, int k) {
    int ret = 0;
    int len = numsSize;
    int numsIndex = 0;

    // Find the maximum value in the nums array
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }

    // Allocate hash array with size based on the maximum value
    int *hash = (int *) calloc(maxVal + 1, sizeof(int));
    int diff = k;

    // Sort the nums array
    qsort(nums, len, sizeof(int), CMP);

    // Count beautiful subsets
    ret = Count(nums, numsSize, diff, hash, numsIndex);
    ret--; // Remove the empty subset

    free(hash);

    return ret;
}
