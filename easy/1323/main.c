#include <stdio.h>
#include <stdlib.h>

int maximum69Number (int num) {
  int ret = num;
  char buf[20];

  sprintf(buf, "%d", num);

  for (int i = 0; buf[i] != '\0'; i++) {
    if (buf[i] == '6') {
      buf[i] = '9';
      if (ret < atoi(buf)) {
        return atoi(buf);
      }
    }
  }

  return ret;
}

int main (int argc, char argv[]) {

  return 0;
}
