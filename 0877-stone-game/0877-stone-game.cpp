class Solution {
public:
    int fn(int l, int r, vector<int>& piles, vector<vector<int>>&dp){
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        
        int x= piles[l] + max( fn(l+2,r,piles,dp), fn(l+1, r-1, piles, dp));
        int y= piles[r] + max( fn(l,r-2,piles,dp), fn(l+1, r-1, piles, dp));
        return dp[l][r]=max(x,y);
    }
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        for(auto it:piles){
            sum+=it;
        }
        int n=piles.size();
        vector<vector<int>>dp(piles.size()+1, vector<int>(piles.size()+1,-1));
        int alice=fn(0, n-1, piles, dp);
        int lee=sum-alice;
        return alice>lee;
    }
};