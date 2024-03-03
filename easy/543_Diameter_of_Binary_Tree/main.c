#include <stdio.h>

int inorderTraversal (struct TreeNode *node, int *maxDiameter) {
  if (!node) {
    return 0;
  }
  int left, right;
  left = right = 0;

  left = inorderTraversal (node->left, maxDiameter);
  right = inorderTraversal (node->right, maxDiameter);
  if (left + right > *maxDiameter) {
    *maxDiameter = left + right;
  }

  return left > right ? ++left : ++right;

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameterOfBinaryTree(struct TreeNode* root) {

  int diameter = 0;
  inorderTraversal (root, &diameter);

  return diameter;
    
}


int main (void) {

 return 0;
}
