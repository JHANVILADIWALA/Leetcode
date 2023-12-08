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
    string ans="";
    void preorder(TreeNode* root){
        // if(!root)return;
        string ss= to_string(root->val);
        ans+=ss;
        
        if(root->left){ //left side check
            ans.push_back('(');
            preorder(root->left);
            ans.push_back(')');
        }
        
        if(root->right){
            if(!root->left)ans += "()"; //left side not present, but right side present
            ans.push_back('(');
            preorder(root->right);
            ans.push_back(')');
        }
        
    }
    string tree2str(TreeNode* root) {
        preorder(root);
           return ans;
    }
};