class Solution {
public:
    int fn(vector<int>& jd, int n, int idx, int d, vector<vector<int>>&dp){
        //base case
        if(d==1){ //takeall jobs nd get their max
            int maxd=jd[idx];
            for(int i=idx; i<n; i++){
                maxd=max(maxd, jd[i]);
            }
            return maxd;
        }
        if(dp[idx][d]!=-1)return dp[idx][d];
        
        int maxd=jd[idx], finalresult=INT_MAX;
        
        for(int i=idx; i<=n-d; i++){
            maxd=max(maxd, jd[i]);
            int result=maxd + fn(jd, n, i+1, d-1, dp);
            
            finalresult=min(finalresult, result);
        }
        return dp[idx][d]=finalresult;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(n<d)return -1;
        vector<vector<int>>dp(n+1, vector<int>(d+1, -1));
        return fn(jd,n,0,d, dp);
    }
};