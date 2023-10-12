
class Solution {
    #define pb push_back
public:
int mod=1e9+7;
    int fn(int ckt, char prev, int n, vector<map<char,int>>&dp){
        if(ckt==n)return 1;
        
        if(dp[ckt].find(prev)!=dp[ckt].end())return dp[ckt][prev];
        
        int ways=0;
        if(prev=='#'){
            ways=((fn(ckt+1,'a',n,dp)+fn(ckt+1,'e',n,dp))%mod+((fn(ckt+1,'i',n,dp)+fn(ckt+1,'o',n,dp))%mod+fn(ckt+1,'u',n,dp))%mod)%mod;
        }
        else if(prev=='a'){
            ways=fn(ckt+1,'e',n, dp)%mod;
        }
        else if(prev=='e'){
            ways=(fn(ckt+1, 'a', n, dp)%mod+fn(ckt+1, 'i', n, dp)%mod)%mod;
        }
        else if(prev=='i'){
            ways=((fn(ckt+1,'a',n,dp)+fn(ckt+1,'e',n,dp))%mod+(fn(ckt+1,'o',n,dp)+fn(ckt+1,'u',n,dp))%mod)%mod;
        }
        else if(prev=='o'){
            ways=(fn(ckt+1, 'i', n, dp)%mod+fn(ckt+1, 'u', n, dp)%mod)%mod;
        }
        else{
            ways=fn(ckt+1, 'a', n, dp);
        }
        return dp[ckt][prev]=ways%mod;
    }
    int countVowelPermutation(int n) {
        vector<map<char,int>>dp(n+1);
        return fn(0,'#',n, dp);
    }
};