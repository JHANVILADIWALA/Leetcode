class Solution {
public:
    int mod = 1e9+7;
    int fn(int steps, int currind, int n, vector<vector<int>>&dp){
        if(steps==0){
            if(currind==0)return 1;
            else return 0;
        }
        if(dp[currind][steps]!=-1)return dp[currind][steps];
        
        int left=0, right=0, stay=0;
        //left
        if(currind>0){
            left=fn(steps-1, currind-1, n, dp)%mod;
        }
        //right
        if(currind<n){
            right=fn(steps-1, currind+1, n, dp)%mod;
        }
        //stay
        stay=fn(steps-1, currind, n, dp)%mod;
        
        return dp[currind][steps]=((left%mod+right%mod)%mod+stay%mod)%mod;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>>dp(501, vector<int>(501, -1));
        return fn(steps, 0, arrLen-1, dp);
    }
};