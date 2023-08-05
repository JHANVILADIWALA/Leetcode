class Solution {
public:
    void dfs( int r, int c, int oldclr, int newclr, vector<vector<int>>&vis, vector<vector<int>>& grid, vector<vector<int>>& ans){
        vis[r][c]=1;
        ans[r][c]=newclr;
        
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        
        for(int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==oldclr && !vis[nr][nc]){
                dfs(nr,nc,oldclr,newclr,vis,grid,ans);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nclr) {
        int iniclr= image[sr][sc];
        vector<vector<int>>ans=image;
        
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(sr,sc,iniclr,nclr,vis,image,ans);
        
        return ans;
    }
};