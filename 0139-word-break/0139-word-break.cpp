class Solution {
public:
    bool rec(int ind, string&s, unordered_map<string,int>&m, vector<int>&dp){
        //base case
        if(ind==s.size())return true;
        
        if(dp[ind]!=-1){//means already calculated
           if(dp[ind]==1)return true;
            else return false;
        }
        
        string temp;
        bool ans=false;
        
        for(int i=ind; i<s.size(); i++){
            temp+=s[i];
            
            if(m.find(temp)!=m.end()){ //means present in the map
                ans = rec(i+1,s,m,dp);
                //after recursion calls completed
                if(ans==true){
                    dp[ind]=true; 
                    return true;
                }
            }
        }
        if(ans==false)dp[ind]=0;
        else dp[ind]=1;
        
        return ans;
    }
        
    bool wordBreak(string s, vector<string>& w) {
        
        //dp vector
        vector<int>dp(s.size(),-1);
        //storing words given in map
        unordered_map<string,int>m;
        
        for(int i=0; i<w.size(); i++){
            m[w[i]]=0; //marking all given words as 0 in map
        }
        
        //recursive fn
        bool ans=rec(0,s,m,dp);
        return ans;
    }
};