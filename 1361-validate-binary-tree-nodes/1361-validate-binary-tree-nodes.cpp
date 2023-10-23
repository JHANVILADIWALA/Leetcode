class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int>m; //child to parent
        vector<vector<int>>adj(n);   // graph
        
        //every child should have only one parent
        for(int i=0; i<n; i++){
            int node=i, leftc=leftChild[i], rightc=rightChild[i];
            
            if(m.find(leftc)!=m.end() || m.find(rightc)!=m.end())return false;
            
            if(leftc!=-1){
                m[leftc]=i;
                adj[i].push_back(leftc);
            }
            if(rightc!=-1){
                m[rightc]=i;
                adj[i].push_back(rightc);
            }
        }
        
        //finding root
        int root=-1;
        for(int i=0; i<n; i++){
            if(m.find(i)==m.end()){
                if(root==-1)root=i;
                else return false;//root was already assigned
            }
        }
        if(root==-1)return false;
        
        //check that u can visit all the nodes from root
        //dfs/bfs
        
        int ckt=0;
        queue<int>q;
        vector<bool>vis(n,false);
        
        q.push(root); vis[root]=true; ckt++;
        
        while(!q.empty()){
            int node=q.front(); q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=true;
                    ckt++;
                    q.push(it);
                }
            }
        }
        if(ckt==n)return true;
        return false;
    }
};