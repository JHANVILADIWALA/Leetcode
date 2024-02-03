class Solution {
public:
    vector<int>dp;
    int fn(vector<int>& arr, int k, int ind){
        int n=arr.size();
        
        if(ind==arr.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        
        int maxi=0, ans=0;
        
        for(int i=ind; i<min(n, ind+k); i++){
            maxi=max(maxi, arr[i]);
            int val=(i-ind+1)*maxi + fn(arr, k, i+1);
            
            ans=max(ans,val);
        }
        return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(), -1);
        return fn(arr, k, 0);
    }
};