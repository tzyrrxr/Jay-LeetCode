bool isTrionic(int* nums, int numsSize) {
  /*
  if (numsSize <= 3) return false;
  bool checker = false;
  int i = 1;

  for (int j = 0; j < 3; j++) {
    while (i < numsSize) {
       if ((nums[i-1] < nums[i]) && (j&1) == 0) {
         i++;
         checker = true;
         continue;
       } else if ((nums[i-1] > nums[i]) && (j&1) == 1) {
         i++;
         checker = true;
         continue;
       }
       break;
    }
    if (!checker) return false;
    checker = false;
  }
    
  return i == numsSize ? true: false;
  */

  if (numsSize <= 3) return false;
  if (nums[0] >= nums[1]) return false;
  int cnt = 0;
  for (int i = 2; i < numsSize; i++) {
    if (nums[i] == nums[i-1]) return false;
    if ((nums[i] - nums[i-1]) * (nums[i-1] - nums[i-2]) < 0) cnt++;
  }
  // Does it have two turning points?
  return cnt == 2;

}
