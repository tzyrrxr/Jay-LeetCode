#include <stdio.h>

void traversal(struct Node *root, int level, int *maxLevel) {
  if (!root) return;

  level++;
  if (level > *maxLevel) {
    *maxLevel = level;
  }

  for (int i = 0; i < root->numChildren; i++) {
    traversal(root->children[i], level, maxLevel);
  }
  
}
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

int maxDepth(struct Node* root) {
  int maxLevel = 0;
  traversal(root, 0, &maxLevel);

  return maxLevel;
    
}

int main (void) {

 return 0;
}
