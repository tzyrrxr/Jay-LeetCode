#include <stdio.h>

struct TreeNode* DFS (struct TreeNode* n, int t) {
 if (n->left) n->left = DFS(n->left, t);
 if (n->right) n->right = DFS(n->right, t);
 if (n->val == t && !n->left && !n->right) {
  free(n);
  return NULL;
 }

 return n;

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* removeLeafNodes(struct TreeNode* root, int target) {

 return DFS (root, target);

}

int main (void) {

 return 0;
}
