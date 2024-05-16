#include <stdio.h>

void DFS (struct TreeNode* n, bool *s, int *top) {
 if (!n) return;

 DFS (n->left, s, top);
 DFS (n->right, s, top);

 bool a, b;

 if (n->val == 0 || n->val == 1) {

  s[++(*top)] = n->val;

 } else {

  a = s[(*top)--];
  b = s[(*top)--];
  switch (n->val) {
   case 2:
    s[++(*top)] = a | b;
    break;
   case 3:
   default:
    s[++(*top)] = a & b;
    break;
  }

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
bool evaluateTree(struct TreeNode* root) {
 // 2 == or
 // 3 == and
 bool *s = (bool*) malloc(1001 * sizeof(bool));
 int top = -1;

 DFS (root, s, &top);
    
 return s[0];
}

int main (void) {

 return 0;
}
