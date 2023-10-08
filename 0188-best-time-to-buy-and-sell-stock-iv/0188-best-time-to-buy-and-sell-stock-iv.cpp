class Solution {
public:
    int fn(vector<int>& prices, int i, int k, bool buy, vector<vector<vector<int>>>&dp, int limit){
        if(i>=prices.size())return 0;
        if(k>=limit)return 0;
        
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        
        //if i can buy then check whether its optimal to buy it or not
        //buying-> money spent-> price decrease
        if(buy){
            return dp[i][buy][k]=max(-prices[i]+fn(prices,i+1,k,!buy,dp,limit),  fn(prices,i+1,k,buy,dp,limit));
        }
        else{
            //sell it -> prices add(profit)..money gained
        return dp[i][buy][k]=max(prices[i]+fn(prices, i+1, k+1, !buy, dp, limit),  fn(prices, i+1, k, buy, dp, limit));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        //3 states: i,k,buy/sell
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2, vector<int>(k,-1)));
        // int k=2;
        int limit=k;
        return fn(prices,0,0,1,dp,limit);
    }
};