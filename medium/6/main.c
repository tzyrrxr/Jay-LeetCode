#include <string.h>

/*
 * suppose that numRows = 4, strlen(s) = 10
 *
 * 0    6 
 * 1  5 7   11
 * 2 4  8 10
 * 3    9     
 *
 * 0-6 = 6, numRows + (numRows-2)
 * (1-5 = 4; 5-7 = 2;) 4+2=6
 * (2-4 = 2; 4-8 = 4;) 2+4=6
 * 3-9 = 6
 *
 */

char* convert(char* s, int numRows) {
  int len = strlen(s);
  int r = numRows;

  char* ret = (char*) malloc((len+1)*sizeof(char));
  int retPt = 0;
  int pt = 0;
  int gap = 2*r - 2; // bar |
  int mid = 0; // diagonal

  if (len <= r || r == 1) {
    strncpy (ret, s, len);
    ret[len] = '\0';
    return ret;
  }

  for (int row = 0; row < r; row++) { // | | |
    for (int i = row; i < len; i+=gap) { // ----
      ret[retPt++] = s[i];
      mid = i + gap - 2*row;
      if (mid < len && row > 0 && row < r-1) {
        ret[retPt++] = s[mid];
      }
    }
  }

  ret[len] = '\0';
  return ret;
}
