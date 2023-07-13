class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<int>adj[n]; //adjacency matrix
        //creating graph
        for(auto it:v ){
            adj[it[1]].push_back(it[0]); // directed edge
        }
        
        //check for toposort
        //that is whether cycle present or not
        //if present -> no not possible
        // not present ->possible
        
        // BFS topological sort
        int indegree[2000] = {0};
        for( int i=0; i<n; i++){ //traversing all nodes
            for(auto it: adj[i]){ //neighbours
                indegree[it]++; //increase indegree of neighbours
            }
        }
        //getting all nodes with indegree 0 in queue because they start the queue
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)q.push(i); //bz 0 based nodes numbered
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node); //if node is in q then push in topo vector
            
            for(auto it : adj[node]){ //neighbours
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(topo.size()==n)return topo;
        return {};
    }
};