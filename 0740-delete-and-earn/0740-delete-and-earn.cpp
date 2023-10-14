class Solution {
public:
    int fn(int ind, vector<int>&nums, map<int,int>&m, vector<int>&dp){
        if(ind>=nums.size())return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        
        //pick................
        int pick=0, notpick=0;
        
        //next index is valid
        if(ind+1<nums.size()){
            // just greater present->jump 2 
           if(nums[ind]+1==nums[ind+1])pick+=(nums[ind]*m[nums[ind]])+fn(ind+2,nums,m,dp);
            //else move to just next
           else                        pick+=(nums[ind]*m[nums[ind]])+fn(ind+1,nums,m,dp);
        }
        //next index not valid -> no further calls
        else pick=(nums[ind]*m[nums[ind]]);
        
        //not pick............
        notpick=fn(ind+1,nums,m,dp);
        
        return dp[ind]=max(pick,notpick);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int,int>m;
        for(auto it: nums)m[it]++;
        vector<int>dp(nums.size()+1, -1);
        
        vector<int>v;
        for(auto it:m)v.push_back(it.first);
    
        return fn(0, v, m, dp);
    }
};