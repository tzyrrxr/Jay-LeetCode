#include <stdio.h>

// return the node need to left coins
int DFS (struct TreeNode* node, int *move) {
 if (!node) return 0;

 // They mean that the coins need to be moved.
 int lCoins = DFS (node->left, move);
 int rCoins = DFS (node->right, move);

 *move += abs(lCoins) + abs(rCoins);

 return (node->val - 1 ) + lCoins + rCoins;

}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int distributeCoins(struct TreeNode* root) {
 int move = 0;
 DFS (root, &move);

 return move;

}

int main (void) {
   
 return 0;
}
