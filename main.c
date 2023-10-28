#include <stdio.h>
#include <stdlib.h>

int findContentChildren(int* g, int gSize, int* s, int sSize){
 return 0;
}

int main () {
 int *g, *s;
 int gSize, sSize;
 int ret;
 gSize = 4;
 sSize = 4;


 g = (int *) malloc(gSize * sizeof (int));
 s = (int *) malloc(sSize * sizeof (int));
 ret = findContentChildren(g, gSize, s, sSize);
 printf("%d\n", ret);

 return 0;
}
