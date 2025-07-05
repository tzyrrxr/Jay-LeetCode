#include <stdio.h>
#include <stdlib.h>

int findLucky(int* arr, int arrSize) {
  int hash[501] = {0};
  int stash[32] = {0}; // sum of n < 500
  int top = -1;
  int ret = -1;

  for (int i = 0; i < arrSize; i++) {
    hash[arr[i]]++;

    if (arr[i] == hash[arr[i]]) {
      if (top == -1 || stash[top] != arr[i]) {
        stash[++top] = arr[i];
        if (arr[i] < ret) {
         // TODO: Optimize sort, tmp to bubble sort
          for (int a = 0; a <= top; a++) {
            for (int b = a+1; b <= top; b++) {
              if (stash[a] > stash[b]) {
                stash[a] = stash[a] + stash[b];
                stash[b] = stash[a] - stash[b];
                stash[a] = stash[a] - stash[b];
              }
            }
          }
        } else {
          ret = arr[i];
        }
      } 
    }

    if (ret == arr[i] && ret < hash[arr[i]]) {
     while (top >= 0 && stash[top] != hash[stash[top]]) top--;
     if (top == -1) ret = -1;
     else ret = stash[top];
    }
  }
    
  return ret;

}

int main () {

  return 0;
}
