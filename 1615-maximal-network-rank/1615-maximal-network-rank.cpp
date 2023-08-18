class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       int ans=0;
       map< pair<int,int>,int >edge;
        
       //making adjacency list
        vector<int>adj[101];
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);   
            adj[it[1]].push_back(it[0]);   
        }
        //marking edge present as 1 in map
        for(auto it:roads){
            edge[{it[0],it[1]}]=1;
            edge[{it[1],it[0]}]=1;
        }
        
        //check for all possible pairs
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                //total neighbours
                int neighb = adj[i].size() + adj[j].size();
                
                //if they both are connected then common edge was counted twice
                if(edge[{i,j}]|| edge[{j,i}]) neighb--;
                ans=max(ans,neighb);
            }
        }
        return ans;
    }
};