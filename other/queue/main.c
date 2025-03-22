#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

  int *arr;
  int head;
  int tail;
  int size;
  int capacity;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
  MyCircularQueue* ret;
  ret = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));

  ret->arr = (int*) malloc (k * sizeof(int));
  ret->head = -1;
  ret->tail = -1;
  ret->size = k;
  ret->capacity = k;

  return ret;

}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  
  if (obj->capacity + 1 > obj->size) return false;
    
  if (obj->head == -1) obj->head = 0;
  obj->tail = (++obj->tail) % obj->size;
  obj->arr[obj->tail] = value;
  obj->capacity--;

  return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if (obj->head == -1 || (obj->haed+1) % obj->size > obj->tail) return false;

  obj->head = (obj->head + 1) % obj->size;
  obj->capacity++;

  return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
  return obj->arr[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
  return obj->arr[obj->tail];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return obj->capacity == 0 ? true : false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return obj->capacity == obj->size ? true : false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
  free (obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/

int main () {

 return 0;

}
