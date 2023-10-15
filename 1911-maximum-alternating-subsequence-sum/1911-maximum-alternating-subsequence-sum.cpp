class Solution {
public:
    //maximise even, minimise odd
    long long fn(int i, bool turnofodd, vector<int>& nums, vector<vector<long long>>&dp){
        if(i>=nums.size())return 0;
        if(dp[i][turnofodd]!=-1)return dp[i][turnofodd];
        
        long long oddsum=0, evensum=0;
        
        if(turnofodd){
            long long a=-nums[i]+fn(i+1, !turnofodd, nums, dp); //pick
            long long b=fn(i+1, turnofodd, nums, dp); //notpick
            oddsum=max(a,b);
            return dp[i][turnofodd]=oddsum;
        }
        else {
            long long a=nums[i]+fn(i+1, !turnofodd, nums, dp); //pick
            long long b=fn(i+1, turnofodd, nums, dp); //notpick
            evensum=max(a,b);
            return dp[i][turnofodd]=evensum;
        }
        
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>dp(nums.size()+1, vector<long long>(2,-1));
        return fn(0,0,nums,dp);
    }
};