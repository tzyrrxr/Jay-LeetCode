char nextGreatestLetter(char* letters, int lettersSize, char target) {
  char res = *letters;
  char *a = letters;
  int l = 0;
  int r = lettersSize - 1;

  // binary search
  while (l <= r) {
    int m = (l + r) >> 1;
    if (a[m] > target) {
       res = a[m];
       r = m - 1;
    } else {
       l = m + 1;
    }
  }

  return res;
}
