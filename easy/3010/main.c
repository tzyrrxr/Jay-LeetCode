// the first number is always included the cost
int minimumCost(int* nums, int numsSize) {
  int min = nums[0];
  int other[2] = {INT_MAX, INT_MAX};
  for (int i = 1; i < numsSize; i++) {
     if (nums[i] < other[0]) {
        other[1] = other[0];
        other[0] = nums[i];
     } else if (nums[i] < other[1]) {
        other[1] = nums[i];
     }
  }
    
  return min + other[0] + other[1];

}
