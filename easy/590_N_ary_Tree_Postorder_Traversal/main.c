#include <stdio.h>

void postTraversal (struct Node* node, int* returnSize, int* arr) {
 if (!node) return;

 for (int i = 0; i < node->numChildren; i++) {
   postTraversal (node->children[i], returnSize, arr);
 }
 arr[(*returnSize)++] = node->val;
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
int* postorder(struct Node* root, int* returnSize) {

 int* ret = (int *) malloc((100000) * sizeof(int));
 *returnSize = 0;
 postTraversal (root, returnSize, ret);

 return ret;
}

int main (void) {

 return 0;
}
