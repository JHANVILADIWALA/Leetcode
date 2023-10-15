class Solution {
public:
    int mod = 1e9+7;
    int fn(int steps, int currind, int n, int startpos, vector<unordered_map<int,int>>&dp){
        if(steps==0){
            if(currind==n)return 1;
            else return 0;
        }
        if(dp[steps].find(currind)!=dp[steps].end())return dp[steps][currind];
        
        long long left=0, right=0;
        //left
        if(currind>=INT_MIN+1){
            left=fn(steps-1, currind-1, n, startpos, dp)%mod;
        }
        //right
        if(currind<=INT_MAX-1){
            right=fn(steps-1, currind+1, n, startpos, dp)%mod;
        }
       
        return dp[steps][currind]=(left%mod+right%mod)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
       vector<unordered_map<int,int>>dp(k+1);
        
        return fn(k, startPos, endPos, startPos, dp);
    }
};