char* findDifferentBinaryString(char** nums, int numsSize) {
  int len = strlen(nums[0]);
  char *res = (char*) malloc(len * sizeof(char)+1);
  res[len] = '\0';

  for (int i = 0; i < numsSize; i++) {
    switch (nums[i][i]) {
      case '0':
        res[i] = '1';
        break;
      default:
        res[i] = '0';
        break;
    }
  }

  return res;
    
}
