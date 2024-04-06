#include <stdio.h>

/*
 * Group of substring types
 * 10, 01, 1100, 0011,
 * 111000, 000111
 * 11110000, 00001111, ...
 */ 
/* Algorithm
 * Example 1: 
 * Input s = "0011". 
 * Its pattern can be represented as [2, 2], indicating that there are 2 distinct types of substrings "01" and "0011".
 *
 * Example 2:
 * Input s = "11100". 
 * Its pattern can be represented as [3, 2], indicating that there are 2 distinct types of substrings "10" and "1100".
 *
 * Example 3:
 * Input s = "001110000".
 * Its pattern can be represented as [2, 3, 4], indicating that there 2 + 3 = 5distinct types of substrings "01", "0011", "10", "1100", and "111000".
 * It can split 2 parts to discuss that the substring of "00111" and "1110000".
 *
 * Example 4:
 * Input s = "11100100011".
 * Its pattern can represented as [3, 2, 1, 3, 2], indicating that there 2 + 1 + 1 + 2 = 6 distinct types of substrings "10", "1100", "01", "10", "01", and "0011".
 * It can split 4 parts to discuss that the substring of "11100", "001", "1000", and "00011".
 *
 * Example 5:
 * Input s = "011100111001".
 * Its pattern can represneted as [1, 3, 2, 3, 2, 1], indicating that there 1 + 2 + 2 + 2 + 1 = 8 distinct types of substrings "01", "10", "1100", "01", "0011", "10", "1100", and "01".
 * It can split 5 parts to discuss that the substring of "0111", "11100", "00111", "11100", and "001".
 *
 * We can notice that the different types of the substrings from only discussing group of "0" and "1", such as "11100" that its pattern can be represents as [3, 2], indicate 2 types of substring, "10" and "1100".
 * Another discuss discussing substring is "1110000", its pattern can be represented as [3, 4], indicating 3 types of substring, "10", "1100", and "111000".
 * Therefore, we can know that the consecutive 0's or 1's number count, its total type of substring can be as same as the smallest the consecutive number count.
 * 
 */
int countBinarySubstrings(char* s) {
 int ret = 0;
 int preCount = 0; 
 int currCount = 1;
 int len = strlen(s);

 for (int i = 1; i < len; i++) {
  if (s[i] != s[i-1]) {
   ret += (preCount < currCount) ? preCount : currCount;
   preCount = currCount;
   currCount = 1;
  } else {
   currCount++;
  }
 }
 // count the last group.
 ret += (preCount < currCount) ? preCount : currCount;

 return ret;
}

int main (void) {

 return 0;
}
