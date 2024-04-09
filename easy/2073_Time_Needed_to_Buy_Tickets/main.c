#include <stdio.h>

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
 int sec = 0;
 int i = 0;

 while (1) {
  if (tickets[i]) {
   tickets[i]--;
   sec++;
  }
  if (!tickets[k]) break;
  if (++i >= ticketsSize) i = 0;
 }

 return sec;
}

int main (void) {

 return 0;
}
