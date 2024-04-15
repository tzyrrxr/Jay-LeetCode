#include <stdio.h>

void DFS (struct TreeNode* node, int *s, int top, int *sum) {
 if (!node) return;

 s[++top] = node->val;

 // Is leaf node?
 if (!node->left && !node->right) {
  int val = 0;
  for (int i = 0; i < top+1; i++) val = 10*val + s[i];
  *sum += val;
 }
 DFS(node->left, s, top, sum);
 DFS(node->right, s, top, sum);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root) {
 int ret = 0;
 int stack[1001] = {0};
 int top = -1;
 DFS(root, stack, top, &ret);
    
 return ret;
}

int main (void) {

 return 0;
}
