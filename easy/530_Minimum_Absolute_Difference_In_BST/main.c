#include <stdio.h>

struct inorderTravel {
  int val;
  struct inorderTravel *next;
};

void CreateNodeAndLink (struct inorderTravel *node, int linkVal) {
  struct inorderTravel *newNode = (struct inorderTravel *) malloc(sizeof(struct inorderTravel));
  newNode->val = linkVal;
  newNode->next = NULL;
  while (node->next) node = node->next;
  node->next = newNode;
}

void inOrderTravel(struct TreeNode *root, struct inorderTravel *nextNode) {
  if (!root) return;

  inOrderTravel (root->left, nextNode);
  CreateNodeAndLink (nextNode, root->val);
  inOrderTravel (root->right, nextNode);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root) {
  int retMin = INT_MAX;
  int diff = INT_MAX;
  struct inorderTravel *first;
  struct inorderTravel *pt = (struct inorderTravel *) malloc(sizeof(struct inorderTravel));
  pt->next = NULL;
  first = pt;

  inOrderTravel(root, pt);

  while (first->next) {
    diff = first->next->val - first->val;
    retMin = retMin > diff ? diff : retMin;

    first = first->next;
  }

  return retMin;
}

int main (void) {

 return 0;
}
