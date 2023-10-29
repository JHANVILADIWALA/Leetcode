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
    unordered_map<int,vector<int>>adj; //creating undirected graph using dfs
    void creategraph(TreeNode* root, int parent=-1){
        if(!root)return;
        
        if(parent!=-1){ //pushing toh adj list
            adj[parent].push_back(root->val);
            adj[root->val].push_back(parent);
        }
        //call for left and right child
        creategraph(root->left, root->val);
        creategraph(root->right,root->val);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        creategraph(root); //convert it to adjacency list
        
        queue<int>q; 
        q.push(target->val);
        unordered_map<int,bool>vis; vis[target->val]=true;
        
        vector<int>ans;
        int currlevel=0;
        while(!q.empty()){
            int n=q.size();
            
            
            while(n--){ //for this level
                auto node=q.front(); q.pop();
                if(currlevel==k){
                    ans.push_back(node);
                }
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it]=true;
                        q.push(it);
                        
                    }
                }
            }
            currlevel++;
        }
        return ans;
    }
};