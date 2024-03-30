#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
 int val;
 struct TreeNode *left;
 struct TreeNode *right;
};

void prefixAddPad (struct TreeNode* node, int k, int *pad, int *padIndex) {
 if (!node) return;
 pad[(*padIndex)++] = k - node->val;
 pad = (int*) realloc(pad, (*padIndex + 1) * sizeof(int));

 prefixAddPad (node->left, k, pad, padIndex);
 prefixAddPad (node->right, k, pad, padIndex);
}

bool infix (struct TreeNode* node, int *pad, int *padSize) {
 if (!node) return false;
 bool ret = false;

 ret = infix (node->left, pad, padSize);
 for (int i = 0; i < *padSize; i++) {
  if (pad[i] == node->val) {
   ret = true;
   break;
  }
 }
 ret = infix (node->right, pad, padSize) || ret;

 return ret;
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
 int *pad = (int *) malloc(sizeof(int));
 int padIndex = 0;
 bool ret = false;

 prefixAddPad (root, k, pad, &padIndex);

 ret = infix (root, pad, &padIndex);

 return ret;
}

int main (void) {

 int arr[] = [5,3,6,2,4,null,7];
 findTarget (arr);

 return 0;
}
