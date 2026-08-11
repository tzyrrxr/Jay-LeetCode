#include<string.h>

int minimumDeletions(char* s) {
  int *Delete_a = (int*) malloc(strlen(s) * sizeof(int));
  int res = INT_MAX;

  for (int i = strlen(s)-1, a_count = 0; i >= 0; i--) {
    Delete_a[i] = a_count;
    if (s[i] == 'a') a_count++;
  }

  for (int i = 0, b_count = 0; i < strlen(s); i++) {
    res = fmin(Delete_a[i] + b_count, res);
    if (s[i] == 'b') b_count++;
  }
    
  free (Delete_a);

  return res;
}
