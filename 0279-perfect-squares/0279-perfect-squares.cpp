class Solution {
public:
    int fn(int n, vector<int>&v,vector<int>&dp){
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        int ans=INT_MAX;
        for(int i=0; i<v.size(); i++){
            if(v[i]<=n){
                int a=1+fn(n-v[i],v,dp);
                ans=min(ans,a);
            }
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
       vector<int>v;
       vector<int>dp(n+1,-1);
       int var=1; int ckt=1;
       while(var<=n){
           var=ckt*ckt;
           v.push_back(var);
           ckt++;
       }
       return fn(n,v,dp);
    }
};