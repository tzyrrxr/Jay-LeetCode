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

  int *arr = (int *) calloc(10000 + 1, sizeof(int));
  int size = 0;
  int *ret;
  int cur;
  int max = 0;
  int len = 0;
  int index = 0;

  NextNode(root, size, arr);

  ret = (int *) malloc(size * sizeof(int));

  cur = arr[0];
 for (int i = 0; i < size; i++) {
  if (cur == arr[i]) {
   len++;
  } else {
 
  if (len > max) {
   index = 0;
   ret[index++] = cur;
   max = len;
  } else if (len == max) {
   ret[i] = cur;
  }
   cur = arr[i];
   len = 1;
  }
 
 }
 *returnSize = index;
 return arr;

}

int main (void)

 return 0;
}

