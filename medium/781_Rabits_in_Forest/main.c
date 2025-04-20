#include <stdio.h>

int numRabbits(int* answers, int answersSize) {
  // array answers is meaning visible rabbits
  // array answers's value means that how many habbits as same as my color except myself
  int atLastRabbitsNum = 0;
  int call[1000] = {0};

  for (int i = 0; i < answersSize; i++) {
    call[answers[i]]++;
  }

  for (int i = 0; i < 1000; i++) {
    atLastRabbitsNum += (i+1) - (call[i] % (i+1)) // need to complete this groups 
     + call[i]; // at least number of rabbits
  }
    
  return atLastRabbitsNum;

}

int main (void) {
 
 return 0;
}
