class Solution {
public:
    int mod=1e9+7;
    int countHomogenous(string s) {
        int n=s.size();
        int len=1;
        int ans=1;
        
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1])len++;
            else len=1;
            
            ans=(ans+len)%mod;
        }
            
        return ans;
    }
};