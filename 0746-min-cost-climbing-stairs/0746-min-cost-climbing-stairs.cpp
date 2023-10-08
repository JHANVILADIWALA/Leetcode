class Solution {
public:
    int fn(int i, vector<int>&cost, vector<int>&dp){
        if(i==0 || i==1)return 0;
        if(dp[i]!=-1)return dp[i];
        
        return dp[i]=min(cost[i-1]+fn(i-1,cost,dp),  cost[i-2]+fn(i-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return fn(n,cost,dp);
    }
};