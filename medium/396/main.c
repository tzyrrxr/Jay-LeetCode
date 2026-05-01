/*
 * f(0) = 0 * nums[0] + 1 * nums[1] + ... + (n-1) * nums[n-1]
 * f(1) = 1 * nums[0] + 2 * nums[1] + ... + (0) * nums[n-1]
 *      = 1 * nums[0] + 2 * nums[1] + ... + (n) * nums[n-1] - (n) * nums[n-1]
 *      =(0 * nums[0] + 1 * nums[1] + ... + (n-1) * nums[n-1]) + 1 * (nums[0] + nums[1] + ... + nums[n-1]) - (n) * nums[n-1]
 *      = f(0) + 1 * sum of nums - n* nums[n-1]
 *
 * f(2) = 2 * nums[0] + 3 * nums[1] + ... + (0) * nums[n-2] + (1) * nums[n-1]
 *      = 2 * nums[0] + 3 * nums[1] + ... + (0) * nums[n-2] + (1) * nums[n-1]
 *      = 2 * nums[0] + 3 * nums[1] + ... + (n) * nums[n-2] - (n) * nums[n-2] + (1) * nums[n-1]
 *      = 2 * nums[0] + 3 * nums[1] + ... + (n) * nums[n-2] + (1) * nums[n-1] - (n) * nums[n-2] 
 *      = (1 * nums[0] + 2 * nums[1] + ... + (n-1) * nums[n-2] + (0) * nums[n-1]) + 1 * (nums[0] + ... + nums[n-1]) - (n) * nums[n-2] 
 *      = f(1) + 1 * sum of nums - n * nums[n-2]
 *
 * f(k) = f(k-1) + sum of nums - n * nums[n-k]
 */
int maxRotateFunction(int* nums, int numsSize) {
  if (numsSize <= 1) return 0;
  int n = numsSize;
  int max = INT_MIN;
  int sum = 0;
  int fSum = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    max = fSum += i * nums[i]; // f(0)
  }

  for (int k = 1; k < n; k++) {
    fSum = fSum + sum - n * nums[n-k];
    max = fmax(max, fSum);
  }

  return max;

}
