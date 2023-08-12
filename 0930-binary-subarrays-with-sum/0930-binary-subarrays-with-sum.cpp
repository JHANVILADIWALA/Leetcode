class Solution {
public:
    int subarr(vector<int>& nums, int k){
        if(k<0)return 0;
        int left=0,right=0;
        int ans=0,sum=0;
        
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>k){
                sum-=nums[left];
                left++;
            }
            ans+=1+(right-left);
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++)nums[i]=nums[i]&1;
        return subarr(nums,k)-subarr(nums,k-1);
    }
};