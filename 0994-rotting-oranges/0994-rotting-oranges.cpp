class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<vector<int>>v=grid;
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        
        //put all the rotten oranges in queue with time 0
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(grid[i][j]==2)q.push({{i,j},0});
            }
        }
        
        int tm=0;
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            
            tm=max(tm,t);
            
            //neighbours
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int nr= r+drow[i];
                int nc= c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && v[nr][nc]==1 ){
                    v[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        
        //check if all are rotten now
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                if(grid[i][j]==1 && v[i][j]!=2)tm=-1;
            }
        }
        return tm;
    }
};