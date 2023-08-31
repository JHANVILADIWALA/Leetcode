class Solution {
public:
    int fn(int row, int col, vector<vector<int>>&dp, vector<vector<int>>& grid){
        if(row<0 || col<0)return 0;
        if(grid[row][col]==1)return 0;
        if(row==0 && col==0)return 1;
        
        if(dp[row][col]!=-1)return dp[row][col];
        int up=fn(row-1, col, dp, grid);
        int left=fn(row, col-1, dp, grid);
        return dp[row][col]= up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return fn(n-1, m-1, dp, grid);
    }
};