class Solution {
public:
    int flg=1;
    long long fn(int i, string&s1, int j, string&s2, vector<vector<long long>>&dp){
        if(j==s2.size())return 1;
        if(i==s1.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        long long ways=0;
        if(s1[i]==s2[j]){
            ways+=fn(i+1, s1, j+1, s2, dp); //picking
        }
        ways+=fn(i+1, s1, j, s2, dp); //not picking
        
        if(ways>INT_MAX){
            flg=0; return 0;
        }
        return dp[i][j]=ways;
    }
    int numDistinct(string s, string t) {
        vector<vector<long long>>dp(s.size()+1, vector<long long>(t.size()+1,-1));
        int ans=fn(0, s, 0, t, dp);
        if(flg==1)return ans;
        else return -1;
    }
};