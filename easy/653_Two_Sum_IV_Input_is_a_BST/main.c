#include <stdio.h>

void infixAddPad (struct TreeNode* node, int k, int *pad, int *padIndex) {
 if (!node) return;
 infixAddPad (node->left, k, pad, padIndex);
 pad[padIndex++] = k - node->val;
 pad = (int*) realloc(pad, padIndex);
 infixAddPad (node->right, k, pad, padIndex);
}

void infix (struct TreeNode* node, int *pad, int *padSize) {
 if (!node) return;
 infix (node->left, pad, padSize);
 infix (node->right, pad, padSize);
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
 infixAddPad (root, k, pad, &padIndex);


 
}

int main (void) {

 return 0;
}
