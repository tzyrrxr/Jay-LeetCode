#include <stdio.h>
#include <stdbool.h>

bool SearchByHashTable (struct TreeNode* node, int k, bool *padArr) {
 if (!node) return false;

 if (padArr[node->val + 100000] == 0) {
  padArr[k - node->val + 100000]++;
 } else {
  return true;
 }

 return SearchByHashTable(node->left, k, padArr) || SearchByHashTable(node->right, k, padArr);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool findTarget(struct TreeNode* root, int k) {
 bool *padArr = (bool *) calloc(1000000, sizeof(bool));
 bool ret = false;

 ret = SearchByHashTable (root, k, padArr);

 return ret;
}

int main (void) {


 return 0;
}
