#include <string.h> 

int longestBalanced(char* s) {
  int n = strlen(s);
  int maxLen = 1;
  int *freq = (int*) malloc(26*sizeof(int));

  for (int i = 0; i < n; i++) {
    memset(freq, 0, 26*sizeof(int));
    int distinct = 0;
    int maxFreq = 0;

    for (int j = i; j < n; j++) {
      int len = j-i+1;
      int curr = s[j] - 'a';

      if (freq[curr] == 0) distinct++;
      freq[curr]++;
      maxFreq = fmax(maxFreq, freq[curr]);


      if (maxFreq * distinct == len && len > maxLen) {
        maxLen = len;
      }

    }
  }
    
  return maxLen;

}
