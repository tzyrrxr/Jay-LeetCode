#include <stdio.h>

struct Node {
 int val;
 struct Node* next;
 struct TreeNode *treeNode;
};

struct Node* CreateNode (int val) {
 struct Node* ret;
 ret->val = val;
 ret->next = NULL;
 return ret;
}

void FreeNode (struct Node* node) {
 free(node);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
 struct Node *pt;
 struct Node *first;
 double *ret = (double *) malloc(1000 * sizeof(double));
 int len;
 int tmpSum;
 struct Node *lastPt;

 // init root
 pt = CreateNode(root->val);
 pt->treeNode = root;
 len = 1;
 *returnSize = 0;
 lastPt = pt;

 while (len) {

  struct TreeNode *currNode = pt->treeNode;

  len = 0;
  // calculate link list length and mark the last pointer
  for (struct Node* tmpPt = lastPt; tmpPt; tmpPt = tmpPt->next) {
   len++;
   lastPt = tmpPt;
  }

  for (int i = 0; i < len; i++) {
   tmpSum += pt->val;
   pt = pt->next;
   if (currNode->left) {
    lastPt->next = CreateNode(currNode->left->val);
    lastPt->next->treeNode = currNode->left;
    lastPt = lastPt->next;
   }

   if (currNode->right) {
    lastPt->next = CreateNode(currNode->right->val);
    lastPt->next->treeNode = currNode->right;
    lastPt = lastPt->next;
   }

  }

  ret[(*returnSize)++] = (double) tmpSum / len;
 }

 return ret;
}

int main (void) {

 return 0;
}
