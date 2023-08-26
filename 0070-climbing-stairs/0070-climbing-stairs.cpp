class Solution {
public:
    int fn(int i, vector<int>&dp){
        if(i==0 || i==1)return 1;
        if(dp[i]!=-1)return dp[i];
        int a=fn(i-1, dp);
        int b=fn(i-2, dp);
        return dp[i]=a+b;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        // memset(dp,-1, sizeof(dp));
        return fn(n,dp);
    }
};