#include <stdio.h>

void infix (struct TreeNode* node, int *min, int *secMin, bool *mm, bool *ms) {
 if (!node) return;

 if (*min >= node->val) {
  *min = node->val;
  *mm = true;
 } else if (*secMin >= node->val && *min < node->val) {
  *secMin = node->val;
  *ms = true;
 }

 infix(node->left, min, secMin, mm, ms);
 infix(node->right, min, secMin, mm, ms);

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
 bool mm, ms;
 mm = ms = false;
 min = secMin = INT_MAX;
 infix (root, &min, &secMin, &mm, &ms);
 if (!mm || !ms) return -1;
 return secMin;
}

int main (void) {

 return 0;
}
