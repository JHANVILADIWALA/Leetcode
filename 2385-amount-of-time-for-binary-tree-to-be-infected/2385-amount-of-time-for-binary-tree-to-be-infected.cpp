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
    int amountOfTime(TreeNode* root, int start) {
        creategraph(root); //convert it to adjacency list
        
        //bfs
        queue<int>q;                   q.push(start);
        unordered_map<int,bool>vis;    vis[start]=true;
        
        int time=0;
        while(!q.empty()){
            int n=q.size();
            //for this particular level traverse all nodes
            while(n--){
                auto node=q.front(); q.pop();
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it]=true;
                        q.push(it);
                    }
                }
            }
            time++;
        }
        return time-1;
    }
};