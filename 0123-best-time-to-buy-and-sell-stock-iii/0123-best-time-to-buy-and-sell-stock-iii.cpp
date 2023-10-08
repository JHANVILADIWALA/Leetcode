class Solution {
public:
    int fn(vector<int>& prices, int i, int k, bool buy, vector<vector<vector<int>>>&dp){
        if(i>=prices.size())return 0;
        if(k>=2)return 0;
        
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        
        //if i can buy then check whether its optimal to buy it or not
        //buying-> money spent-> price decrease
        if(buy){
            return dp[i][buy][k]=max(-prices[i]+fn(prices,i+1,k,!buy,dp),  fn(prices,i+1,k,buy,dp));
        }
        else{
            //sell it -> prices add(profit)..money gained
        return dp[i][buy][k]=max(prices[i]+fn(prices, i+1, k+1, !buy, dp),  fn(prices, i+1, k, buy, dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        //3 states: i,k,buy/sell
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2, vector<int>(2,-1)));
        int k=2;
        return fn(prices,0,0,1,dp);
    }
};