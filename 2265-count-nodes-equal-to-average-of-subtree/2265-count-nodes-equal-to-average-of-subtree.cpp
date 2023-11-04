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
    // {sum ,  ckt}
    pair<int,int> fn(TreeNode* root, int &ckt){
        if(!root)return {0,0};
        
        pair<int,int>l,r;
        l=fn(root->left,  ckt);
        r=fn(root->right, ckt);
        
        int newckt=l.second+r.second+1;
        int newsum=l.first+r.first+root->val;
        int avg=newsum/newckt;
        if(avg==root->val)ckt++;
        
        return {newsum, newckt};
    }
    int averageOfSubtree(TreeNode* root) {
        int ckt=0;
        fn(root, ckt);
        return ckt;
    }
};