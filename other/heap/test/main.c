#include <stdio.h>
#include <stdlib.h>

// Max heap test

#define MAX 100

int heap[MAX] = {0};
int len = 0;

void swap (int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void Insert (int val) {
  if (len >= MAX) {
    puts("overflow");
    return;
  }
  int index;
  int parent;

  len++;
  index = len-1;

  // insert value into the last position
  heap[index] = val;

  // heapify
  parent = (index-1) / 2;
  while (index != 0 && heap[parent] < heap[index]) {
    swap (heap+parent , heap+index);
    index = parent;
    parent = (index-1) / 2;
  }

}

void heapify (int index) {
  int maxIndex = index;
  int left = index * 2 + 1;
  int right = index * 2 + 2;

  if (left < len && heap[maxIndex] < heap[left]) maxIndex = left;
  if (right < len && heap[maxIndex] < heap[right]) maxIndex = right;

  if (maxIndex != index) {
    swap (heap+maxIndex, heap+index);
    heapify(maxIndex);
  }
}

int deleteMax () {
  if (len <= 0) {
    puts("underflow");
    return -1;
  }

  int ret = heap[0];
  heap[0] = heap[len-1];
  len--;
  heapify(0);

  return ret;
}

int main (void) {

  Insert(2);
  Insert(5);
  Insert(3);
  Insert(1);
  Insert(9);

  for (int i = 0; i < len; i++) printf("%d ", heap[i]);
  printf("\n");
 
  return 0;

}
