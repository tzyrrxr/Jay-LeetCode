/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
  struct ListNode *p1, *p2;
  int cnt = 0;
  p1 = p2 = head;

  while (p1 != NULL) {
    cnt++;
    p1 = p1->next;
  }
  if (cnt <= 1) return NULL;

  cnt /= 2;

  while (--cnt) {
    p2 = p2->next;
  }
  p2->next = p2->next->next;

  return head;
    
}
