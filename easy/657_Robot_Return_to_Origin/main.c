#include <stdio.h>

bool judgeCircle(char* moves) {
 int x, y;
 x = y = 0;

 for (int i = 0; moves[i]; i++) {
  switch (moves[i]) {
   case 'U':
    y += 1;
    break;
   case 'D':
    y -= 1;
    break;
   case 'R':
    x += 1;
    break;
   case 'L':
    x -= 1;
    break;
  }
 }

 return !(x || y);
}

int main (void) {

 return 0;
}
