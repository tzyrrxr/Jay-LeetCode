#include <stdio.h>

void preorderTraversal(struct Node* node, int* ret, int* retSize) {
 if (!node) return;

 ret[(*retSize)++] = node->val;
 for (int i = 0; i < node->numChildren; i++) {
   preorderTraversal(node->children[i], ret, retSize);
 }

}

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {

 int *ret = (int*) malloc((100000) * sizeof(int));
 *returnSize = 0;

 preorderTraversal(root, ret, returnSize);

 return ret;
}

int main (void) {

 return 0;
}
