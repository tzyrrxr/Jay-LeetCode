struct DepthInfo {
  struct TreeNode* node;
  int depth;
};

typedef struct DepthInfo DepInfo;
typedef struct TreeNode Node;

DepInfo helper(Node *root) {
  if (!root) return (DepInfo) {NULL, 0};

  DepInfo left = helper(root->left);
  DepInfo right = helper(root->right);

  if (left.depth > right.depth) return (DepInfo) {left.node, left.depth + 1};
  if (right.depth > left.depth) return (DepInfo) {right.node, right.depth + 1};
  return (DepInfo) {root, right.depth + 1}; // left and right depths are equal.
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    
  return helper(root).node;

}
