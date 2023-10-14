class Solution {
public:
    int solve(int ind,vector<int>&nums,bool f,vector<vector<int>>&dp){
        if(ind==0) return 1;
        if(dp[ind][f]!=-1) return dp[ind][f];
        long long int take=0;
        long long int notTake = solve(ind-1,nums,f,dp);
        if((f==1 && (nums[ind]-nums[ind-1])<0) || (f==0 && (nums[ind]-nums[ind-1])>0)){
            take = 1+solve(ind-1,nums,!f,dp);
            
        } 
        
        return dp[ind][f]=max(take,notTake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return 1;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return max(solve(n-1,nums,0,dp),solve(n-1,nums,1,dp));
        
    }
};