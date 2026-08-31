/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
  int *ret = (int*)malloc(2*sizeof(int));
  *returnSize = 2;
  struct ListNode *pre, *next, *pt;
  int critical_1 = 0, critical_pre = 0; 
  int counter = 2;
  int min = INT_MAX, max = 0; 

  //memset(ret, 1, 2*sizeof(int));
  ret[0] = -1;
  ret[1] = -1;

  pre = next = pt = head;
  if (pt->next && pt->next->next) {
    pt = pt->next;
    next = pt->next;
  } else {
    return ret;
  }

  while (next) {
    if ((pre->val > pt->val && next->val > pt->val) ||
        (pre->val < pt->val && next->val < pt->val)
      ) {
      if (!critical_1) {
        critical_1 = counter;
        critical_pre = counter;
      }
      if (counter - critical_pre < min && counter - critical_pre > 0) {
        min = counter - critical_pre;
      }
      if (counter - critical_1 > max && counter - critical_1 > 0) {
        max = counter - critical_1;
      }
      critical_pre = counter;
    }
    pre = pt;
    pt = next;
    counter++;
    next = next->next;
  }

  if (min != INT_MAX)
    ret[0] = min;
  if (max != 0)
    ret[1] = max;
    
  return ret;
}
