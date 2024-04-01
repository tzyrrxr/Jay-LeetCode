#include <stdio.h>

void infix (struct TreeNode* node, int *min, int *secMin) {
 if (!node) return;

 if (*min > node->val) {
  *min = node->val;
 }
 if (*minSec > node->val && *min > node->val) {
  *minSec = node->val;
 }

 infix(root->left, min, secMin);
 infix(root->right, min, secMin);

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findSecondMinimumValue(struct TreeNode* root) {
 int min, secMin;
 min = secMin = INT_MIN;
 infix (root, &min, &secmIN);
}

int main (void) {

 return 0;
}
