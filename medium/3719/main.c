#define MAX_LEN 100001

int longestBalanced(int* nums, int numsSize) {
  int n = numsSize;
  int visited[MAX_LEN] = {0};
  int maxLen = 0;

  for (int i = 0; i < n; i++) {
    int ueven = 0;
    int uodd = 0;
    memset(visited, 0, sizeof(visited));
    for (int j = i; j < n; j++) {
      int val = nums[j];
      if (visited[val] == 0) {
        if (val & 1) {
          uodd++;
        }else {
          ueven++;
        }
        visited[val]++;
      }

      if (uodd == ueven) {
        maxLen = fmax(maxLen, j-i+1);
      }

    }
  }

  return maxLen;
}
