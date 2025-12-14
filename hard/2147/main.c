#include <stdio.h>

//void DP (char *pt, int *cnt, int seatCnt) {
//  if (*pt == '\0') return;
//  if (*pt == 'S') {
//    if (seatCnt < 2) {
//      seatCnt++;
//    } else {
//      seatCnt
//    }
//  } 
//}

int numberOfWays(char* corridor) {
  int cnt = 0;
  char *pt = corridor;

  while(*pt != '\0') {
    if (*pt == 'S') cnt++;
    pt++;
  }

  if(cnt & 1) return 0;
 

  return cnt;
}
