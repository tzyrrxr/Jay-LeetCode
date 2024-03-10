#include <stdio.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int inorderTraversal (struct TreeNode* root, int *ret) {
  int leftNode, rightNode; 
  if (root->left) {
    leftNode = inorderTraversal(root->left, ret);
  } else {
    leftNode = 0;
  }

  if (root->right) {
    rightNode = inorderTraversal(root->right, ret);
  } else {
    rightNode = 0;
  }

  if (leftNode > rightNode) {
    *ret += leftNode - rightNode;
  } else {
    *ret += rightNode - leftNode;
  }


  return root->val + leftNode + rightNode;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findTilt(struct TreeNode* root) {
  if (!root) return 0;
  int ret = 0;
  inorderTraversal (root, &ret);

  return ret;
}

int main (void) {

 return 0;
}
