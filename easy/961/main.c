// Permutation problem
// n+1 unique numbers
// numsSize == 2n
// How far is the repeated number between itself?
// Think the color balls
// n different colors balls and n balls with same color
// The balls are placed each other. One color ball is placed between two same color balls.
// 4 balls group together, there are 2 same color balls if we can grap a group each time.
int repeatedNTimes(int* nums, int numsSize) {
  for (int bar = 1; bar <= 3; bar++) {
    for (int i = 0; i < numsSize - bar; i++) {
      if (nums[i] == nums[i + bar]) return nums[i];
    }
  }

  return -1;
}
