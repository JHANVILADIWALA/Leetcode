class Solution {
public:
    int fn(int row, int col, int c, int ckt, vector<vector<int>>& grid){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size())return 0;
        if(grid[row][col]==-1 || grid[row][col]==3)return 0;
        if(grid[row][col]==2 ){
            if(c-1==ckt)return 1; //all cells covered
            else return 0;
        }
        
        // if(dp[row][col]!=-1)return dp[row][col];
        grid[row][col]=3;
        int up=fn(row-1, col, c+1, ckt, grid);
        int left=fn(row, col-1 ,c+1, ckt, grid);
        int down=fn(row+1, col,c+1, ckt, grid);
        int right=fn(row, col+1,c+1, ckt, grid);
        grid[row][col]=0;
        return up+left+down+right;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        int start=0, end=0;
        int ckt=0; //walkable cells
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    start=i, end=j;
                }
                if(grid[i][j]==0)ckt++;
            }
        }
        return fn(start, end, 0, ckt, grid);
    }
};