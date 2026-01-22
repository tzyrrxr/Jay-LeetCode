struct Node {
  int val;
  int sumOfNextPairs;
  struct Node* next;
};

struct Node* createNode(int val) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->val = val;
  newNode->next = NULL;
  return newNode;
}

int minimumPairRemoval(int* nums, int numsSize) {
  struct Node *h = createNode(nums[0]);
  struct Node *p = h;
  int min = INT_MAX;
  int minIndex = -1;
  int cnt = 0;
  bool isNonDecreasing =true;

  for (int i = 1; i < numsSize; i++) {
    p->next = createNode(nums[i]);
    p = p->next;
  }

  while (numsSize - cnt > 1) {
    isNonDecreasing = true;
    p = h;
    min = INT_MAX;
    minIndex = -1;

    for (int i = 0; i < numsSize-cnt-1; i++) {
      p->sumOfNextPairs = p->val + p->next->val;

      if (p->sumOfNextPairs < min) {
       min = p->sumOfNextPairs;
       minIndex = i;
      }
      if (p->val > p->next->val) {
        isNonDecreasing = false;
      }

      p = p->next;
    }
    if (isNonDecreasing) break;

    p = h;

    while (minIndex > 0) {
      p = p->next;
      minIndex--;
    }
    p->val = p->sumOfNextPairs;
    p->sumOfNextPairs = INT_MAX;
    struct Node *tmp = NULL;
    if (p->next->next) tmp = p->next->next;
    free(p->next);
    p->next = tmp;
    cnt++;
  }

  for (p = h; p != NULL;) {
    struct Node* tmp = p;
    p = p->next;
    free(tmp);
  }


  return cnt;
    
}
