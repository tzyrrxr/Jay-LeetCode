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
  if (!node->left && !node->right) { /* _ */
   node->left = CreateNode(val);
   node->right = CreateNode(val);
  } else if (node->left && node->right) { /* /\ */
   struct TreeNode *tmp;
   tmp = node->left;
   node->left = CreateNode(val);
   node->left->left = tmp;

   tmp = node->right;
   node->right = CreateNode(val);
   node->right->right = tmp;
  } else if (node->left && !node->right) { /* / */
   struct TreeNode *tmp;
   tmp = node->left;
   node->left = CreateNode(val);
   node->left->left = tmp;

   node->right = CreateNode(val);
  } else if (!node->left && node->right) { /* \ */
   struct TreeNode *tmp;
   tmp = node->right;
   node->right = CreateNode(val);
   node->right->right = tmp;

   node->left = CreateNode(val);
  }
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
 struct TreeNode *ret;
 ret = root;

 if (depth == 1) {
  ret = CreateNode(val);
  ret->left = root;
 } else {
  DFS(ret, 1, val, depth);
 }
    
 return ret;
}

int main (void) {

 return 0;
}
