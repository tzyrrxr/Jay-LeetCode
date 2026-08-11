/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
  if (!head) return head;
  struct ListNode* pt = head;
  int len = 0;
  while (pt->next != NULL) {
    len++;
    pt = pt->next;
  }
  pt->next = head;
  pt = pt->next;
  len++;

  k %= len;
  k = len - k;

  struct ListNode* pre;
  for (int i = 0; i < k; i++) {
    pre = pt;
    pt = pt->next;
  }
  pre->next = NULL;

  return pt;
    
}
