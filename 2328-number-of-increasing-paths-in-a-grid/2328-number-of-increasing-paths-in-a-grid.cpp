class Solution {
public:
    long long mod= 1e9 + 7 ;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    
    bool isvalid(int x, int y, vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size())return false;
        return true;
    }
    
    int dfs(int x,int y,vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(dp[x][y]!=-1){ //means already stored
            return dp[x][y];
        }
        int ans=1;
        for(int i=0;i<4;i++){
            int nx= x + dx[i];
            int ny= y + dy[i];
            if(isvalid(nx,ny,grid) && grid[x][y]>grid[nx][ny]){
                ans = (ans%mod + dfs(nx,ny,grid,dp)%mod);
            }
        }
        return dp[x][y]=ans%mod;
    }
    
    
    int countPaths(vector<vector<int>>& grid) {
        //using graph
        //optimise using dp
        
        // m*n grid containing -1
        vector<vector<int>>dp( grid.size(), vector<int>(grid[0].size(),-1) );
        
        long long count =0 ;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                // count += dfs
                count = (count%mod + dfs( i,j,grid,dp )%mod)%mod;    
            }
        }
        return (int)count%mod ;
    }
};