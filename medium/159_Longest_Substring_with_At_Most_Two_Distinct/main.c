#include <stdio.h>

int lengthOfLongestSubstringTwoDistinct(char* s) {
 if (strlen(s) <= 2) return strlen(s);

 int ht['z' + 1] = {0};
 char stack[2] = {0};
 int prev, curr;
 int ret = 0;
 int n = strlen(s);
 int tmp;
 int i, j;

 prev = s[0];
 curr = s[1];
 stack[0] = prev;
 stack[1] = curr;
 ht[prev]++;
 ht[curr]++;

 for (i = 2; i < n; i++) {
  curr = s[i];
  prev = s[i-1];
  if (stack[0] == stack[1] && s[i] != stack[1]) {
   stack[1] = s[i];
   ht[s[i]]++;
   curr = s[i];
   continue;
  }

  if (s[i] == stack[0] || s[i] == stack[1]) {
   if (s[i] == stack[0]) {
    tmp = stack[0];
    stack[0] = stack[1];
    stack[1] = tmp;
   }
   ht[s[i]]++;
   continue;
  }

  if(curr != prev && s[i] != stack[0] && s[i] != stack[1]) {
   // total score.
   ret = ret < ht[stack[0]] + ht[stack[1]] ? ht[stack[0]] + ht[stack[1]] : ret;
   ht[stack[0]] = 0;
   // calculate the previous character.
   for (j = i-1, ht[prev] = 0; s[j] == prev && j >= 0; ht[prev]++, j--);
   stack[0] = prev;
   stack[1] = curr;
   ht[stack[1]]++;
  } 
  
 }

 if (stack[0] != stack[1]) {
  ret = ret < ht[stack[0]] + ht[stack[1]] ? ht[stack[0]] + ht[stack[1]] : ret;
 } else if (stack[0] == stack[1]) {
  ret = ht[stack[0]];
 }

 return ret;
}

int main (void) {

 return 0;
}
