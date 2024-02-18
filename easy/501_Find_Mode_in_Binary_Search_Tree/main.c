#include <stdio.h>


void NextNode(struct TreeNode* root, int* size, int *retArr) {
  if (!root) return;
  retArr[(*size)++] = root->val;
  NextNode (root->left, size, retArr);
  NextNode (root->right, size, retArr);
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
int* findMode(struct TreeNode* root, int* returnSize) {

  int *retArr = (int *) calloc(10000 + 1, sizeof(int));
  
  *returnSize = 0;
  
  NextNode(root, returnSize, retArr);
  
  //realloc(retArr, (*returnSize) * sizeof(int));
  
  return retArr;

}

int main (void)

 return 0;
}

