#include <stdio.h>

int hammingDistance(int x, int y) {
 unsigned int val = x^y;
 int counter = 0;

 for (; val; val>>=1) val&1 ? counter++ : 0;

 return counter;
}


int main () {

 int counter = hammingDistance (1, 4);
 printf("%d\n", counter);

 return 0;
}
