class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n = a.size();
        int ans=0;
        if(n<=2) return n;
        unordered_map <int,int> dp[n+1];
        
        //bottom up approach
        for(int i=1;i<n;i++){
            for(int j=0; j<i; j++){
                int diff = a[i] - a[j] ;
                int ckt=1;
                
                if(dp[j].count(diff))ckt=dp[j][diff];
                
                dp[i][diff]= 1+ckt;
                ans= max(ans, dp[i][diff]);
                
            }
        }
        return ans;
    }
};