class Solution {
public:
    bool fn(int i, string s, map<string,int>m , vector<int>&dp){
        if(i==s.size())return true;
        bool ans=false;
        if(dp[i]!=-1)return dp[i];
        
        string temp="";
        for(int k=i; k<s.size(); k++){
            temp+=s[k];
            if(m[temp]){ //pick
                ans|= fn(k+1, s, m, dp);
            }
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& d) {
        map<string,int>m;
        for(auto it:d){
            m[it]++;
        }
        int n= s.size();
        vector<int>dp(n+1, -1);
        return fn(0, s, m, dp);
    }
};