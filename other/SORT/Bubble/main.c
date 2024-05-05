#include <stdio.h>

void BS_inc (int *pt, int s) {

 int tmp;

 for (int i = 0; i < s; i++) {
  for (int j = 0; j < s-1-i; j++) {
   if (pt[j] > pt[j+1]) {
    tmp = pt[j];
    pt[j] = pt[j+1];
    pt[j+1] = tmp;
   }
  }
 }

}

void BS_dec (int *pt, int s) {
 int tmp;

 for (int i = 0; i < s; i++) {
  for (int j = 0; j < s-1-i; j++) {
   if (pt[j] < pt[j+1]) {
    tmp = pt[j];
    pt[j] = pt[j+1];
    pt[j+1] = tmp;
   }
  }
 }

}

int main (void) {
 int t[] = {1, 2, 3, 5, 10};

 BS_dec (t, sizeof(t)/sizeof(int));

 puts("Done");

 return 0;
}
