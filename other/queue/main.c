typedef struct {

  int *arr;
  int head;
  int tail;
  int size;
  int count;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
  MyCircularQueue* ret;
  ret = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));

  ret->arr = (int*) malloc (k * sizeof(int));
  ret->head = -1;
  ret->tail = -1;
  ret->size = k;
  ret->count = 0;

  return ret;

}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  
  if (obj->count == obj->size) return false;
    
  if (obj->head == -1) obj->head = 0;
  obj->tail = (++obj->tail) % obj->size;
  obj->arr[obj->tail] = value;
  obj->count++;

  return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if (obj->count == 0) return false;

  obj->head = (obj->head + 1) % obj->size;
  obj->count--;

  return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
  return obj->count != 0 ? obj->arr[obj->head] : -1;
}

int myCircularQueueRear(MyCircularQueue* obj) {
  return obj->count != 0 ? obj->arr[obj->tail] : -1;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  return obj->count == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  return obj->count == obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
  free (obj->arr);
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

