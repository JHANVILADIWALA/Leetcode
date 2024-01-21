class Solution {
public:
    int fn(vector<int>nums, int i, vector<int>&dp){
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        
        return dp[i]=max(nums[i]+fn(nums, i-2, dp), fn(nums, i-1, dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return fn(nums, nums.size()-1, dp);
    }
};