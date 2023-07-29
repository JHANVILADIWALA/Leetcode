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
    // left subtree is p right is q
    //toh p ka left and q ka right
    //and qka left and p ka right
    //recursively
    bool func( TreeNode*p , TreeNode*q ){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL ) return false;
        if( p->val != q->val ) return false;
        return func( p->left,q->right ) && func( p->right , q->left);

    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return func( root->left , root->right); //check if left and right subtree of root are mirror image of each other 
    }
};