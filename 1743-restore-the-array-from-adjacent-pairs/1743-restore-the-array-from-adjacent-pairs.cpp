class Solution {
public:
    vector<int>ans;
    void dfs(map<int,vector<int>>&adj, int curr, int prev){
        ans.push_back(curr);
        for(auto it: adj[curr]){
            if(it!=prev){
                dfs(adj, it, curr);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjp) {
        int n=adjp.size();
        map<int,vector<int>>adj;
        
        for(auto it: adjp){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int startpoint=-1;
        for(auto it: adj){
            if(it.second.size()==1){
                startpoint=it.first;
                break;
            }
        }
        dfs(adj,startpoint, INT_MIN);
        return ans;
    }
};