#define UNVISITED INT_MIN
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a > b) ? b : a; }

int topDown(
  int* nums1, 
  int nums1Size, 
  int i,
  int* nums2, 
  int nums2Size,
  int j,
  int** dp
  ) {

  if (i == nums1Size || j == nums2Size) return 0;
  if (dp[i][j] != UNVISITED) return dp[i][j];
  int useCurrProd = nums1[i] * nums2[j] + topDown(nums1, nums1Size, i + 1, nums2, nums2Size, j + 1, dp); // if out of range, add zero

  // 3 options: use current product, skip nums1[i], and skip nums2[j]
  dp[i][j] = max(
    useCurrProd,
    max(
       topDown(nums1, nums1Size, i + 1, nums2, nums2Size, j, dp), 
       topDown(nums1, nums1Size, i, nums2, nums2Size, j + 1, dp)
       )
    );

  return dp[i][j];
}

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int **dp = (int **) malloc( (nums1Size + 1) * sizeof(int *));
  // If all of values in num[] are skipped, the minimum dot product is zero.
  // It needs to consider special case, if either array has all negative or all positive numbers
  int nums1Max = INT_MIN;
  int nums2Max = INT_MIN;
  int nums1Min = INT_MAX;
  int nums2Min = INT_MAX;

  for (int i = 0; i < nums1Size; i++) {
    nums1Max = max(nums1Max, nums1[i]);
    nums1Min = min(nums1Min, nums1[i]);
  }

  for (int i = 0; i < nums2Size; i++) {
    nums2Max = max(nums2Max, nums2[i]);
    nums2Min = min(nums2Min, nums2[i]);
  }

  // nums1 all positive and nums2 all negative
  if (nums1Min >= 0 && nums2Max < 0) return nums1Min * nums2Max;
  // nums1 all negative and nums2 all positive
  else if (nums1Max < 0 && nums2Min >= 0) return nums1Max * nums2Min;

  // Start DP table to get max dot product
  for (int i = 0; i < nums1Size; i++) {
    dp[i] = (int*) calloc(nums2Size + 1, sizeof(int));
    for (int j = 0; j < nums2Size; j++) {
      dp[i][j] = UNVISITED;
    }
  }
    
  return topDown(nums1, nums1Size, 0, nums2, nums2Size, 0, dp);

}
