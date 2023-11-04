class Solution {
    int fn(int ind, vector<int>&arr, int d, vector<int>&dp){
        int tot=1;
        int flg1=1, flg2=1;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=1; i<=d; i++){
            //move right
            if(ind+i<arr.size()){
                if(arr[ind]<=arr[ind+i])flg1=0;
                if(flg1==1) tot=max(tot,1+fn(ind+i, arr, d, dp));
            }
            //move left
            if(ind-i>=0 ){
                if(arr[ind]<=arr[ind-i])flg2=0;
                if(flg2==1)  tot=max(tot,1+fn(ind-i, arr, d, dp));
            }
        }
        return dp[ind]=tot;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<int> dp(arr.size()+1,-1);
        int ans=0;
        for(int i=0; i<arr.size(); i++){
            ans=max(ans, fn( i, arr, d ,dp ));
        }
        return ans;
    }
};