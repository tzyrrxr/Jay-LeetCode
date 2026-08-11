int DFS (struct TreeNode* root, bool *res, int depth) {
  if (!root->left && !root->right) return depth;
  int l, r;
  l = r = depth;
  if (root->left) {
    l = DFS(root->left, res, depth+1);
  }
  if (root->right) {
    r = DFS(root->right, res, depth+1);
  }

  if (l-r < -1 || l-r > 1) *res = false;

  return l > r ? l : r;

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root) {
  if (!root) return true;
  bool res = true;

  DFS (root, &res, 0);
    
  return res;
}
