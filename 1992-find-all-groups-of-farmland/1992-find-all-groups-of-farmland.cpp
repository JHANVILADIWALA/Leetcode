class Solution {
public:
     void dfs( int r, int c,int&a, int&b,vector<vector<int>>& grid, vector<vector<int>>&vis ){
        vis[r][c]=1;
        // ls.push_back(node);
        
        if(r>a || c>b){
            a=r, b=c;
        }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        
        //neighbours
        for(int i=0; i<4; i++){
            int nr= r+dr[i];
            int nc= c+dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1 && !vis[nr][nc]){
                vis[nr][nc]=1;
                dfs(nr,nc,a,b,grid,vis);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<int>temp;
                    int a=i, b=j;
                    temp.push_back(i);
                    temp.push_back(j);

                    dfs(i,j,a,b,grid,vis);
                    
                    temp.push_back(a);
                    temp.push_back(b);
                    ans.push_back(temp);
                }
            }
        }
        return ans; 
    }
};