class Solution {
public:
    int fn(vector<int>nums, int i, vector<int>&dp){
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int rob= nums[i] + fn(nums, i-2, dp);
        int dont= fn(nums,i-1,dp);
        return dp[i]=max(rob, dont);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        
        //cant rob first and last house together
        //creating two vectors .... temp1 contains all except last...temp2 contains all except first
        //best of two will be answer
        vector<int>temp1,temp2;
        for(int i=0; i<nums.size(); i++){
            if(i!=nums.size()-1)temp1.push_back(nums[i]);
            if(i!=0)temp2.push_back(nums[i]);
        }
         vector<int>dp(temp1.size(), -1);
         int a=fn(temp1, temp1.size()-1, dp);
         
         vector<int>dpp(temp2.size(), -1);
         int b=fn(temp2, temp2.size()-1, dpp);
        return max(a,b);
    }
};