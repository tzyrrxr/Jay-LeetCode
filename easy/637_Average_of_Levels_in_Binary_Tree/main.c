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
 double* ret = (double *) malloc (1000 * sizeof(double));

 struct TreeNode* queue[10000];
 struct TreeNode* pt;
 int start, end;
 double sum;

 queue[0] = root;
 start = 0;
 end = 1;

 *returnSize = 0;
 while (end != start) {
  int endOfLevel = end;
  int count = endOfLevel - start;

  for (sum = 0; start < endOfLevel; start++) {

   pt = queue[start];

   sum += pt->val;

   if (pt->left) {
    queue[end++] = pt->left;
   }
   if (pt->right) {
    queue[end++] = pt->right;
   }

  }
  ret[(*returnSize)++] = (double) sum / count;

  // move
  for (int i = start; i <= end; i++) {
   queue[i-count] = queue[i];
  }
  start -= count;
  end   -= count;

 }

 return ret;
}

int main (void) {

 return 0;
}
