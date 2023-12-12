class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    //using dijkstra
    int minimumEffortPath(vector<vector<int>>& v) {
        
        priority_queue<p,vector<p>,greater<p>>pq; // {diff,{row,col}}
        pq.push({0,{0,0}});
        int n=v.size(), m=v[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0; //source to source dist 0
        
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        int ans=-1;
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            
            int diff=it.first, row=it.second.first, col=it.second.second;
            if(row==n-1 && col==m-1){
                ans=diff; break;
            }
            
            //neighbours
            for(int i=0; i<4; i++){
                int nrow=row+dr[i], ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    int neweffort=max(abs(v[row][col]-v[nrow][ncol]), diff);
                    if(neweffort<dist[nrow][ncol]){
                        dist[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }
                }
            }
        }
        return ans;
    }
};