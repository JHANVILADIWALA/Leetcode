class Solution {
public:
    void dfs( int r, int c,vector<vector<int>>& grid, vector<vector<int>>&vis, int&ckt ){
        vis[r][c]=1;
        // ls.push_back(node);
        ckt++;
        
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        
        //neighbours
        for(int i=0; i<4; i++){
            int nr= r+dr[i];
            int nc= c+dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1 && !vis[nr][nc]){
                vis[nr][nc]=1;
                dfs(nr,nc,grid,vis,ckt);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int ckt=0;
                    dfs(i,j,grid,vis,ckt);
                    ans=max(ans,ckt);
                }
            }
        }
        return ans; 
    }
};