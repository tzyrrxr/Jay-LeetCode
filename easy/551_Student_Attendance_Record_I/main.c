#include <stdio.h>

bool checkRecord(char* s) {
  int absentTimes = 0;
  int consecutiveLateTimes = 0;
  bool ret = true;

  while(*s != '\0') {
    switch(*s) {
      case 'A':
        absentTimes++;
        consecutiveLateTimes = 0;
        if (absentTimes > 1) return false;
        break;
      case 'L':
        consecutiveLateTimes++;
        if (consecutiveLateTimes > 2) return false;
        break;
      default: // Present
        consecutiveLateTimes = 0;
        break;
    }
    s++;
  }

  return true;
}

int main (void) {

 return 0;
}
