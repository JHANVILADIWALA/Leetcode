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
public:
    void inorder(TreeNode* node, vector<int>&v){
        if(!node)return;
        inorder(node->left,v);
        v.push_back(node->val );
        inorder(node->right,v);
        
    }
    int getMinimumDifference(TreeNode* root) {
      vector<int>v;
      inorder(root,v);
        int mini=INT_MAX;
      for(int i=0;i<v.size()-1;i++){
          mini=min(abs(v[i]-v[i+1]), mini);
      }
        return mini;
    }
};