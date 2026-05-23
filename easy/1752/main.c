bool check(int* nums, int numsSize) {
    int critical = 0;

    for (int i = 0; i < numsSize; i++) {
        if(nums[i] > nums[(i+1)%numsSize]) {
            critical++;
        }
    }

    if (critical > 1) return false;

    return true;
}
