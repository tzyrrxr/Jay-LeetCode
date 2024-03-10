#include <stdio.h>

bool checkingSubtree (struct TreeNode* root, struct TreeNode* subRoot) {
  if (!root && !subRoot) return true;
  if (!root || !subRoot) return false;
  if (root->val != subRoot->val) return false;

  return checkingSubtree(root->left, subRoot->left) && checkingSubtree(root->right, subRoot->right);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
  if (!root) return false;
  if (!subRoot) return true;
  if (checkingSubtree(root, subRoot)) return true;

  return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main (void) {

 return 0;
}
