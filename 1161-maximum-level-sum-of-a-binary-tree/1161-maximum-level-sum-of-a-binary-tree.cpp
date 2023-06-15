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
    int maxLevelSum(TreeNode* root) {
        int ans=0;
        int sum;
        int finsum=INT_MIN;
        int level=0;

        queue<TreeNode*>q;
        q.push(root);

        //BFS
        while(!q.empty()){
             level++;
             sum=0;
             int sz=q.size();
             for(int i=0;i<sz;i++){
                 TreeNode* currnode = q.front();
                 q.pop();
                 
                 sum+= currnode->val;
                 if(currnode->left!= nullptr) q.push(currnode->left);
                 if(currnode->right!=nullptr) q.push(currnode->right);

             }
             if(sum>finsum){
                 finsum=sum;
                 ans = level;
             }
        }
        return ans;
    }
};