class Solution {
private:
    void dfs(vector<int> adj[], vector<bool> &vis, vector<int> &ans, int s){
	    // base case
	    if(vis[s])  return;
	    // calling recursion
	    vis[s]=true;
	    for(int u: adj[s]){
	        if(!vis[u])
	            dfs(adj,vis,ans,u);
	    }
	    ans.push_back(s);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // using DFS
	    vector<int> ans;
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	            dfs(adj,vis,ans,i);
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
    
    int find(vector<int> adj[], vector<bool>& vis, vector<int>& ret, int n, int s) {
        int re = 0;
        for(int u: adj[s]) {
            if(!vis[u]) {
                vis[u] = true;
                re += 1 + find(adj, vis, ret, n, u);
            }
        }
        return re;
    }
    
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++) {
            adj[i].push_back(edges[i]);
        }
        vector<int> topo = topoSort(n, adj);
        reverse(topo.begin(), topo.end());
        vector<bool> vis(n, false);
        vector<int> ret(n, -1);
        for(int i: topo) {
            if(!vis[i]) {
                if(vis[edges[i]]) {
                    ret[i] = 1 + ret[edges[i]];
                    vis[i] = true;
                }
                else {
                    int r = find(adj, vis, ret, n, i);
                    for(int i = 0; i < n; i++) {
                        if(ret[i] == -1 and vis[i])
                            ret[i] = r;
                    }
                }
            }
        }
        return ret;
    }
};