#include <stdio.h>

int passThePillow(int n, int time) {
  // full rounds time, even ->, odd <-
  int fullRoundsTime = time / (n - 1); 
  int extraTime = time % (n - 1);

  if (fullRoundsTime & 0x1) return n - extraTime;
  else return extraTime + 1;
     
}

int main (void) {
 
 return 0;
}
