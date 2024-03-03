#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root) {
  if (!root->left && !root->right) return INT_MAX;
  int retMin = INT_MAX;
  int leftHistoryMin = INT_MAX;
  int rightHistoryMin = INT_MAX;
  int HistoryMin = INT_MAX;
  int diff = INT_MAX;

  if (root->left) {
    leftHistoryMin = getMinimumDifference(root->left);
    diff = root->val - root->left->val;
    retMin = leftHistoryMin > diff ? diff : leftHistoryMin;
  }
  if (root->right) {
    diff = root->right->val - root->val;
    retMin = leftHistoryMin > diff ? diff : leftHistoryMin;
  }

  if (root->right) {
    rightHistoryMin = getMinimumDifference(root->right);
    HistoryMin = rightHistoryMin > leftHistoryMin ? leftHistoryMin : rightHistoryMin;
    diff = root->right->val - root->val;
    retMin = HistoryMin > diff ? diff : HistoryMin;
  }
  if (root->left) {
    diff = root->val - root->left->val;
    retMin = HistoryMin > diff ? diff : HistoryMin;
  }
    
  return retMin;
}

int main (void) {

 return 0;
}
