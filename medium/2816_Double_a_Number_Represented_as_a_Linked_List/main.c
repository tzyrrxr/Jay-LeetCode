#include <stdio.h>

struct ListNode* CreateNode (int val) {

 struct ListNode* ret = (struct ListNode*) malloc(sizeof(struct ListNode));
 ret->val = val;
 ret->next = NULL;

 return ret;
}

struct ListNode* Reverse (struct ListNode* head) {
 struct ListNode* pt;
 struct ListNode* prev;
 struct ListNode* npt;
 pt = head;
 prev = NULL;
 npt  = NULL;

 while (pt) {
  npt = pt->next;
  pt->next = prev;
  prev = pt;
  pt = npt;
 }

 return prev;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head){
 struct ListNode* pt;
 struct ListNode* prev;
 struct ListNode* ret;
 int carry = 0;
 int val;
 ret = head;
 ret = Reverse (ret);
 pt = ret;

 while (pt) {
  val = pt->val;
  pt->val = ((val * 2) + carry) % 10;
  carry = ((val * 2)) / 10;
  prev = pt;
  pt = pt->next;
 }

 if (carry) prev->next = CreateNode(1);

 ret = Reverse (ret);

 return ret;
}

int main (void) {

 return 0;
}
