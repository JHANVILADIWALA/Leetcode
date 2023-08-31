class Solution {
public:
    int fn(int row, int col, vector<vector<int>>&dp){
        if(row==0 && col==0)return 1;
        if(row<0 || col<0)return 0;
        
        if(dp[row][col]!=-1)return dp[row][col];
        int up=fn(row-1, col, dp);
        int left=fn(row, col-1, dp);
        return dp[row][col]= up+left;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return fn(n-1, m-1, dp);
    }
};