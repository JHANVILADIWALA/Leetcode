class Solution {
public:
    int dp[502][502];
    int solve(int i,  vector<int>&a, int x, int xdue){
        if(i==a.size())return 0; //base case
        if(dp[i][xdue]!=-1)return dp[i][xdue];
        
        int ans=INT_MAX;
        
        //adjacent flip through that range
        if(i<a.size()-1){
            ans=min(ans, (a[i+1]-a[i])+solve(i+2,a,x,xdue)); //move fwd 2 index
        }
        
        // x 
        ans=min(ans, x + solve(i+1,a,x,xdue+1));
        
        //check if any x was due then try using it here...but no cost will be there
        if(xdue>0){
            ans=min(ans, solve(i+1,a,x,xdue-1));
        }
        return dp[i][xdue]=ans;
    }
    int minOperations(string s1, string s2, int x) {
        int n=s1.size();
        vector<int>a;
        
        // putting all indexes where strings mismatch in 'a' vector
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i])a.push_back(i);
        }
        
        if((int)a.size()%2==1)return -1; //odd not possible
        if(a.size()==0)return 0; //already same
        memset(dp, -1, sizeof(dp));
        return solve(0,a,x,0);
    }
};