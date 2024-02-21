#include <stdio.h>

void NextNode(struct TreeNode* root, int* size, int *retArr) {
  if (!root) return;

  // inorder traversal
  NextNode (root->left, size, retArr);
  retArr[(*size)++] = root->val;
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

  int *arr = (int *) malloc(10000 * sizeof(int));
  int size = 0;
  int *ret;
  int cur;
  int max = 0;
  int len = 0;
  int index = 0;


  NextNode(root, &size, arr);

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
        ret[index++] = cur;

      }
        cur = arr[i];
        len = 1;
    }

  }

  // if the last number run "if (cur == arr[i])"
  if (len > max) {
    index = 0;
    ret[index++] = cur;

  } else if (len == max) { 
    ret[index++] = cur;

  }
  

  *returnSize = index;
  return ret;
}

int main (void)

 return 0;
}

