class Solution {
public:
    int fn(int i, vector<int>&dp, vector<int>& cost){
        if(i==0 || i==1)return 0;
        if(dp[i]!=-1)return dp[i];
        int a=cost[i-1]+fn(i-1, dp, cost);
        int b=cost[i-2]+fn(i-2, dp, cost);
        return dp[i]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1, -1);
        return fn(n,dp, cost);
    }
};