#include <stdio.h>

void DFS (struct TreeNode* node, int *lNodes, int *size) {
 if (!node) return;

 if (!node->left && node->right) {
  lNodes[(*size)++] = node->right->val;
 }
 if (node->left && !node->right) {
  lNodes[(*size)++] = node->left->val;
 }

 DFS(node->left, lNodes, size);
 DFS(node->right, lNodes, size);

}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLonelyNodes(struct TreeNode* root, int* returnSize) {
 int *ret = (int *) malloc(1001 * sizeof(int));
 *returnSize = 0;

 DFS(root, ret, returnSize);

 return ret;
}

int main (void) {

 return 0;
}
