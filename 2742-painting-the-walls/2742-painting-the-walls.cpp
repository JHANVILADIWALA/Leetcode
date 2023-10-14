class Solution {
public:
    int fn(int i, int remaining, vector<int>& cost, vector<int>& time, vector<vector<int>>&dp){
        if(remaining<=0)return 0;
        
        if(dp[i][remaining]!=-1)return dp[i][remaining];
        
        if(i>=cost.size() && remaining>0)return 1e9;
        //pick
        int pickit=cost[i]+fn(i+1, remaining-time[i]-1, cost, time, dp);
        //int notpick
        int leaveit=0+fn(i+1, remaining, cost, time, dp);
        
        return dp[i][remaining]=min(pickit, leaveit);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return fn(0, cost.size(), cost, time, dp);
    }
};