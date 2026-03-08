char* findDifferentBinaryString(char** nums, int numsSize) {
  int len = strlen(nums[0]);
  int possible = 1 << len; // value from 0 ~ possible - 1
  bool visited[possible];
  char *res = (char*) malloc(len * sizeof(char)+1);
  memset (visited, 0, sizeof(bool)*possible);
  res[len] = '\0';

  for (int i = 0; i < numsSize; i++) {
    int val = 0;
    for (int j = 0; j < len; j++) {
      val = (val << 1) | (nums[i][j] - '0');
    }
    visited[val] = 1;
  }
  int i = 0;
  while (visited[i] == 1) {
    i++;
  }

  int val = i;
  for (int i = len-1; i >= 0; i--) {
    int reminder = val % 2;
    val = val / 2;
    res[i] = reminder + '0';
  }

  return res;
    
}
