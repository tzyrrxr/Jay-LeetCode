#include <stdio.h>

void DFS (struct TreeNode* node, char *nowStr, char* smStr) {
 if (!node) return;


 int len = strlen(nowStr); // The nowStr is a reversed string.
                           
 //char *s = (char *) calloc(len+2, sizeof(char));
 char s[200] = {0};

 strncpy(s, nowStr, len);
 s[len] = (char) (node->val + 'a');

 int i, j;
 int tmp;
 for (i = 0, j = len; i < j; i++, j--) {
  tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
 }

 //s[len+1] = '\0';

 // Is a leaf?
 int wS, wSm;
 if (!node->left && !node->right) {
  len = strlen(s);
  if (*smStr == '\0') {
   strncpy(smStr, s, len);
   smStr[len] = '\0';
  } else {
   wS = 0;
   wSm = 0;

   bool compare = false;

   for (int i = 0; s[i] && smStr[i]; i++) {
    if (s[i] == smStr[i]) {
     continue;
    } else if (s[i] < smStr[i]) {
     compare = true;
     break;
    } else {
     compare = false;
     break;
    }
   }

   tmp = strlen(s) < strlen(smStr) ? strlen(s) : strlen(smStr);
   for (int x = 0; x < tmp && compare; x++) wS = wS*26 + s[x];
   for (int y = 0; y < tmp && compare; y++) wSm = wSm*26 + smStr[y];

   if (wS <= wSm && compare) {
    strncpy(smStr, s, len);
    smStr[len] = '\0';
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

 //free(s);

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
 char *ret = (char*) calloc(8501, sizeof(char));
    
 DFS (root, "", ret);

 return ret;
}

int main (void) {

 return 0;
}
