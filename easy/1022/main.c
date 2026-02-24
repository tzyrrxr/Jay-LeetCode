typedef struct TreeNode* NODE;

void DFS (NODE root, int val, int *sum) {
  if (!root) {
    return;
  }
  val <<= 1;
  val += root->val;

  if (!root->left && !root->right) {
    *sum += val;
  } else {
    DFS(root->left, val, sum);
    DFS(root->right, val, sum);
  }

}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumRootToLeaf(struct TreeNode* root) {
  int sum = 0;
  DFS(root, 0, &sum);
  return sum;
}
