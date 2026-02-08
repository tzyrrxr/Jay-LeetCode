/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int DFS(TreeNode* root) {
      if (!root) return 0;
      int l, r;
      l = DFS(root->left);
      if (l == -1) {
        return -1;
      }
      r = DFS(root->right);
      if (r == -1) {
        return -1;
      }

      if (l-r > 1 || l-r < -1) {
        return -1;
      }

      return 1 + (l > r ? l : r);
    }
public:
    bool isBalanced(TreeNode* root) {
      return DFS(root) != -1;
    }
};
