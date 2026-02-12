#include <string.h> 

int longestBalanced(char* s) {
  int n = strlen(s);
  int max = 1;
  int *hash = (int*) malloc(26*sizeof(int));

  for (int i = 0; i < n; i++) {
    memset(hash, 0, 26*sizeof(int));
    int pre = s[i] - 'a';

    for (int j = i; j < n; j++) {
      int curr = s[j] - 'a';
      hash[curr]++;

      if (hash[curr] == hash[pre]) {
        int verify = i;
        while (verify <= j && hash[curr] == hash[s[verify++]-'a']);
        if (verify-1 == j) {
          max = fmax(max, j-i+1);
        }
      }
    }
  }
    
  return max;

}
