void DFS (struct TreeNode *root, int *inOrderList, int *top) {
  if (!root) return;
  DFS(root->left, inOrderList, top);
  inOrderList[(*top)++] = root->val;
  DFS(root->right, inOrderList, top);
}
struct TreeNode* CreateBalanceTree (int *inOrderList, int s, int e) {
  if (!(s<=e)) return NULL;
  int mid = (s+e) >> 1;
  struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
  struct TreeNode* lsub = CreateBalanceTree(inOrderList, s, mid-1);
  struct TreeNode* rsub = CreateBalanceTree(inOrderList, mid+1, e);
  root->val = inOrderList[mid];
  root->left = lsub;
  root->right = rsub;
  return root;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* balanceBST(struct TreeNode* root) {
  int *inOrderList = (int*) malloc(10001 * sizeof(int));
  int top = 0;
  DFS(root, inOrderList, &top);
  struct TreeNode* res = CreateBalanceTree(inOrderList, 0, top-1);
  free(inOrderList);
  return res;
}
