#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
 if (!root1) return root2;

 if (!root2) return root1; // Tree 2 is null
 root1->val += root2->val;

 // combine two trees into tree 1
 root1->left = mergeTrees (root1->left, root2->left);
 root1->right = mergeTrees (root1->right, root2->right);

 return root1;
}

int main (void) {

 return 0;
}
