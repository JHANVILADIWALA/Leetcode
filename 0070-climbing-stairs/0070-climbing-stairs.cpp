class Solution {
public:
    int fn(int i, vector<int>&dp){
        if(i==1 || i==0)return 1;
        
        if(dp[i]!=-1)return dp[i];
        return dp[i]=fn(i-2,dp)+fn(i-1,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};