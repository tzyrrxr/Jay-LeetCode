#include <stdio.h>

struct TreeNode* CreateNode (int val) {
 struct TreeNode *ret = (struct TreeNode *) malloc(sizeof(struct TreeNode));
 ret->val = val;
 ret->left = NULL;
 ret->right = NULL;

 return ret;
}

// nDepth: node's depth
// tDepth: target depth
void DFS (struct TreeNode *node, int nDepth, int val, int tDepth) {
 if (!node) return;

 if (nDepth+1 == tDepth) {
  // _
  if (!node->left && !node->right) {
   node->left = CreateNode(val);
   node->right = CreateNode(val);
  }
  /* /\ */
  if (node->left && node->right) {
  }
  /* / */
  /* \ */
 }

 DFS(node->left, nDepth+1, val, tDepth);
 DFS(node->right, nDepth+1, val, tDepth);

}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {
    
}

int main (void) {

 return 0;
}
