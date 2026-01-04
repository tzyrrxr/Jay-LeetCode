int sumFourDivisors(int* nums, int numsSize) {
  int total = 0;
  int n = numsSize;
  for (int i = 0; i < n; i++) {
    int divisorCnt = 0;
    int divisorSum = 0;
    for (int divisor = 2; divisor*divisor <= nums[i]; divisor++) {
      if (nums[i] % divisor == 0) {
        divisorCnt++;
        if (divisor*divisor != nums[i]) {
          divisorCnt++;
          divisorSum += divisor + nums[i]/divisor;
        }

      }
      if (divisorCnt > 2) break;
    }
    if (divisorCnt == 2) {
      total += (divisorSum + 1 + nums[i]);
    }
     
  }
    
  return total;
}
