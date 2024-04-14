#include <stdio.h>

void DFS (struct TreeNode *node, int *sum, bool isLeft) {
 if (!node) return;

 if (!node->left && !node->right && isLeft) *sum += node->val;

 DFS(node->left, sum, true);
 DFS(node->right, sum, false);

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
 int ret = 0;
 bool isLeft = false;

 DFS(root, &ret, isLeft);

 return ret;
}

int main (void) {

 return 0;
}
