bool isTrionic(int* nums, int numsSize) {
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

}
