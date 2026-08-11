int missingInteger(int* nums, int numsSize) {
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1] + 1) {
            sum += nums[i];
            continue;
        }
        break;
    }

    bool found = 0;
    while (1) {
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == sum) {
                found = 1;
                break;
            }
        }
        if (found == false) {
            return sum;
        }
        sum++;
        found = false;
    }
}