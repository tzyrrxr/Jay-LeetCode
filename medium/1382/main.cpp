/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void CreateInorderList (TreeNode *root, vector<int>& inorderList) {
      if (!root) return;
      CreateInorderList(root->left, inorderList);
      inorderList.push_back(root->val);
      CreateInorderList(root->right, inorderList);
    }

    TreeNode* CreateBalanceTree (const vector<int> &inorderList, int s, int e) {
      if (!(s<=e)) return NULL;
      int mid = (s+e) >> 1;
      return new TreeNode(inorderList[mid], CreateBalanceTree(inorderList, s, mid-1), CreateBalanceTree(inorderList, mid+1, e));
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
      vector<int> inorderList;
      CreateInorderList(root, inorderList);

      int n = inorderList.size();
        
      return CreateBalanceTree(inorderList, 0, n-1);
    }
};
