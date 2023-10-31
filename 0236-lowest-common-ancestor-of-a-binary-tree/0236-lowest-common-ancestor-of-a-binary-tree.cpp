/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL)return root;
        if(root==p || root==q)return root;
        
        TreeNode* leftnode= lowestCommonAncestor(root->left, p, q);
        TreeNode* rightnode= lowestCommonAncestor(root->right, p, q);
        
        if(leftnode==NULL)return rightnode;
        if(rightnode==NULL)return leftnode;
        
        //means both not null -> means current node is lca so return that
        return root;
    }
};