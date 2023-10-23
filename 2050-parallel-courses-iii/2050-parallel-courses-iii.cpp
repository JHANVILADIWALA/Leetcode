class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>indegree(n,0);
        //making graph, indegree
        unordered_map<int,vector<int>>adj;
        // vector<vector<int>>adj(n);
        for(int i=0; i<relations.size(); i++){
            int u=relations[i][0]-1, v=relations[i][1]-1;//zero indexing
            
            adj[u].push_back(v);  indegree[v]++;
        }
        
        //pushing node with indeg=0 in queue
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>maxtime=time;
        
        while(!q.empty()){
            int node=q.front(); q.pop();
            
            for(auto it: adj[node]){
                maxtime[it]=max(maxtime[it], maxtime[node]+time[it]);
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return *max_element(maxtime.begin(), maxtime.end());
    }
};