#include <stdio.h>

/*
 * There are n people to buy tickets.
 * { tickets = person[Index] | Index = {0 ~ n-1} }
 * That is person 0 to buy person[0] tickets.
 * Mark person k to end of time consume.
 * If Index <= k, then the person <Index> can buy the most to person[k] tickets.
 * If Index > k, then the person <Index> can buy the most to person[k]-1 tickets.
 */

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
 int sec = 0;
 int pk = tickets[k];

 for (int i = 0; i < ticketsSize; i++) {
   sec += (i > k) ? 
   (tickets[i] < pk-1 ? tickets[i] : pk-1) : 
   (tickets[i] < pk ? tickets[i] : pk);
 }

 return sec;
}

int main (void) {

 return 0;
}
