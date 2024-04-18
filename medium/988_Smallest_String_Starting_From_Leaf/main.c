#include <stdio.h>

void DFS (struct TreeNode* node, char *nowStr, char* smStr) {
 if (!node) return;

 int len = strlen(nowStr); // The nowStr is a reversed string.
 char s[len+2];
 strcpy(s, nowStr);
 s[len] = (char) (node->val + 'a');

 int i, j;
 int tmp;
 for (i = 0, j = len; i < j; i++, j--) {
  tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
 }

 s[len+1] = '\0';

 // Is a leaf?
 int wS, wSm;
 if (!node->left && !node->right) {
  if (smStr == "") {
   strcpy(smStr, s);
   smStr[strlen(s)] = '\0'
  } else {
   wS = 0;
   wSm = 0;

   for (int x = 0; x < strlen(s); x++) wS = wS*2 + s[x];
   for (int y = 0; y < strlen(smStr); y++) wSm = wSm*2 + s[y];

   if (wS < wSm) {
    strcpy(smStr, s);
    smStr[strlen(s)] = '\0'
   }
  }

 }

 for (i = 0, j = len; i < j; i++, j--) {
  tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
 }

 DFS (node->left, s, smStr);
 DFS (node->right, s, smStr);

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char* smallestFromLeaf(struct TreeNode* root) {
 char *ret = (char*) malloc(8501 * sizeof(char));
 ret[0] = '\0';
    
 DFS (root, "", ret);

 return ret;
}

int main (void) {

 return 0;
}
