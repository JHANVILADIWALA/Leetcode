class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int subarr(vector<int>& nums, int k){
        int left=0, right=0, n=nums.size();
        
        if(k<0)return 0;
        int sum=0;
        int ans=0;
        
        while(right<n){
            sum+=nums[right];
            while(sum>k){
                sum-=nums[left];
                left++;
            }
            ans+=1+right-left;
            right++;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        
        //converting even to 0 and odd to 1
        for(int i=0; i<n; i++){
            nums[i]=nums[i]&1;
            // cout<<nums[i]<<" ";
        }
        //now we need to find the number of subarray with sum k that is k odd numbers present in subarray
        //FINDING SUBARRAYS COUNT WITH SUM K AND K-1 AND SUBTRACT 
         
        return subarr(nums,k) - subarr(nums,k-1);
    }
};