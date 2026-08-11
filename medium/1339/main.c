
// The node's value is positive and the total value of root is fixed.
// The product number = tatal * (total - subtree) 

#define MOD 1000000007
typedef struct TreeNode* NODE; 

// DFS
long long SumOfSubtree(NODE root, long long* total, long long *TreeSum, int *top) {
  if (!root) return 0;
  long long left = SumOfSubtree(root->left, total, TreeSum, top);
  long long right = SumOfSubtree(root->right, total, TreeSum, top);
  long long subtreeSum = left + right + root->val;
  *total = subtreeSum;
  TreeSum[*top] = subtreeSum;
  (*top)++;

  return subtreeSum;

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxProduct(struct TreeNode* root) {
  long long bestProd = 0;
  long long total = 0;
  int top = 0;
  // The number of nodes in the tree is in the range [2, 5 * 10^4].
  long long *TreeSum = (long long*) malloc(sizeof(long long) *50001);

  SumOfSubtree (root, &total, TreeSum, &top);

  for (int i = 0; i < top; i++) {
    long long currTreeSum = (long long) TreeSum[i];
    long long prod = (total - currTreeSum) * currTreeSum;
    if (prod > bestProd) bestProd = prod;
  }

  free(TreeSum);

  return (int)(bestProd % MOD);
}
