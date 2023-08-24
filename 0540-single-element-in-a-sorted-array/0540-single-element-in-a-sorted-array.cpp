class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans;
        int n=nums.size();
        if(n==1 || n==2)return nums[0];
        if(nums[0]!=nums[1])ans=nums[0];
        for(int i=1; i<n-1;i++){
            if(nums[i-1]!=nums[i] && nums[i]!=nums[i+1])ans=nums[i];
        }
        
        if(nums[n-1]!=nums[n-2])ans=nums[n-1];
        return ans;
    }
};