#include <stdio.h>
#include <stdlib.h>

struct sample {
  int a;
  int b;
  float c;
  long d;
};

int main (void) {

  struct sample *p = (struct sample *) malloc (sizeof(struct sample));

  int *e;
  int f;
  int g;

  e = (int *) &p;
  f = *e;
  g = *e + 4;

  printf("p addre: %x\n", p);
  printf("p + 1 addre: %x\n", p + 1);
  printf("size of *p: %x\n", sizeof(*p));
  printf("%x\n", f);
  printf("%x\n", g);
 
  return 0;

}
