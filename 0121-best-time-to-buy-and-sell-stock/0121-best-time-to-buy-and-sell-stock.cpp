class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
         int suff[n];
         int maxi=INT_MIN;
         
        int ans=0;
         for(int i=n-1; i>=0; i--){
             maxi = max(maxi, prices[i]);
             suff[i]=maxi;
             ans = max(suff[i]-prices[i], ans);
         }
        return ans;
        
    }
};