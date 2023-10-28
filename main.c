#include <stdio.h>

int findContentChildren(int* g, int gSize, int* s, int sSize){
 return 0;
}





int main () {
 int ret;
 int g[] = {1, 2, 3};
 int s[] = {1, 1};
 int gSize, sSize;

 gSize = sizeof (g) / sizeof (int);
 sSize = sizeof (s) / sizeof (int);

 ret = findContentChildren(g, gSize, s, sSize);

 printf("result: %d\n", ret);

 return 0;
}
