#include <stdio.h>
#include <stdlib.h>

void DFS (struct TreeNode* node, char *s, int top, int *sum) {
 if (!node) return;

 s[++top] = 0x30 + node->val;

 // Is leaf node?
 if (!node->left && !node->right) {
  s[top+1] = '\0';
  *sum += atoi(s);
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
 char stack[1001] = {0};
 int top = -1;
 DFS(root, stack, top, &ret);
    
 return ret;
}

int main (void) {

 return 0;
}
