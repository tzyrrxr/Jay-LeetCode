#include <stdio.h>

struct TreeNode* NewNode (int val) {
  struct TreeNode* ptr = (struct TreeNode*) malloc (sizeof(struct TreeNode));
  if (ptr == NULL) {
    printf("malloc node for %d fail.", val);
    return NULL;
  }

  ptr->val = val;
  ptr->left = NULL;
  ptr->right = NULL;
  return ptr;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* recoverFromPreorder(char* traversal) {
    int len = strlen (traversal);
    int index = 0;
    int depth = 0;
    int val = 0;
    struct TreeNode* stack[1000];
    int top = -1;

    struct TreeNode* ret = NULL;
    struct TreeNode* node = NULL;

    while (index < len) {

      // count dash, mean depth
      depth = 0;
      while (index < len && traversal[index] == '-') {
        depth++;
        index++;
      }

      // digital
      val = 0;
      while (index < len && (traversal[index] >= '0' && traversal[index] <= '9')) {
        val = val* 10 + traversal[index] - '0';
        index++;
      }

      node = NewNode (val);

      if (top == -1) {
        ret = node;
        stack[++top] = ret;
      }

      if (top > 0) {
        if (top >= depth) top = depth - 1;
        if (stack[top]->left == NULL) {
          stack[top]->left = node;
        } else {
          stack[top]->right = node;
        }
      }

      stack[++top] = node;
    }

    return ret;
}

int main (void) {
 
 return 0;
}
