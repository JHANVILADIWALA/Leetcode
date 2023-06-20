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
    
    int sum=0;
    
    int height(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        
        int lh= height(root->left);
        int rh= height(root->right);
        
        return 1+max(lh,rh);
    }
    void calc( TreeNode* root, int maxht, int currht){
        if(root==NULL) return;
        currht++;
        
        if(currht==maxht)sum+=root->val;
        
        calc(root->left, maxht,currht);
        calc(root->right, maxht,currht);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        int ht = height(root);
        calc(root, ht, 0);
        return sum;
    }
};