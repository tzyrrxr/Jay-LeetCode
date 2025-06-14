#include <stdio.h>
#include <stdlib.h>
#include <limit.h>
#include <math.h>

int minMaxDifference(int num) {
  int diff = 0;
  int min = INT_MAX;
  int max = INT_MIN;
  int tmp;
  int d;
  int source;
  int target;
  int picker;
  int transfer;

  for (source = 0; source < 10; source++) {
    for (target = 0, d=0; target < 10; target++, d=0) {
      if (target == source) continue;
      tmp = num;
      transfer = 0;
      while (tmp) {
        picker = tmp % 10;
        if (picker == source) {
          picker = target;
        }
        transfer += picker * pow(10 , d);
        d++;
        tmp /= 10;
      }

      if (transfer > max) max = transfer;
      if (transfer < min) min = transfer;
      
    }
  }

  diff = max - min;
    
  return diff;

}

int main () {

  minMaxDifference (11981);

  return 0;
}
