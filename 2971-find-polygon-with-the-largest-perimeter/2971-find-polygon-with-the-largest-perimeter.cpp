class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans=-1;
        sort(nums.begin(), nums.end());
        long long left=0, right=0;
        int n=nums.size();
        right=nums[n-1];
        
        for(int i=0; i<n-1; i++){
            left+=nums[i];
        }
        for(int i=n-2; i>=0; i--){
            if(left>right){
                ans=left+right; break;
            }
            left-=nums[i]; right=nums[i];
        }
        return ans;
    }
};