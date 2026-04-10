int minimumDistance(int* nums, int numsSize) {
    int n = numsSize;
    if (n < 3) return -1;
    int min = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (nums[i] != nums[j]) continue;
            for (int k = j+1; k < n; k++) {
                if (nums[j] != nums[k]) continue;
                min = fmin(min, k-i + k-j + j-i);
                j = n;
                break;
            }
        }
    }
    
    return min == INT_MAX ? -1 : min;

}