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
        //the moment we cannot say that both of them lie either on left or right
        //i got my lca
        if(root==NULL)return NULL;
        int curr=root->val;
        
        if(curr>p->val && curr>q->val){
            //move left both roots small
            return lowestCommonAncestor(root->left, p, q);
        }
        if(curr<p->val && curr<q->val){
            //both large
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
    }
};