#include <stdio.h>

/*
// Definition for a Node.
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};
*/

struct Node* inorderSuccessor(struct Node* node) {

  // If the node has a right subtree, then goto right node and go through every left node.
  if (node->right) {
    node = node->right;
    while(node->left) node = node->left;
  } else { 
    // No right node.
    // Two cases:
    // case 1: This node is left node. Return parent's node
    // case 2: This node is right node. Return the oldest parent's node if parent's node is right node.
    
    // case 2
    while (node->parent && // level 1 node
           node == node->parent->right  // check the node is as be the right node.
          ) {
      node = node->parent;
    }
    node = node->parent; // case 1
  }

  return node;
}

int main (void) {

 return 0;
}
