class Solution {
public:
    int fn(int i, int j, vector<vector<int>>& t,vector<vector<int>>&dp){
        if(i==t.size()-1)return t[t.size()-1][j];
        if(j>t[i].size()-1)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int bottom= t[i][j]+fn(i+1, j, t, dp);
        int bottomright= t[i][j] + fn(i+1, j+1, t, dp); 
        return dp[i][j]=min(bottom, bottomright);
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n= t.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return fn(0,0,t,dp);
    }
};