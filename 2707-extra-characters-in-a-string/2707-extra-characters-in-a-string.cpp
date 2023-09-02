class Solution {
public:
    int fn(int i, string&s, vector<string>& d, vector<int>&dp){
        if(i==s.size())return 0;
        int ans = s.size();
        
        if(dp[i]!=-1)return dp[i];
        for(auto w: d){
            int len= w.size();
            if(i+len<= s.size() && s.substr(i,len)==w){
                ans= min(ans, fn(i+len, s, d, dp)) ;
            }
        }
        ans= min(ans,1+ fn(i+1, s, d, dp));
        return dp[i]=ans;
        
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        vector<int>dp(n+1, -1);
        return fn(0, s, dictionary, dp);
    }
};