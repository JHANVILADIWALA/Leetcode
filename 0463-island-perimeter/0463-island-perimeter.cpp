class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    break;
                }
            }
        }
        
        
        int ans=0;
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] ){
                    if(grid[nr][nc]==1){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                    else{
                        ans++;
                    }
                }
                else if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc])continue;
                else ans++;
            }
        }
        return ans;
    }
};