class Solution {
public:
   int fn(vector<int>& prices, int i, bool buy, vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        
        if(buy){
           return dp[i][buy]=max(-prices[i]+fn(prices, i+1, !buy, dp), fn(prices, i+1, buy, dp));    
        }
        else{//cooldown=>i+2
            return dp[i][buy]=max(prices[i]+fn(prices, i+2, !buy, dp), fn(prices, i+1, buy, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // if(n<2)return 0;
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        return fn(prices, 0, 1, dp);
    }
};