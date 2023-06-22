class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        int profit=0;
        
        int price= prices[0];
        
        for(int i=1;i<n;i++){
            profit= max( profit, prices[i]-price-fee );
            price= min(price, prices[i]-profit );
        }
        return profit;
    }
};