class Solution {
public:
int m=1000000007;
    int fn(int n, int cell,vector<vector<int>>&adj,vector<vector<int>>&dp){
        if(n==0)return 1;
        if(dp[n][cell]!=-1)return dp[n][cell];
        int ans=0;
        for(auto it: adj[cell]){
            ans=(ans+fn(n-1,it,adj,dp))%m;
        }
        return dp[n][cell]=ans;
    }
    int knightDialer(int n) {
        vector<vector<int>>adj={
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {3,9,0},
        {},
        {1,7,0},
        {2,6},
        {1,3},
        {2,4}};
        vector<vector<int>>dp(5001, vector<int>(11,-1)); 
        int result=0;
        for(int cell=0; cell<=9; cell++){
            result=(result+fn(n-1,cell,adj,dp))%m;
        }
        return result;
    }
};