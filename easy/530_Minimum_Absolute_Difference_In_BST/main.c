#include <stdio.h>


void inOrderTravel(struct TreeNode *root, int *min, int *preVal) {
  if (!root) return;

  inOrderTravel (root->left, min, preVal);

  if (*preVal != INT_MAX) {
    if (*min > (root->val - *preVal)) {
      *min = root->val - *preVal;
    }
    *preVal = root->val;
  } else { // initial
    *preVal = root->val;
  }

  inOrderTravel (root->right, min, preVal);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root) {
  int retMin = INT_MAX;
  int preVal = INT_MAX;

  inOrderTravel (root, &retMin, &preVal);

  return retMin;
}

int main (void) {

 return 0;
}
