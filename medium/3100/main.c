#include <stdio.h>

int maxBottlesDrunk(int numBottles, int numExchange) {
  int drink = numBottles;
  int empty = numBottles;

  while (empty >= numExchange) {
    empty = empty - numExchange + 1;
    drink++;
    numExchange++;
  }
    
  return drink;
}

int main (int argc, char *argv[]) {
  int ret =0;

  ret = maxBottlesDrunk (10, 3);

  printf("%d\n", ret);

  return 0;
}
