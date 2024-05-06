#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
 struct ListNode *ret;
 struct ListNode *pt;
 struct ListNode **s = (struct ListNode **) malloc(100001 * sizeof(struct ListNode*));
 int top = -1;

 pt = head;
 while (pt) {

  while (top > -1 && s[top]->val < pt->val) {
   top--;
  }

  s[++top] = pt;
  pt = pt->next;

 }

 ret = s[0];
 for (int i = 0; i < top; i++) {
  s[i]->next = s[i+1];
 }

 return ret;
}

int main (void) {

 return 0;
}
