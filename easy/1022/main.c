int DFS (struct TreeNode* root, int val) {
  if (!root) return 0;
  val = val*2 + root->val;

  if (!root->left && !root->right) {
    return val;
  } 

  return DFS(root->left, val) + DFS(root->right, val);

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
  return DFS(root, 0);
}
