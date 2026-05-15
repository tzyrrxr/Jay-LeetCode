// binary search TC: O(logN)
int findMin(int* nums, int numsSize) {
    int n = numsSize;
    if (n == 1) return nums[0];
    int left = 0;
    int right = n-1;

    if (nums[left] <= nums[right]) return nums[0];

    while (left <= right) {
        int mid = (left + right) >> 1;

        if (mid > 0 && nums[mid] < nums[mid-1]) {
            return nums[mid];
        }
        if (nums[mid+1] < nums[mid]) {
            return nums[mid+1];
        }

        if (nums[mid] > nums[0]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

    }

    return -1;
}
