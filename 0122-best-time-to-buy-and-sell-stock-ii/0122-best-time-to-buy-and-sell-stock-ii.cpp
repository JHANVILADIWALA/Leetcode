class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans=0;
         int curr=prices[0];
         int diff=0;
         for(int i=1; i<n; i++){
             if(prices[i]>=curr){
                 diff+=prices[i]-curr;
                 curr=prices[i];
             }
             else{
                 ans+=diff;
                 diff=0;
                 curr=prices[i];
             }
         }
         ans+=diff;
         return ans;
         
    }
};