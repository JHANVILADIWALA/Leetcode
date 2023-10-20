class Solution {
public:
    int fn(int i, int m, int n, vector<int>&ones, vector<int>&zeroes, vector<vector<vector<int>>>&dp){
        
        if(i==ones.size())return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        
        int a=0, b=0;
        //can pick or not
        if(m>=zeroes[i] && n>=ones[i]){
            //means i can pick
            //so pick
            a=1+fn(i+1, m-zeroes[i], n-ones[i], ones, zeroes, dp);
            //don't pick
            b=0+fn(i+1, m, n, ones, zeroes, dp);
            return dp[i][m][n]=max(a,b);
        }
        //leave
        else return dp[i][m][n]=0+fn(i+1, m, n, ones, zeroes, dp);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<int>ones(sz);
        vector<int>zeroes(sz);
        vector<vector<vector<int>>>dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        for(int i=0; i<sz; i++){
            int ckt1=0, ckt0=0;
            for(int j=0; j<strs[i].size(); j++){
                if(strs[i][j]=='0')ckt0++;
                else if(strs[i][j]=='1')ckt1++;
            }
            ones[i]=ckt1; zeroes[i]=ckt0;
        }
        return fn(0,m,n,ones,zeroes,dp);
    }
};