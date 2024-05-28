#include <stdio.h>

int equalSubstring(char* s, char* t, int maxCost) {
 int ret = 0;
 int sIndex = 0;
 int currCost = 0;
 int len = strlen(s);
 int tmp;

 for (int i = 0; i < len; i++) {
  tmp = s[i] - t[i];
  currCost += tmp < 0 ? ~tmp + 0x1 : tmp;

  // remove previous cost
  while (currCost > maxCost && sIndex <= i) {
   tmp = s[sIndex] - t[sIndex];
   currCost -= tmp < 0 ? ~tmp + 0x1 : tmp;
   sIndex++;
  }

  tmp = i - (sIndex - 1);
  if (ret < tmp) ret = tmp;

 }

 return ret;
    
}

int main (void) {
 
 return 0;
}
