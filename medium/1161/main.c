/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
  int front = 0, rear = -1;
  int level = 0;
  int currentlevel = 0;
  int maxSum = INT_MIN;
  struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode*)*10000);

  queue[++rear] = (struct TreeNode* )root;
  level = currentlevel;

  while (front <= rear) {
    int currentSum = 0;
    int size = rear - front + 1;
    for (int i = 0; i < size; front++, i++) {
      currentSum += queue[front]->val;
      if (queue[front]->left) {
        queue[++rear] = queue[front]->left;
      }
      if (queue[front]->right) {
        queue[++rear] = queue[front]->right;
      }

    }
    currentlevel++;
    if (maxSum < currentSum) {
      maxSum = currentSum;
      level = currentlevel;
    }
  }
  free(queue);
    
  return level;
}
