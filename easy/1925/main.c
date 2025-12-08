#include <stdio.h>
#include <math.h>

int countTriples(int n) {
  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int aSqr = i*i;
      int bSqr = j*j;
      int c = (int)sqrt(aSqr + bSqr);
      if (c <= n && c*c == aSqr + bSqr) {
        cnt++;
      }
    }
  }
  
  return cnt;
    
}
