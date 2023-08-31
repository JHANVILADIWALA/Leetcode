class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        //O(N^2) TC
        //O(N) SC
        vector<int>dp(n+1, n+2);
        dp[0]=0;
        
        for(int i=0; i<ranges.size(); i++){
            for(int j=max(0,i-ranges[i]); j<=min(n, i+ranges[i]); j++){
                int old=dp[j];
                int partbefore= max(0, i-ranges[i]);
                int curr= dp[partbefore]+1;
                dp[j]=min(old , curr);
            }
        }
        if(dp[n]>=n+2)return -1;
        else return dp[n];
    }
};