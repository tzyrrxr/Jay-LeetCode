#include <stdio.h>

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
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
 struct TreeNode* queue[10000];
 int queueIndex = -1;
 double *ret = (double *) malloc(10000 * sizeof(double));

 queue[++queueIndex] = root;
 *returnSize = 0;
 int levelSize = 1;
 int inputCount;

 while (queueIndex >= 0) {
  int levelSum = 0;
  struct TreeNode *currPt;
  inputCount = 0;                   

  for (int i = queueIndex; i < queueIndex + levelSize; i++) {
   currPt = queue[i]; // mark item pointer

   if (currPt->left) {
    queue[queueIndex+i] = currPt->left; // prepare next level item
    inputCount++;                                    
   }
   if (currPt->right) {
    queue[queueIndex+i] = currPt->right; // prepare next level item
    inputCount++;                                    
   }
                                                           
   levelSum += currPt->val;
  }

  levelSize = inputCount;
  // insert average item.
  ret[(*returnSize)++] = (double) levelSum / levelSize;
 }

 return ret;
}

int main (void) {

 return 0;
}
