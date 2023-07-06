class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // two pointer
        int ans=INT_MAX;
        int l=0, r=0, sum=0;
        
        while(r<nums.size()){
            sum += nums[r];
            r++;
            while(sum>=target){
                ans=min(ans, r-l);
                sum-=nums[l];
                l++;
            }
        }
        
        if(ans==INT_MAX)return 0;
        else return ans;
    }
};